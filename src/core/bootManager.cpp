#include <LittleFS.h>

#include "../include/core/bootManager.hpp"
#include "../include/core/configStorage.hpp"
#include "../include/connection/wifiManager.hpp"
#include "../include/services/localServerService.hpp"
#include "../include/services/operationService.hpp"

ConfigStorage configStorage;

WifiManager wifiManager;

void BootManager::scan() {
    configStorage.begin();
    String ssid = configStorage.getWifiSSID();
    String password = configStorage.getWifiPassword();

    if (!LittleFS.begin()) {
            Serial.println("Faile begin LittleFS");
            bootMode = ERROR_MODE;
            return;
        }

    if (ssid.isEmpty() || password.isEmpty()) {
        Serial.println("Wifi SSID or password is not set.");
        Serial.println("Start local wifi for configuration.");

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
                Serial.println("Activation code is not set.");
                Serial.println("Start local wifi for configuration.");
                bootMode = LOCAL_SERVER_MODE;
                return;
            }

            // connect and initialize this gateway
            bootMode = INITIALIZATION_MODE;
            return;
        } 
        else {
            bootMode = OPERATIONG_MODE;
            return;
        }
    } 
    else {
        bootMode = LOCAL_SERVER_MODE;
        return;
    }
}

void BootManager::setup() {
    scan();
    switch(bootMode) {
        case LOCAL_SERVER_MODE:
            localServerService.setup();
            break;
        case INITIALIZATION_MODE:
            // TODO
            bootMode = OPERATIONG_MODE;
            break;
        case OPERATIONG_MODE:
            operationService.setup();
            break;
        case ERROR_MODE:
            Serial.println("Error mode. Please check the logs.");
            break;
        default:
            Serial.println("Unknown boot mode " + String(bootMode));
            break;
    }
}


void BootManager::loop() {
    switch(bootMode) {
        case LOCAL_SERVER_MODE:
            localServerService.loop();
            break;
        case OPERATIONG_MODE:
            operationService.loop();
            break;
        case ERROR_MODE:
            break;
        default:
            Serial.println("Unknown boot mode " + String(bootMode));
            break;
    }
}
