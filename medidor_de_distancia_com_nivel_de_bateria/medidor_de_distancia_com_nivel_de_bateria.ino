//Projeto feito para detectar se as pessoas estao muito proximas umas das outras nesse momento de pandemia do COVID-19
//Feito por: André Oliveira Cunha
//3° Periodo de Engenharia de Computacao - UFES


#include "ESP8266WiFi.h"
#define apito D1

#define led1 D2
#define led2 D3
#define led3 D4
#define led4 D5
#define led5 D6
#define led6 D7
#define botao D8
#define voltimetro A0


int estado = 0;
float seno;
int frequencia;
float leituraTensao = 0;
int leituraBotao = 0;


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

//inicializa o esp8266 como access point
  boolean result = WiFi.softAP("COVID19", "12345678");
  if(result == true){
    Serial.println("Tudo pronto!");
  }
  else{
    Serial.println("Falhou!");
  }

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(apito,OUTPUT);
  pinMode(botao, INPUT);
  pinMode(voltimetro, INPUT);

  digitalWrite(led6, LOW);
  apagaLeds();

  delay(2000);
}

void loop() {
  estado = 0;
  leituraTensao = converteEmTensao(analogRead(voltimetro));
  leituraBotao = digitalRead(botao);
  
  Serial.println(leituraTensao);
  if(leituraBotao == HIGH){
    bateria(leituraTensao);
  }

  // WiFi.scanNetworks retorna o numero de redes wifi encontradas
  int n = WiFi.scanNetworks();
  
  if (n == 0) {
    Serial.println("Nenhum wifi encontrado");
  } else {
    Serial.print(n);
    Serial.println(" redes encontradas");
    for (int i = 0; i < n; ++i) {
      //verifica se a rede tem o nome "COVID19"
      if(WiFi.SSID(i) == "COVID19"){
        Serial.print(i + 1);
        Serial.print(") ");
        Serial.print(WiFi.SSID(i));// SSID
        Serial.print(WiFi.RSSI(i));//Potencia do sinal em dBm  
        Serial.println("dBm");

        if(WiFi.RSSI(i) >= -20){
          estado = 1;
        }
      }
    }
    Serial.println("");
  }
  alertaDeProximidade(estado);
}

void alertaDeProximidade(int estado){
  if(estado == 1){
      digitalWrite(led6, HIGH);

      //repeticao para gerar o apito no buzzer
      for(int x=0;x<180;x++){
        //converte graus para radiando e depois obtém o valor do seno
        seno=(sin(x*3.1416/180));
        //gera uma frequência a partir do valor do seno
        frequencia = 2000+(int(seno*1000));
        tone(apito,frequencia);
        delay(2);
      }
      delay(50);
    }
    else{
      digitalWrite(led6, LOW);
      digitalWrite(apito, LOW);
    }
}


float converteEmTensao(int leituraAnalogica){
  float leitura = leituraAnalogica;
  return (leitura*9)/1023;
}

void bateria(float leituraTensao){
  if(leituraTensao > 2.0){
    digitalWrite(led5, HIGH);
    delay(150);
  }
  if(leituraTensao > 5.5){
    digitalWrite(led4, HIGH);
    delay(150);
  }
  if(leituraTensao > 6.5){
    digitalWrite(led3, HIGH);
    delay(150);
  }
  if(leituraTensao > 7.0){
    digitalWrite(led2, HIGH);
    delay(150);
  }
  if(leituraTensao > 8.0){
    digitalWrite(led1, HIGH);
    delay(150);
  }
  delay(1500);
  apagaLeds();
}

void apagaLeds(){
  digitalWrite(led1, LOW);
  delay(150);
  digitalWrite(led2, LOW);
  delay(150);
  digitalWrite(led3, LOW);
  delay(150);
  digitalWrite(led4, LOW);
  delay(150);
  digitalWrite(led5, LOW);
}
