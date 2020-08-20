#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {
 int n = WiFi.scanNetworks(false, true, 6);

String ssid;
uint8_t encryptionType;
int32_t RSSI;
uint8_t* BSSID;
int32_t channel;
bool isHidden;

//Serial.println(n);

for (int i = 0; i < n; i++)
{
  WiFi.getNetworkInfo(i, ssid, encryptionType, RSSI, BSSID, channel, isHidden);
  Serial.printf("%d: %s, Ch:%d (%ddBm) %s %s\n", i + 1, ssid.c_str(), channel, RSSI, encryptionType == ENC_TYPE_NONE ? "open" : "", isHidden ? "hidden" : "");
}
}
