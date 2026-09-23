#ifndef INIT_HANDLER_HPP
#define INIT_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/handlers/iHandler.hpp"

class InitHandler : public IHandler {
    public:
        void handle(const JsonDocument& doc) override;
};

#endif // INIT_HANDLER_HPP
