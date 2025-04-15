#include "Courier.h"

Courier::Courier(const std::string& empName, int id, Vehicle* vehicle)
    : Employee(empName, id, "Courier"), deliveryVehicle(vehicle) {}

std::string Courier::getEmployeeInfo() const {
    return "Employee: " + name + ", ID: " + std::to_string(employeeID) +
        ", Position: " + position + ", Vehicle: " + deliveryVehicle->getVehicleType();
}

void Courier::deliverMail(Mail& mail) {
    std::cout << "Delivering mail with tracking number " << mail.getTrackingNumber()
        << " using " << deliveryVehicle->getVehicleType() << "." << std::endl;
    mail.markAsDelivered();
    std::cout << "Mail delivered." << std::endl;
}

void Courier::checkVehicleCapacity() {
    deliveryVehicle->checkCapacityStatus();
}

