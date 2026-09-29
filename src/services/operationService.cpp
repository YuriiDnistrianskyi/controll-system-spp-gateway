#include <ArduinoJson.h>

#include "../include/services/operationService.hpp"
#include "../include/connection/espNowManager.hpp"
#include "../include/connection/webSocketManager.hpp"
#include "../include/core/configStorage.hpp"

extern ConfigStorage configStorage;

EspNowManager espNowManager;
WebSocketManager webSocketManager;


void OperationService::setup() {
    webSocketManager.connect();
    StaticJsonDocument<200> doc;
    doc["type"] = "authentication";
    doc["id"] = configStorage.getGatewayId();
    doc["token"] = configStorage.getDeviceToken();
    webSocketManager.send(doc);
    
    // Create flat for getting a list of devices
    // TODO

    espNowManager.begin();
}

void OperationService::loop() {
    webSocketManager.loop();

    // TODO
    // Add geting parameters of wifi

}
