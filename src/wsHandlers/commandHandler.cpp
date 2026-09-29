#include <ArduinoJson.h>
#include <vector>

#include "../include/wsHandlers/commandHandler.hpp"
#include "../include/structures/connection_device.hpp"
#include "../include/connection/espNowManager.hpp"

extern EspNowManager espNowManager;

extern std::vector<ConnectionDevice> devices;

ConnectionDevice getDeviceById(uint8_t id) {
    for (const auto& device : devices) {
        if (device.id == id) {
            return device;
        }
    }
}

void CommandHandler::handle(const JsonDocument& doc) {
    const char* command = doc["command"];
    uint16_t deviceId = doc["id"];
    ConnectionDevice device = getDeviceById(deviceId);

    if (!device) {
        Serial.println("Not found conencted device by id: " + String(deviceId));
    }

    StaticJsonDocument<200> sendDoc;
    sendDoc["command"] = doc["command"];

    espNowManager.sendData(device.macAddress, sendDoc);
}
