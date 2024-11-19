#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\LeaseAgreement.h"

TEST(LandlordTest, AddProperty) {
    Landlord landlord("Alice", "alice@example.com");
    Property property1(true, 1200.0, "123 Main St", "House");
    Property property2(false, 1500.0, "456 Elm St", "Office");

    landlord.addProperty(&property1);
    landlord.addProperty(&property2);

    testing::internal::CaptureStdout();
    landlord.getProperties();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("123 Main St"), std::string::npos);
    EXPECT_NE(output.find("456 Elm St"), std::string::npos);
}

TEST(LandlordTest, AddNullProperty) {
    Landlord landlord("Alice", "alice@example.com");

    testing::internal::CaptureStdout();
    landlord.addProperty(nullptr);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Error: Attempted to add a null property!"), std::string::npos);
}

TEST(TenantTest, SetLeaseAgreement) {
    Property* property = new Property(true, 1000, "789 Pine St", "House"); 
    Landlord* landlord = new Landlord("John Doe", "johndoe@example.com");
    Tenant* tenant = new Tenant("Jane Smith", "janesmith@example.com");

    LeaseAgreement lease(tenant, landlord, property, "2024-01-01", "2024-12-31");

    tenant->setLeaseAgreement(&lease);

    EXPECT_EQ(tenant->getLeaseAgreement(), &lease);
}
