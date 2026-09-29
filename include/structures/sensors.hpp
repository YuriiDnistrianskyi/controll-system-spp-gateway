#ifndef SENSORS_HPP
#define SENSORS_HPP

#include <Arduino.h>

enum SensorType {
    FRONT,
    BACK
};

struct Sensor {
    uint16_t id;
    String macAddress;
    SensorType type;
};

#endif // SENSORS_HPP
