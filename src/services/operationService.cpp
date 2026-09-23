#include "../include/services/operationService.hpp"

void OperationService::setup() {
    webSocketManager.connect();
    // send token

    // esp now
}

void OperationService::loop() {
    webSocketManager.loop();

}
