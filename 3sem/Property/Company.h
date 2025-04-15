#pragma once
#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
#include <vector>
#include "Website.h"
#include "PropertyManager.h"
#include "SupportStaff.h"

class Company {
private:
    std::string name;
    std::string address;
    std::vector<PropertyManager*> managers;
    std::vector<SupportStaff*> staff;
    Website* website;

public:
    Company(const std::string& name, const std::string& address);

    void setWebsite(Website* site);

    void addEmployee(PropertyManager* newManager);

    void addEmployee(SupportStaff* newStaff);

    void displayCompanyInfo() const;
};

#endif 
