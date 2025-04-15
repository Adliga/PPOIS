#pragma once

#ifndef COURIER_H
#define COURIER_H

#include "Employee.h"
#include "Mail.h"
#include "Vehicle.h"

class Courier : public Employee {
private:
    Vehicle* deliveryVehicle;

public:
    Courier(const std::string& empName, int id, Vehicle* vehicle);

    std::string getEmployeeInfo() const override;
    void deliverMail(Mail& mail);
    void checkVehicleCapacity();
};
#endif
