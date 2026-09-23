#ifndef I_HANDLER_HPP
#define I_HANDLER_HPP

#include <ArduinoJson.h>

class IHandler {
    public:
        virtual void handle(const JsonDocument& doc) = 0;
};

#endif // I_HANDLER_HPP
