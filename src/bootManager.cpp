#include "../include/bootManager.hpp"
#include "../include/configStorage.hpp"
#include "../include/wifiManager.hpp"

extern ConfigStorage configStorage;

WifiManager wifiManager;

void BootManager::setup() {
    String ssid =configStorage.getWifiSSID();
    String password = configStorage.getWifiPassword();

    if (ssid.isEmpty() || password.isEmpty()) {
        Serial.println("Wifi SSID or password is not set.");
        Serial.println("Start local wifi for configuration.");

        wifiManager.initWifi();
        // ...

        return;
    }

    bool wifiStatus = wifiManager.connectToWifi(ssid.c_str(), password.c_str());

    if (wifiStatus) 
    {
        wifiManager.initWifi();
        // ...
    } 
    else {
        
    }


}

void BootManager::loop() {

}
