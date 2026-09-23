#include <ArduinoJson.h>

#include "../include/handlers/devicesHandler.hpp"

#include "../include/structures/connection_device.hpp"
#include "../include/structures/sensors.hpp"

std::vector<ConnectionDevice> devices;
std::vector<Sensor> sensors;

void DevicesHandler::handle(const JsonDocument& doc) {
    devices.clear();
    sensors.clear();

    for (JsonObject device : doc["connected_devices".as<JsonArray>()]) {
        devices.push_back({
            device["id"],
            device["mac_address"].as<String>()
        });
    }

    for (JsonObject sensor : doc["sensors"].as<JsonArray>()) {
        sensors.push_back({
            sensor["id"],
            sensor["mac_address"].as<String>(),
            sensor["type"] == "FRONT" ? SensorType::FRONT : SensorType::BACK
        });
    }
}