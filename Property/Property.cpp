#include "Property.h"

Property::Property(bool available, double cost, const std::string& address, const std::string& type)
    : isAvailable(available), cost(cost), address(address), type(type) {}

bool Property::getIsAvailable() const {
    return isAvailable;
}
double Property::getCost() const { 
    return cost;
}

void Property::setIsAvailable(bool availability) {
    isAvailable = availability;
}

void Property::displayPropertyInfo() const {
    std::cout << "Property type: " << type << "\n";
    std::cout << "Adress: " << address << "\n";
    std::cout << "Cost: " << cost << "\n";
}
