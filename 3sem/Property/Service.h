#pragma once
#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>

class Service {
private:
    std::string serviceName;
    double serviceCost;

public:
    Service(const std::string& serviceName, double serviceCost);

    std::string getServiceName() const;
    double getServiceCost() const;
    void displayServiceInfo() const;
};

#endif 
