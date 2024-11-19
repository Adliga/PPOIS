#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Company.cpp"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\SupportStaff.cpp"

TEST(CompanyTest, ConstructorInitializesFields) {
    Company company("TechCorp", "1234 Main St");

    testing::internal::CaptureStdout();
    company.displayCompanyInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Company: TechCorp"), std::string::npos);
    EXPECT_NE(output.find("Adress: 1234 Main St"), std::string::npos);
    EXPECT_NE(output.find("Site doesn't exist"), std::string::npos);
}

TEST(CompanyTest, SetWebsiteUpdatesWebsite) {
    Company company("TechCorp", "1234 Main St");
    Website site("https://techcorp.com");

    company.setWebsite(&site);

    testing::internal::CaptureStdout();
    company.displayCompanyInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Site: https://techcorp.com"), std::string::npos);
}

TEST(CompanyTest, AddEmployeePropertyManager) {
    Company company("TechCorp", "1234 Main St");
    PropertyManager manager("John Doe", "johndoe@example.com");

    testing::internal::CaptureStdout();
    company.addEmployee(&manager);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Manager added"), std::string::npos);
}

TEST(CompanyTest, AddEmployeeSupportStaff) {
    Company company("TechCorp", "1234 Main St");
    SupportStaff staff("Jane Doe", "Technician");

    testing::internal::CaptureStdout();
    company.addEmployee(&staff);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Staff added"), std::string::npos);
}

TEST(CompanyTest, AddNullPropertyManager) {
    Company company("TechCorp", "1234 Main St");

    testing::internal::CaptureStdout();
    company.addEmployee(static_cast<PropertyManager*>(nullptr));
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Error: Attempted to add a null employee!"), std::string::npos);
}

TEST(CompanyTest, AddNullSupportStaff) {
    Company company("TechCorp", "1234 Main St");

    testing::internal::CaptureStdout();
    company.addEmployee(static_cast<SupportStaff*>(nullptr));
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Error: Attempted to add a null employee!"), std::string::npos);
}