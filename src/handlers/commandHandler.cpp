#include <ArduinoJson.h>

#include "../include/handlers/commandHandler.hpp"
#include "../include/structures/connection_device.hpp"
#include "../include/structures/sensors.hpp"

extern std::vector<ConnectionDevice> devices;
extern std::vector<Sensor> sensors;

void CommandHandler::handle(const JsonDocument& doc) {
    const char* command = doc["command"];
    uint16_t deviceId = doc["id"];
    if (strcmp(command, "on") == 0) {
        
    } else {

    }
}
