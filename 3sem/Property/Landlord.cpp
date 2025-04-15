#include "Landlord.h"

Landlord::Landlord(const std::string& name, const std::string& email)
    : User(name, email, "Landlord") {}

void Landlord::getProperties() const {
    std::cout << "List of properties:" << std::endl;
    for (const auto& property : properties) {
        if (property) {
            property->displayPropertyInfo();
            std::cout << std::endl;
        }
        else {
            std::cout << "Found null properties!" << std::endl;
        }
    }
}

void Landlord::addProperty(Property* newProperty) {
    if (newProperty) {
        properties.push_back(newProperty);
        std::cout << "Property added: ";
        newProperty->displayPropertyInfo();
    }
    else {
        std::cout << "Error: Attempted to add a null property!" << std::endl;
    }
    std::cout << std::endl;
}
