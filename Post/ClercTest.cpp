#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Clerk.cpp"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Employee.cpp"
#include <sstream>

TEST(ClerkTest, GetEmployeeInfoTest) {
    Clerk myClerk("Jane Doe", 101);
    EXPECT_EQ(myClerk.getEmployeeInfo(), "Employee: Jane Doe, ID: 101, Position: Clerk");
}

TEST(ClerkTest, GetAndSetCounterTest) {
    Clerk myClerk("John Smith", 102);
    myClerk.setCounter(5);
    EXPECT_EQ(myClerk.getCounter(), 5);
}
