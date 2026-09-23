#ifndef OPERATION_SERVICE_HPP
#define OPERATION_SERVICE_HPP

#include "../include/services/iService.hpp"

class OperationService : public IService {

    public:
        void setup();
        void loop();
};

#endif // OPERATION_SERVICE_HPP
