#include "Clerk.h"

Clerk::Clerk(const std::string& empName, int id)
    : Employee(empName, id, "Clerk"), counter(0) {}

std::string Clerk::getEmployeeInfo() const {
    return "Employee: " + name + ", ID: " + std::to_string(employeeID) +", Position: " + position;
}

int Clerk::getCounter() const {
    return counter;
}

void Clerk::setCounter(int place) {
    counter = place;
}