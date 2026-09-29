#include <vector>

#include "../include/espNowHandlers/statusHandler.hpp"

#include "../include/connection/webSocketManager.hpp"
#include "../include/structures/connection_device.hpp"


extern WebSocketManager webSocketManager;
extern std::vector<ConnectionDevice> devices;

ConnectionDevice StatusHandler:getDeviceByMacAddress(const String macAddress) {
    for (const auto& device : devices) {
        if (strcmp(device.macAddress, macAddress) == 0) {
            return device;
        }
    }
}


void StatusHandler:handle(const JsonDocument& doc, const String& macAddress) {
    const String state = doc["state"]

    // if (strcmp(state, "on") == 0) {
    //
    // } else {
    //
    // }

    StaticJsonDocument<200> sendDoc;
    StaticJsonDocument<200> deviceDoc;

    ConnectionDevice device = getDeviceByMacAddress(macAddress);

    if (!device) {
        Serial.println("Not found conencted device by mac address: " + String(macAddress));
        return;
    }

    deviceDoc["id"] = device.id;
    deviceDoc["state"] = state;

    sendDoc["connected_device"] = deviceDoc;

    webSocketManager.send(sendDoc);
}
