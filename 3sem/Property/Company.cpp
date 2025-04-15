#include "Company.h"

Company::Company(const std::string& name, const std::string& address)
    : name(name), address(address), website(nullptr) {}

void Company::setWebsite(Website* site) {
    website = site;
}

void Company::addEmployee(PropertyManager* newManager) {
    if (newManager) {
        managers.push_back(newManager);
        std::cout << "Manager added" << std::endl;
    }
    else {
        std::cout << "Error: Attempted to add a null employee!" << std::endl;
    }
}

void Company::addEmployee(SupportStaff* newStaff) {
    if (newStaff) {
        staff.push_back(newStaff);
        std::cout << "Staff added" << std::endl;
    }
    else {
        std::cout << "Error: Attempted to add a null employee!" << std::endl;
    }
}

void Company::displayCompanyInfo() const {
    std::cout << "Company: " << name << "\n";
    std::cout << "Adress: " << address << "\n";
    if (website) {
        std::cout << "Site: " << website->getURL() << "\n";
    }
    else {
        std::cout << "Site doesn't exist" << "\n";
    }
}
