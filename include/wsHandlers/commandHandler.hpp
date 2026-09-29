#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/wsHandlers/iWsHandler.hpp"

class CommandHandler : public IWsHandler {
    public:
        void handle(const JsonDocument& doc) override;
};

#endif // COMMAND_HANDLER_HPP
