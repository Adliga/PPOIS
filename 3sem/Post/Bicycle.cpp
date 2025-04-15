#include "Bicycle.h"

Bicycle::Bicycle(double cap, double speed, bool electr)
    : Vehicle(cap, speed), isElectric(electr) {}

std::string Bicycle::getVehicleType() const {
    return "Bicycle";
}

bool Bicycle::getIsElectric() const {
    return isElectric;
}
