#include <ArduinoJson.h>
#include <vector>


#include "../include/espNowHandlers/electricalHandler.hpp"

#include "../include/connection/webSocketManager.hpp"
#include "../include/structures/sensors.hpp"

extern std::vector<Sensor> sensors;

extern WebSocketManager webSocketManager;

const Sensor* ElectricalHandler::getSensorByMacAddress(const String& macAddress) {
    for (const auto& sensor : sensors) {
        if (sensor.macAddress == macAddress) {
            return &sensor;
        }
    }
    return nullptr;
}

void ElectricalHandler::handle(const JsonDocument& doc, const String& macAddress) {
    int8_t voltage = doc["voltage"];
    int8_t current = doc["current"];

    JsonDocument sendDoc;
    sendDoc["type"] = "snapshot";

    JsonObject sensorObject = sendDoc["sensors"].to<JsonObject>();

    // JsonArray sensors = sendDoc["sensors"].to<JsonArray>();
    // JsonObject sensorObject = sensors.add<JsonObject>();

    sensorObject["macAddress"] = macAddress;
    sensorObject["voltage"] = voltage;
    sensorObject["current"] = current;
    sensorObject["power"] = voltage * current;

    const Sensor* sensor = getSensorByMacAddress(macAddress);
    if (sensor == nullptr) {
        Serial.println("Not found sensor by mac address: " + String(macAddress));
        return;
    }

    if (sensor->type == FRONT) {
        //TODO 
        //battery
        JsonObject batteryObject = sendDoc.to<JsonObject>();
        batteryObject["SoC"] = 100; //
        batteryObject["sensor_id"] = 1; //
    }

    webSocketManager.send(sendDoc);
}
