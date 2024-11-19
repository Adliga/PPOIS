#include "Apartment.h"

Apartment::Apartment(bool available, double cost, const std::string& address, int floor, int roomCount)
    : Property(available, cost, address, "Apartment"), floor(floor), roomCount(roomCount) {}

void Apartment::displayPropertyInfo() const {
    Property::displayPropertyInfo();
    std::cout << "Floor: " << floor << "\n";
    std::cout << "Room count: " << roomCount << "\n";
}
