#include <WiFi.h>

#include "../include/wifiManager.hpp"
#include "../include/config.hpp"


IPAddress local_IP(192, 168, 4, 100);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

void WifiManager::initWifi() {
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(LOCAL_WIFI_SSID, LOCAL_WIFI_PASSWORD);
}

bool WifiManager::connectToWifi(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    int count = 0;
    Serial.print("Connecting to WiFi " + String(ssid) + " ...");
    for (WiFi.status() != WL_CONNECTED) {
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
