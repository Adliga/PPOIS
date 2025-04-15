#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Service.cpp"

TEST(ServiceTest, GetServiceName) {
    Service service("Internet Connection", 50.0);

    EXPECT_EQ(service.getServiceName(), "Internet Connection");
}

TEST(ServiceTest, GetServiceCost) {
    Service service("Internet Connection", 50.0);

    EXPECT_DOUBLE_EQ(service.getServiceCost(), 50.0);
}

TEST(ServiceTest, DisplayServiceInfo) {
    Service service("Internet Connection", 50.0);

    testing::internal::CaptureStdout();

    service.displayServiceInfo();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Service Name: Internet Connection"), std::string::npos);
    EXPECT_NE(output.find("Service cost: 50 byn."), std::string::npos);
}