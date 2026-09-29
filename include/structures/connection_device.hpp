#ifndef CONNECTION_DEVICE_HPP
#define CONNECTION_DEVICE_HPP

#include <Arduino.h>

struct ConnectionDevice {
    uint16_t id;
    String macAddress;
};

#endif // CONNECTION_DEVICE_HPP
