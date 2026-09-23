#ifndef DEVICES_HANDLER_HPP
#define DEVICES_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/handlers/iHandler.hpp"

class DevicesHandler : public IHandler {
    public:
        void handle(const JsonDocument& doc) override;
};

#endif // DEVICES_HANDLER_HPP
