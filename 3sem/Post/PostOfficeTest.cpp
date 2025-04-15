#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\PostOffice.cpp"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\Clerk.h"
#include <sstream>
#include <iostream>

TEST(PostOfficeTest, OpenOfficeTest) {
    PostOffice office("123 Main St", "9 AM - 5 PM", 5);
    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    office.openOffice();
    std::cout.rdbuf(prevCoutBuf);
    EXPECT_EQ(buffer.str(), "PostOffice at 123 Main St is now open.\n");
}

TEST(PostOfficeTest, HireEmployeeTest) {
    PostOffice office("123 Main St", "9 AM - 5 PM", 5);
    Employee* newEmployee = new Clerk("John Doe", 1);
    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    office.hireEmployee(newEmployee);
    std::cout.rdbuf(prevCoutBuf);
    EXPECT_EQ(buffer.str(), "Employee hired: Employee: John Doe, ID: 1, Position: Clerk\n");
    delete newEmployee;
}

TEST(PostOfficeTest, PrintAllEmployeesTest) {
    PostOffice office("123 Main St", "9 AM - 5 PM", 5);
    Employee* emp1 = new Clerk("John Doe", 1);
    Employee* emp2 = new Clerk("Jane Smith", 2);
    office.hireEmployee(emp1);
    office.hireEmployee(emp2);
    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    office.printAllEmployees();
    std::cout.rdbuf(prevCoutBuf);
    std::string expectedOutput =
        "List of Employees:\n"
        "Employee: John Doe, ID: 1, Position: Clerk\n"
        "Employee: Jane Smith, ID: 2, Position: Clerk\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
    delete emp1;
    delete emp2;
}

TEST(PostOfficeTest, FireEmployeeTest) {
    PostOffice office("123 Main St", "9 AM - 5 PM", 5);
    Employee* emp1 = new Clerk("John Doe", 1);
    office.hireEmployee(emp1);
    office.fireEmployee(emp1);
    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    office.printAllEmployees();
    std::cout.rdbuf(prevCoutBuf);
    EXPECT_EQ(buffer.str(), "List of Employees:\n");
    delete emp1;
}

TEST(PostOfficeTest, GetCounterAvailabilityTest) {
    PostOffice office("123 Main St", "9 AM - 5 PM", 5);
    EXPECT_EQ(office.getCounterAvailability(), 5);
}

TEST(PostOfficeTest, PrintAvailableServicesTest) {
    PostOffice office("123 Main St", "9 AM - 5 PM", 5);
    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    office.printAvailableServices();
    std::cout.rdbuf(prevCoutBuf);
    std::string expectedOutput =
        "Available Services:\n"
        "- Parcel Delivery\n"
        "- Mail Handling\n"
        "- Express Delivery\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}
