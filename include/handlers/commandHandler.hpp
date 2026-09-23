#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/handlers/iHandler.hpp"

class CommandHandler : public IHandler {
    public:
        void handle(const JsonDocument& doc) override;
};

#endif // COMMAND_HANDLER_HPP
