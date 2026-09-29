#include <ArduinJson.h>
#include <vector>


#include "../include/espNowHandlers/electricalHandler.hpp"

#include "../include/connection/webSocketManager.hpp"
#include "../include/structures/sensors.hpp"

extern std::vector<Sensor> sensors;

extern WebSocketManager webSocketManager;

Sensor ElectricalHandler:getSensorByMacAddress(const String& macAddress) {
    for (const &auto sensor : sensors) {
        if (strcmp(sensor.macAddress, macAddress) == 0) {
            return sensor;
        }
    }
}

void ElectricalHandler::handle(const JsonDocument& doc, const String& macAddress) {
    int8_t voltage = doc["voltage"];
    int8_t current = doc["current"];

    StaticJsonDocument<200> sensorDoc;
    sensorDoc["macAddress"] = macAddress;
    sensorDoc["voltage"] = voltage;
    sensorDoc["current"] = current;

    StaticJsonDocument sensors[1] = { sensorDoc };

    StaticJsonDocument<200> sendDoc;
    sendDoc["type"] = "snapshot";
    sendDoc["sensors"] = sensors;

    Sensor sensor = getSensorByMacAddress(macAddress);
    if (!sensor) {
        Serial.println("Not found sensor by mac address: " + String(macAddress));
        return;
    }

    if (sensor.type == FRONT) {
        //TODO 
        //battery
        StaticJsonDocument<200> battery;
        battery["SoC"] = 100; //
        battery["sensor_id"] = 1; //

        StaticJsonDocument batteries[1] = { battery }
        sendDoc["battery"] = batteries
    }

    webSocketManager.send(sendDoc);
}
