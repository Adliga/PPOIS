#include "LeaseAgreement.h"

LeaseAgreement::LeaseAgreement(Tenant* tenant, Landlord* landlord, Property* property, const std::string& startDate, const std::string& endDate)
    : tenant(tenant), landlord(landlord), property(property), startDate(startDate), endDate(endDate) {}

void LeaseAgreement::displayAgreementInfo() const {
    std::cout << "Lease Agreement Details:" << std::endl;

    std::cout << "\nProperty Info:" << std::endl;
    if (property) {
        property->displayPropertyInfo();
    }
    else {
        std::cout << "No property assigned!" << std::endl;
    }

    std::cout << "\nLandlord Info:" << std::endl;
    if (landlord) {
        landlord->displayUserInfo();
    }
    else {
        std::cout << "No landlord information available!" << std::endl;
    }

    std::cout << "\nTenant Info:" << std::endl;
    if (tenant) {
        tenant->displayUserInfo();
    }
    else {
        std::cout << "No tenant information available!" << std::endl;
    }

    std::cout << "\nLease Start Date: " << startDate << std::endl;
    std::cout << "Lease End Date: " << endDate << std::endl;
}
