#pragma once
#ifndef LEASEAGREEMENT_H
#define LEASEAGREEMENT_H

#include "Tenant.h"
#include "Landlord.h"
#include "Property.h"

class Tenant;

class LeaseAgreement {
private:
    Tenant* tenant;
    Landlord* landlord;
    Property* property;
    std::string startDate;
    std::string endDate;

public:
    LeaseAgreement(Tenant* tenant, Landlord* landlord, Property* property, const std::string& startDate, const std::string& endDate);
    void displayAgreementInfo() const;
};

#endif 
