#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);

  delay(100);
}

void loop() {
  Serial.println("Wifi scan started");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("Wifi scan ended");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found

      if(WiFi.SSID(i) == "COVID19"){
        Serial.print(i + 1);
        Serial.print(") ");
        Serial.print(WiFi.SSID(i));// SSID
        Serial.println(WiFi.RSSI(i));//Signal strength in dBm  
        Serial.print("dBm");
      }
    }
  Serial.println("");
  }
}
