#include <ArduinoJson.h>
#include <vector>

#include "../include/wsHandlers/devicesHandler.hpp"

#include "../include/structures/connection_device.hpp"
#include "../include/structures/sensors.hpp"

std::vector<ConnectionDevice> devices;
std::vector<Sensor> sensors;

void DevicesHandler::handle(const JsonDocument& doc) {
    devices.clear();
    sensors.clear();

    for (JsonObjectConst device : doc["connected_devices"].as<JsonArrayConst>()) {
        devices.push_back({
            device["id"],
            device["mac_address"].as<String>()
        });
    }

    for (JsonObjectConst sensor : doc["sensors"].as<JsonArrayConst>()) {
        sensors.push_back({
            sensor["id"],
            sensor["mac_address"].as<String>(),
            sensor["type"] == "FRONT" ? SensorType::FRONT : SensorType::BACK
        });
    }
}