#include "Car.h"

Car::Car(double cap, double speed, double engSize)
    : Vehicle(cap, speed), engineSize(engSize) {}

std::string Car::getVehicleType() const {
    return "Car";
}
