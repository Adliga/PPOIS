#include "PostOffice.h"
#include "Employee.h"  

PostOffice::PostOffice(const std::string& addr, const std::string& hours, int counters)
    : address(addr), openingHours(hours), numberOfCounters(counters) {

    servicesAvailable.push_back("Parcel Delivery");
    servicesAvailable.push_back("Mail Handling");
    servicesAvailable.push_back("Express Delivery");
}

void PostOffice::openOffice() {
    std::cout << "PostOffice at " << address << " is now open." << std::endl;
}

void PostOffice::hireEmployee(Employee* newEmployee) {
    employees.push_back(newEmployee);
    std::cout << "Employee hired: " << newEmployee->getEmployeeInfo() << std::endl; 
}

void PostOffice::printAllEmployees() const {
    std::cout << "List of Employees:" << std::endl;
    for (const auto& employee : employees) {
        if (employee) {
            std::cout << employee->getEmployeeInfo() << std::endl; 
        }
        else { 
            std::cout << "Found null employee!" << std::endl; 
        }
    }
}

void PostOffice::fireEmployee(Employee* employeeToRemove) {
    auto it = std::find(employees.begin(), employees.end(), employeeToRemove);
    if (it != employees.end()) {
        employees.erase(it);
        std::cout << "Employee fired." << std::endl;
    }
}

int PostOffice::getCounterAvailability() const {
    return numberOfCounters;
}

void PostOffice::printAvailableServices() const {
    std::cout << "Available Services:\n";
    for (const auto& service : servicesAvailable) {
        std::cout << "- " << service << '\n';
    }
}