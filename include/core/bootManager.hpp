#ifndef BOOT_MANAGER_HPP
#define BOOT_MANAGER_HPP

#include "../include/services/localServerService.hpp"
#include "../include/services/operationService.hpp"

enum BootMode {
    LOCAL_SERVER_MODE,
    INITIALIZATION_MODE,
    OPERATIONG_MODE,
    ERROR_MODE
};

class BootManager {
    public:
        void setup();
        void loop();

    private:
        LocalServerService localServerService;
        OperationService operationService;

        BootMode bootMode;
        void scan();
};

#endif // BOOT_MANAGER_HPP
