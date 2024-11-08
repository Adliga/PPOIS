#pragma once

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    double engineSize;

public:
    Car(double cap, double speed, double engSize);

    std::string getVehicleType() const override;
};


#endif
