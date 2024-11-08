#pragma once

#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
private:
    bool isElectric;

public:
    Bicycle(double cap, double speed, bool electr);

    std::string getVehicleType() const override;
    bool getIsElectric() const;
};


#endif
