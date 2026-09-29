#include <ArduinJson.h>
#include <vector.h>


#include "../include/espNowHandlers/electricalHandler.hpp"

#include "../include/connection/webSocketManager.hpp"
#include "../include/structures/connection_device.hpp"
#include "../include/structures/sensors.hpp"

extern std::vector<ConnectionDevice> devices;
extern std::vector<Sensor> sensors;

extern WebSocketManager webSocketManager;

bool ElectricalHandler:sensorIsFront(const String macAddress) {
    for (const &auto sensor : sensors) {
        if (strcmp(macAddress, sensor.macAddress)) {
            if (sensor.type == FRONT) {
                return true;
            }
        }
    }
    return false;
}

void ElectricalHandler::handle(const JsonDocument doc, const String macAddress) {
    int8_t voltage = doc["voltage"];
    int8_t current = doc["current"];

    StaticJsonDocument<200> sensor;
    sensor["macAddress"] = macAddress;
    sensor["voltage"] = voltage;
    sensor["current"] = current;

    StaticJsonDocument sensors[1] = { sensor }

    StaticJsonDocument<200> sendDoc;
    sendDoc["type"] = "snapshot";
    sendDoc["sensors"] = sensors;


    if (sensorIsFront(macAddress) == true) {
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
