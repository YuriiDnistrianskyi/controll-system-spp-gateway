#ifndef INIT_HANDLER_HPP
#define INIT_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/wsHandlers/iWsHandler.hpp"

class InitHandler : public IWsHandler {
    public:
        void handle(const JsonDocument& doc) override;
};

#endif // INIT_HANDLER_HPP
