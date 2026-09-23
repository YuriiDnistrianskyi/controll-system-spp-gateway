#include "../include/services/operationService.hpp"

void OperationService::setup() {
    webSocketManager.connect();
    // esp now
}

void OperationService::loop() {
    webSocketManager.loop();

}
