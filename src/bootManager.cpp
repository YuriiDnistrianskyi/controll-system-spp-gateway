#include <LittleFS.h>

#include "../include/bootManager.hpp"
#include "../include/configStorage.hpp"
#include "../include/wifiManager.hpp"
#include "../include/localServer.hpp"

ConfigStorage configStorage;

WifiManager wifiManager;

LocalServer localServer;

void BootManager::setup() {
    configStorage.begin();
    String ssid = configStorage.getWifiSSID();
    String password = configStorage.getWifiPassword();

    if (!LittleFS.begin()) {
            Serial.println("Faile begin LittleFS");
            return;
        }

    if (ssid.isEmpty() || password.isEmpty()) {
        Serial.println("Wifi SSID or password is not set.");
        Serial.println("Start local wifi for configuration.");

        wifiManager.initWifi();
        localServer.begin();
        bootMode = LOCAL_SERVER_MODE;
        return;
    }

    bool wifiStatus = wifiManager.connectToWifi(ssid.c_str(), password.c_str());

    if (wifiStatus) 
    {
        bootMode = OPERATIONG_MODE;
        int id = configStorage.getGatewayId();
        String token = configStorage.getDeviceToken();
        if (id == NULL || token.isEmpty()) {
            String code = configStorage.getActivationCode();
            if (code.isEmpty()) {
                wifiManager.initWifi();
                localServer.begin();
                bootMode = LOCAL_SERVER_MODE;
                return;
            }

            // connect to server
            // get id and token from server
            // get device list from server
        }

        // conect to server
        // get device list
        bootMode = OPERATIONG_MODE;
    } 
    else {
        wifiManager.initWifi();
        localServer.begin();
        bootMode = LOCAL_SERVER_MODE;
        return;
    }
}

void BootManager::loop() {
    switch(bootMode) {
        case LOCAL_SERVER_MODE:
            localServer.loop();
            break;
        case OPERATIONG_MODE:
            break;
        default:
            Serial.println("Unknown boot mode " + String(bootMode));
            break;
    }
}
