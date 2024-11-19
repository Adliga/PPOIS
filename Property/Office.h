#pragma once
#ifndef OFFICE_H
#define OFFICE_H

#include "Property.h"
#include <string>

class Office : public Property {
private:
    std::string officeType;

public:
    Office(bool available, double cost, const std::string& address, const std::string& officeType);
    void displayPropertyInfo() const override;
};

#endif 
