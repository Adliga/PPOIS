#include "House.h"

House::House(bool available, double cost, const std::string& address, double gardenSize, int floorCount)
    : Property(available, cost, address, "House"), gardenSize(gardenSize), floorCount(floorCount) {}

void House::displayPropertyInfo() const {
    Property::displayPropertyInfo();
    std::cout << "Garden size: " << gardenSize << " м.кв.\n";
    std::cout << "Floor count: " << floorCount << "\n";
}
