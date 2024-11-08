#include "Vehicle.h"

Vehicle::Vehicle(double cap, double speed) : capacity(cap), maxSpeed(speed) {}

void Vehicle::checkCapacityStatus() {
    std::cout << "Checking the technical condition of the vehicle with a load capacity of: " << capacity << " kg.\n";
}