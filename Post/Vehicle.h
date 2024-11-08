#pragma once

#ifndef VEHICLE_H
#define VEHICLE_H
 
#include <string>
#include <iostream>

class Vehicle {
protected:
    double capacity;   
    double maxSpeed;  

public:
    Vehicle(double cap, double speed); 

    void checkCapacityStatus();          
    virtual std::string getVehicleType() const = 0;
};
#endif
