#pragma once
#ifndef TENANT_H
#define TENANT_H

#include "User.h"
#include "LeaseAgreement.h"

class LeaseAgreement;

class Tenant : public User {
private:
    LeaseAgreement* leaseAgreement;

public:
    Tenant(const std::string& name, const std::string& email);

    LeaseAgreement* getLeaseAgreement() const;

    void setLeaseAgreement(LeaseAgreement* newLeaseAgreement);
};

#endif 
