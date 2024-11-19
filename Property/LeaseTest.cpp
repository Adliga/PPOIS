#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\LeaseAgreement.cpp"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Landlord.cpp"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Apartment.cpp"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Tenant.cpp"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\User.cpp"

TEST(LeaseAgreementTest, DisplayAgreementInfo) {
    Property* property = new Apartment(true, 1000, "789 Pine St", 2, 3);  
    Landlord* landlord = new Landlord("John Doe", "johndoe@example.com");
    Tenant* tenant = new Tenant("Jane Smith", "janesmith@example.com");

    LeaseAgreement lease(tenant, landlord, property, "2024-01-01", "2024-12-31");

    testing::internal::CaptureStdout();

    lease.displayAgreementInfo();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Lease Agreement Details:"), std::string::npos);
    EXPECT_NE(output.find("Property Info:"), std::string::npos);
    EXPECT_NE(output.find("789 Pine St"), std::string::npos);  
    EXPECT_NE(output.find("Landlord Info:"), std::string::npos);
    EXPECT_NE(output.find("John Doe"), std::string::npos);  
    EXPECT_NE(output.find("Tenant Info:"), std::string::npos);
    EXPECT_NE(output.find("Jane Smith"), std::string::npos); 
    EXPECT_NE(output.find("Lease Start Date: 2024-01-01"), std::string::npos);
    EXPECT_NE(output.find("Lease End Date: 2024-12-31"), std::string::npos);
}
