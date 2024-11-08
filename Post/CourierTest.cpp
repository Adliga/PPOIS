#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Courier.cpp"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Car.h"
#include <sstream>

TEST(CourierTest, GetEmployeeInfoTest) {
    Car deliveryCar(500.0, 220.0, 2.5);
    Courier courier("Alice Brown", 301, &deliveryCar);
    EXPECT_EQ(courier.getEmployeeInfo(), "Employee: Alice Brown, ID: 301, Position: Courier, Vehicle: Car");
}

TEST(CourierTest, DeliverMailTest) {
    Car deliveryCar(500.0, 220.0, 2.5);
    Courier courier("Alice Brown", 301, &deliveryCar);
    Mail myMail("Important document", "123456", "2024-11-01", "2024-11-05", nullptr, nullptr);

    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());

    courier.deliverMail(myMail);

    std::cout.rdbuf(prevCoutBuf);

    std::string expectedOutput = "Delivering mail with tracking number 123456 using Car.\n"
        "Mail with tracking number 123456 delivered.\n"
        "Mail delivered.\n";

    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(CourierTest, CheckVehicleCapacityTest) {
    Car deliveryCar(500.0, 220.0, 2.5);
    Courier courier("Alice Brown", 301, &deliveryCar);

    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());

    courier.checkVehicleCapacity();

    std::cout.rdbuf(prevCoutBuf);

    std::string expectedOutput = "Checking the technical condition of the vehicle with a load capacity of: 500 kg.\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}
