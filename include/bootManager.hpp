#ifndef BOOT_MANAGER_HPP
#define BOOT_MANAGER_HPP

enum BootMode {
    LOCAL_SERVER_MODE,
    OPERATIONG_MODE,
};

class BootManager {
    public:
        void setup();
        void loop();

    private:
        BootMode bootMode;
};

#endif // BOOT_MANAGER_HPP
