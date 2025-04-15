#pragma once 

#ifndef POSTOFFICE_H
#define POSTOFFICE_H

#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class PostOffice {
private:
    std::string address;
    std::vector<Employee*> employees;           
    std::string openingHours;                   
    std::vector<std::string> servicesAvailable;  
    int numberOfCounters;

public:
    PostOffice(const std::string& addr, const std::string& hours, int counters);

    void openOffice();
    void hireEmployee(Employee* newEmployee);
    void fireEmployee(Employee* employeeToRemove);
    int getCounterAvailability() const; 
    void printAllEmployees() const; 
    void printAvailableServices() const;
  
};

#endif