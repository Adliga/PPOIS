#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int employeeID;
    std::string position;

public:
    Employee(const std::string& empName, int id, const std::string& pos);
    
    virtual ~Employee() = default; 

    virtual std::string getEmployeeInfo() const {
        return "Name: " + name + ", ID: " + std::to_string(employeeID) + ", Position: " + position;
    }
};

#endif  
