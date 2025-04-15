#pragma once
#ifndef PROPERTY_MANAGER_H
#define PROPERTY_MANAGER_H

#include "User.h"
#include "LeaseAgreement.h"
#include "Tenant.h"
#include "Landlord.h"
#include "Property.h"
#include <iostream>
#include <string>

class PropertyManager : public User {
private:
    std::vector<LeaseAgreement*> arrangedAgreements;
public:
    PropertyManager(const std::string& name, const std::string& email);

    void getArrangedAgreements() const;
    void arrangeAgreement(LeaseAgreement* newAgreement);
};

#endif 
