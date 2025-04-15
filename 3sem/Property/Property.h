#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <string>
#include <vector>

class Property {
protected:
    bool isAvailable;
    double cost;
    std::string address;
    std::string type;

public:
    Property(bool available, double cost, const std::string& address, const std::string& type);
    virtual ~Property() = default;

    bool getIsAvailable() const;
    double getCost() const;
    void setIsAvailable(bool availability);

    virtual void displayPropertyInfo() const;
};

#endif 
