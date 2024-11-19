#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Request.cpp"

TEST(RequestTest, GetRequestID) {
    Request request("REQ123", "2024-11-19", "Pending");

    EXPECT_EQ(request.getRequestID(), "REQ123");
}

TEST(RequestTest, GetRequestDate) {
    Request request("REQ123", "2024-11-19", "Pending");

    EXPECT_EQ(request.getRequestDate(), "2024-11-19");
}

TEST(RequestTest, GetStatus) {
    Request request("REQ123", "2024-11-19", "Pending");

    EXPECT_EQ(request.getStatus(), "Pending");
}

TEST(RequestTest, SetStatus) {
    Request request("REQ123", "2024-11-19", "Pending");

    request.setStatus("Completed");

    EXPECT_EQ(request.getStatus(), "Completed");
}

TEST(RequestTest, DisplayRequestInfo) {
    Request request("REQ123", "2024-11-19", "Pending");

    testing::internal::CaptureStdout();

    request.displayRequestInfo();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Request ID: REQ123"), std::string::npos);
    EXPECT_NE(output.find("Request date: 2024-11-19"), std::string::npos);
    EXPECT_NE(output.find("Request status: Pending"), std::string::npos);
}