#pragma once

#ifndef CLERC_H
#define CLERC_H

#include "Employee.h"

class Clerk : public Employee {
private:
    int counter;

public:
    Clerk(const std::string& empName, int id);

    std::string getEmployeeInfo() const override;

    int getCounter() const;

    void setCounter(int place);
};

#endif