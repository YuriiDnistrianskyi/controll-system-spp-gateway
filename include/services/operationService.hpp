#ifndef OPERATION_SERVICE_HPP
#define OPERATION_SERVICE_HPP

#include "../include/services/iService.hpp"
#include "../include/connection/webSocketManager.hpp"

class OperationService : public IService {
    public:
        void setup() override;
        void loop() override;

    private:
        WebSocketManager webSocketManager;
};

#endif // OPERATION_SERVICE_HPP
