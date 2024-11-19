#pragma once
#ifndef APARTMENT_H
#define APARTMENT_H

#include "Property.h"

class Apartment : public Property {
private:
    int floor;
    int roomCount;

public:
    Apartment(bool available, double cost, const std::string& address, int floor, int roomCount);

    void displayPropertyInfo() const override;
};

#endif 
