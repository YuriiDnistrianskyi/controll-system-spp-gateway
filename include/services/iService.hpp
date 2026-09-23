#ifndef I_SERVICE_HPP
#define I_SERVICE_HPP

class IService {
    public:
        virtual void setup() = 0;
        virtual void loop() = 0;
};

#endif // I_SERVICE_HPP
