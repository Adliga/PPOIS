#include "Service.h"

Service::Service(const std::string& serviceName, double serviceCost)
    : serviceName(serviceName), serviceCost(serviceCost) {}

std::string Service::getServiceName() const {
    return serviceName;
}

double Service::getServiceCost() const {
    return serviceCost;
}

void Service::displayServiceInfo() const {
    std::cout
        << "Service Name: " << serviceName << "\n"
        << "Service cost: " << serviceCost << " byn.\n";
}
