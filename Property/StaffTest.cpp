#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\SupportStaff.h"

TEST(SupportStaffTest, AssignRequestAddsValidRequest) {
    SupportStaff staff("Jane Doe", "jane.doe@example.com");
    Request request("REQ123", "2023-11-01", "Pending");

    testing::internal::CaptureStdout();
    staff.assignRequest(&request);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Request added: Request ID: REQ123"), std::string::npos);
    EXPECT_NE(output.find("Request date: 2023-11-01"), std::string::npos);
    EXPECT_NE(output.find("Request status: Pending"), std::string::npos);
}

TEST(SupportStaffTest, AssignRequestHandlesNullRequest) {
    SupportStaff staff("Jane Doe", "jane.doe@example.com");

    testing::internal::CaptureStdout();
    staff.assignRequest(nullptr);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Error: Attempted to add a null request!"), std::string::npos);
}

TEST(SupportStaffTest, GetRequestsDisplaysAllRequests) {
    SupportStaff staff("Jane Doe", "jane.doe@example.com");
    Request request1("REQ123", "2023-11-01", "Pending");
    Request request2("REQ124", "2023-11-02", "Processed");

    staff.assignRequest(&request1);
    staff.assignRequest(&request2);

    testing::internal::CaptureStdout();
    staff.getRequests();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Request ID: REQ123"), std::string::npos);
    EXPECT_NE(output.find("Request date: 2023-11-01"), std::string::npos);
    EXPECT_NE(output.find("Request status: Pending"), std::string::npos);
    EXPECT_NE(output.find("Request ID: REQ124"), std::string::npos);
    EXPECT_NE(output.find("Request date: 2023-11-02"), std::string::npos);
    EXPECT_NE(output.find("Request status: Processed"), std::string::npos);
}

TEST(SupportStaffTest, CompleteRequestUpdatesStatus) {
    SupportStaff staff("Jane Doe", "jane.doe@example.com");
    Request request("REQ123", "2023-11-01", "Processed");

    staff.assignRequest(&request);

    testing::internal::CaptureStdout();
    staff.completeRequest("REQ123");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(request.getStatus(), "Completed");
    EXPECT_NE(output.find("Request REQ123 has been completed."), std::string::npos);
}

TEST(SupportStaffTest, CompleteRequestHandlesUnprocessedRequest) {
    SupportStaff staff("Jane Doe", "jane.doe@example.com");
    Request request("REQ123", "2023-11-01", "Pending");

    staff.assignRequest(&request);

    testing::internal::CaptureStdout();
    staff.completeRequest("REQ123");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(request.getStatus(), "Pending");
    EXPECT_NE(output.find("Request REQ123 is already Pending."), std::string::npos);
}

TEST(SupportStaffTest, CompleteRequestHandlesInvalidRequestID) {
    SupportStaff staff("Jane Doe", "jane.doe@example.com");

    testing::internal::CaptureStdout();
    staff.completeRequest("REQ999");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Request with ID REQ999 not found."), std::string::npos);
}
