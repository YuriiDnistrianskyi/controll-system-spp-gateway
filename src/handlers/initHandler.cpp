#include <ArduinoJson.h>

#include "../include/handlers/inithHandler.hpp"
#include "../include/core/configStorage.hpp"

extern ConfigStorage configStorage;

void InitHandler::handle(const JsonDocument& doc) {
    const char* result = doc["result"];
    if (strcmp(result, "success") == 0) {
        Serial.println("Initialization success");
        uint16_t gatewayId = doc["gateway_id"];
        const char* token = doc["token"];
        configStorage.setGatewayId(gatewayId);
        configStorage.setDeviceToken(token);
    }
}
