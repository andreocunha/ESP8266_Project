//Projeto feito para detectar se as pessoas estao muito proximas umas das outras nesse momento de pandemia do COVID-19
//Feito por: André Oliveira Cunha
//3° Periodo de Engenharia de Computacao - UFES


#include "ESP8266WiFi.h"
#define apito 3
#define led 2

int estado = 0;
//float seno;
//int frequencia;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  pinMode(led, OUTPUT);
  pinMode(apito, OUTPUT);

//inicializa o esp8266 como access point
  boolean result = WiFi.softAP("COVID19", "12345678");
  if(result == true){
    Serial.println("Tudo pronto!");
  }
  else{
    Serial.println("Falhou!");
    while(1){
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
    }
  }

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  digitalWrite(led, HIGH);
  digitalWrite(apito, LOW);
  delay(2000);
  digitalWrite(led, LOW);
}

void loop() {
  estado = 0;

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

        if(WiFi.RSSI(i) >= -40){
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
      digitalWrite(led, HIGH);
      digitalWrite(apito, HIGH);

//      //repeticao para gerar o apito no buzzer
//      for(int x=0;x<180;x++){
//        //converte graus para radiando e depois obtém o valor do seno
//        seno=(sin(x*3.1416/180));
//        //gera uma frequência a partir do valor do seno
//        frequencia = 2000+(int(seno*1000));
//        tone(apito,frequencia);
//        delay(2);
//      }
      delay(50);
    }
    else{
      digitalWrite(led, LOW);
      digitalWrite(apito, LOW);
    }
}
