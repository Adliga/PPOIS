#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\PropertyManager.cpp"

TEST(PropertyManagerTest, ArrangeAgreementAddsValidAgreement) {
    PropertyManager manager("John Doe", "john.doe@example.com");

    Tenant tenant("Alice", "alice@example.com");
    Landlord landlord("Bob", "bob@example.com");
    Property property(true, 1200.0, "123 Main St", "Apartment");
    LeaseAgreement agreement(&tenant, &landlord, &property, "2024-01-01", "2024-12-31");

    manager.arrangeAgreement(&agreement);

    testing::internal::CaptureStdout();
    manager.getArrangedAgreements();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Lease Agreement Details"), std::string::npos);
    EXPECT_NE(output.find("123 Main St"), std::string::npos);
    EXPECT_NE(output.find("Alice"), std::string::npos);
    EXPECT_NE(output.find("Bob"), std::string::npos);
}

TEST(PropertyManagerTest, ArrangeAgreementHandlesNull) {
    PropertyManager manager("John Doe", "john.doe@example.com");

    testing::internal::CaptureStdout();
    manager.arrangeAgreement(nullptr);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Error: Attempted to add a null agreement"), std::string::npos);
}
