#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Apartment.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\House.cpp"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Office.cpp"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Property.cpp"

TEST(ApartmentTest, SetIsAvailable) {
    Apartment apartment(true, 1500, "123 Test St", 5, 3);

    ASSERT_TRUE(apartment.getIsAvailable());

    apartment.setIsAvailable(false);
    ASSERT_FALSE(apartment.getIsAvailable());

    apartment.setIsAvailable(true);
    ASSERT_TRUE(apartment.getIsAvailable());
}

TEST(ApartmentTest, ConstructorAndInheritedMethods) {
    Apartment apartment(true, 75000, "123 Main St", 5, 3);

    EXPECT_TRUE(apartment.getIsAvailable());
    EXPECT_EQ(apartment.getCost(), 75000);

    testing::internal::CaptureStdout();
    apartment.displayPropertyInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Property type: Apartment"), std::string::npos);
    EXPECT_NE(output.find("Adress: 123 Main St"), std::string::npos);
    EXPECT_NE(output.find("Cost: 75000"), std::string::npos);
    EXPECT_NE(output.find("Floor: 5"), std::string::npos);
    EXPECT_NE(output.find("Room count: 3"), std::string::npos);
}

TEST(HouseTest, ConstructorAndInheritedMethods) {
    House house(false, 200000, "456 Elm St", 500, 3);

    EXPECT_FALSE(house.getIsAvailable());
    EXPECT_EQ(house.getCost(), 200000);

    testing::internal::CaptureStdout();
    house.displayPropertyInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Property type: House"), std::string::npos);
    EXPECT_NE(output.find("Adress: 456 Elm St"), std::string::npos);
    EXPECT_NE(output.find("Cost: 200000"), std::string::npos);
    EXPECT_NE(output.find("Garden size: 500"), std::string::npos);
    EXPECT_NE(output.find("Floor count: 3"), std::string::npos);
}

TEST(OfficeTest, ConstructorAndInheritedMethods) {
    Office office(true, 120000, "789 Pine St", "Coworking");

    EXPECT_TRUE(office.getIsAvailable());
    EXPECT_EQ(office.getCost(), 120000);

    testing::internal::CaptureStdout();
    office.displayPropertyInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Property type: Office"), std::string::npos);
    EXPECT_NE(output.find("Adress: 789 Pine St"), std::string::npos);
    EXPECT_NE(output.find("Cost: 120000"), std::string::npos);
    EXPECT_NE(output.find("Office type: Coworking"), std::string::npos);
}
