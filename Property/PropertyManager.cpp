#include "PropertyManager.h"

PropertyManager::PropertyManager(const std::string& name, const std::string& email)
    : User(name, email, "Property manager") {}

void PropertyManager::getArrangedAgreements() const {
    std::cout << "List of arranged agreements:" << std::endl;
    for (const auto& agr : arrangedAgreements) {
        if (agr) {
            agr->displayAgreementInfo();
            std::cout << std::endl;
        }
        else {
            std::cout << "Found null agreements!" << std::endl;
        }
    }
}

void PropertyManager::arrangeAgreement(LeaseAgreement* newAgreement) {
    if (newAgreement) {
        arrangedAgreements.push_back(newAgreement);
        std::cout << "Agreement arranged";
    }
    else {
        std::cout << "Error: Attempted to add a null agreement" << std::endl;
    }
    std::cout << std::endl;
}




