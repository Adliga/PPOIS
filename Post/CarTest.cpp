#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Car.cpp"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Vehicle.cpp"
#include <sstream>
#include <iostream>

TEST(CarTest, CheckCapacityStatusTest) {
    Car myCar(500.0, 220.0, 2.5);
    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    myCar.checkCapacityStatus();
    std::cout.rdbuf(prevCoutBuf);
    std::string expectedOutput = "Checking the technical condition of the vehicle with a load capacity of: 500 kg.\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(CarTest, GetVehicleTypeTest) {
    Car myCar(500.0, 220.0, 2.5);
    EXPECT_EQ(myCar.getVehicleType(), "Car");
}
