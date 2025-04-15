#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include "Property.h"

class House : public Property {
private:
    double gardenSize;
    int floorCount;

public:
    House(bool available, double cost, const std::string& address, double gardenSize, int floorCount);

    void displayPropertyInfo() const override;
};

#endif 
