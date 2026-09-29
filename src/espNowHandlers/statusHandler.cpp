#include <vector>

#include "../include/espNowHandlers/statusHandler.hpp"

#include "../include/connection/webSocketManager.hpp"
#include "../include/structures/connection_device.hpp"


extern WebSocketManager webSocketManager;
extern std::vector<ConnectionDevice> devices;

const ConnectionDevice* StatusHandler::getDeviceByMacAddress(const String& macAddress) {
    for (const auto& device : devices) {
        if (device.macAddress == macAddress) {
            return &device;
        }
    }
    return nullptr;
}

void StatusHandler::handle(const JsonDocument& doc, const String& macAddress) {
    const String state = doc["state"];

    // if (strcmp(state, "on") == 0) {
    //
    // } else {
    //
    // }


    const ConnectionDevice* device = getDeviceByMacAddress(macAddress);

    if (device == nullptr) {
        Serial.println("Not found conencted device by mac address: " + String(macAddress));
        return;
    }

    JsonDocument sendDoc;
    sendDoc["type"] = "snapshot";
    JsonObject deviceObject = sendDoc["connected_device"].to<JsonObject>();
    deviceObject["id"] = device->id;
    deviceObject["state"] = state;

    webSocketManager.send(sendDoc);
}
