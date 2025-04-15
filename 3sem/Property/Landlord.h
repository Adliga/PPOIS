#pragma once
#ifndef LANDLORD_H
#define LANDLORD_H

#include "User.h"
#include "Property.h"
#include <vector>

class Landlord : public User {
private:
    std::vector<Property*> properties;

public:
    Landlord(const std::string& name, const std::string& email);

    void getProperties() const;
    void addProperty(Property* newProperty);
};

#endif 
