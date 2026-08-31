#ifndef BOOT_MANAGER_HPP
#define BOOT_MANAGER_HPP

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
        void scan();
        BootMode bootMode;
};

#endif // BOOT_MANAGER_HPP
