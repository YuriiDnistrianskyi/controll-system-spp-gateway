#include <ArduinoJson.h>
#include <vector>

#include "../include/wsHandlers/commandHandler.hpp"
#include "../include/structures/connection_device.hpp"
#include "../include/connection/espNowManager.hpp"

extern EspNowManager espNowManager;

extern std::vector<ConnectionDevice> devices;

const ConnectionDevice* getDeviceById(uint8_t id) {
    for (const auto& device : devices) {
        if (device.id == id) {
            return &device;
        }
    }
    return nullptr;
}

void CommandHandler::handle(const JsonDocument& doc) {
    const char* command = doc["command"];
    uint16_t deviceId = doc["id"];
    const ConnectionDevice* device = getDeviceById(deviceId);

    if (device == nullptr) {
        Serial.println("Not found conencted device by id: " + String(deviceId));
        return;
    }

    JsonDocument sendDoc;
    sendDoc["command"] = doc["command"];

    espNowManager.sendData(device->macAddress, sendDoc);
}
