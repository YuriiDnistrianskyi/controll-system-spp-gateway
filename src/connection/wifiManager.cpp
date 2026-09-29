#include <WiFi.h>

#include "../include/connection/wifiManager.hpp"
#include "../include/core/config.hpp"


IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

void WifiManager::initWifi() {
    if (!WiFi.softAPConfig(local_IP, gateway, subnet)) {
        Serial.println("Failed to configure soft AP");
    }
    WiFi.softAP(LOCAL_WIFI_SSID, LOCAL_WIFI_PASSWORD);
    Serial.println(WiFi.softAPIP());
}

bool WifiManager::connectToWifi(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    int count = 0;
    Serial.print("Connecting to WiFi " + String(ssid) + " ...");
    while (WiFi.status() != WL_CONNECTED) {
        if (count >= 20) {
            Serial.println("Failed to connect to WiFi (20 seconds).");
            return false;
        }
        delay(1000);
        Serial.print(".");
        count++;
    }
    Serial.println("Connected to WiFi " + String(ssid));
    Serial.println("IP address: " + WiFi.localIP().toString());
    return true;
}
