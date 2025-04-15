#include "Office.h"

Office::Office(bool available, double cost, const std::string& address, const std::string& officeType)
    : Property(available, cost, address, "Office"), officeType(officeType) {}

void Office::displayPropertyInfo() const {
    Property::displayPropertyInfo();
    std::cout << "Office type: " << officeType << "\n";
}
