#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Bicycle.cpp"
#include <sstream>
#include <iostream>

TEST(BicycleTest, CheckCapacityStatusTest) {
    Bicycle myBicycle(20.0, 30.0, true);
    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    myBicycle.checkCapacityStatus();
    std::cout.rdbuf(prevCoutBuf);
    std::string expectedOutput = "Checking the technical condition of the vehicle with a load capacity of: 20 kg.\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(BicycleTest, GetVehicleTypeTest) {
    Bicycle myBicycle(20.0, 30.0, true);
    EXPECT_EQ(myBicycle.getVehicleType(), "Bicycle");
}

TEST(BicycleTest, GetIsElectricTest) {
    Bicycle electricBicycle(20.0, 30.0, true);
    Bicycle nonElectricBicycle(20.0, 30.0, false);
    EXPECT_TRUE(electricBicycle.getIsElectric());
    EXPECT_FALSE(nonElectricBicycle.getIsElectric());
}

