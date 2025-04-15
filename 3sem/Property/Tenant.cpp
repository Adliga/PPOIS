#include "Tenant.h"

Tenant::Tenant(const std::string& name, const std::string& email)
    : User(name, email, "Tenant"), leaseAgreement(nullptr) {}

LeaseAgreement* Tenant::getLeaseAgreement() const {
    return leaseAgreement;
}

void Tenant::setLeaseAgreement(LeaseAgreement* newLeaseAgreement) {
    leaseAgreement = newLeaseAgreement;
}

