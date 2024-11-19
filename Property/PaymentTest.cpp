#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Payment.cpp"

TEST(PaymentTest, SetAmount) {
    Payment payment("PAY123");

    payment.setAmount(100.0);
    EXPECT_DOUBLE_EQ(payment.getAmount(), 100.0);

    testing::internal::CaptureStdout();
    payment.setAmount(-50.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Payment amount cannot be negative!"), std::string::npos);
}

TEST(PaymentTest, ProcessPaymentForPropertySuccess) {
    Property property(true, 1000, "123 Main St", "House"); 
    Payment payment("PAY123");

    EXPECT_TRUE(payment.processPayment(1000.0, &property));
    EXPECT_DOUBLE_EQ(payment.getAmount(), 1000.0);
    EXPECT_FALSE(property.getIsAvailable());  
}

TEST(PaymentTest, ProcessPaymentForPropertyFailureAmountMismatch) {
    Property property(true, 1000, "123 Main St", "House"); 
    Payment payment("PAY123");

    testing::internal::CaptureStdout();
    EXPECT_FALSE(payment.processPayment(500.0, &property));
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Payment amount does not match the property cost!"), std::string::npos);
}

TEST(PaymentTest, ProcessPaymentForPropertyFailurePropertyUnavailable) {
    Property property(true, 100.0, "123 Main St", "Apartment");
    Payment payment("PAY123");

    property.setIsAvailable(false);

    testing::internal::CaptureStdout();
    EXPECT_FALSE(payment.processPayment(100.0, &property));  
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Property is not available for rent!"), std::string::npos);
}


TEST(PaymentTest, ProcessPaymentForServiceSuccess) {
    Service service("Internet Connection", 50.0); 
    Payment payment("PAY123");

    EXPECT_TRUE(payment.processPayment(50.0, &service));
    EXPECT_DOUBLE_EQ(payment.getAmount(), 50.0);
}

TEST(PaymentTest, ProcessPaymentForServiceFailureAmountMismatch) {
    Service service("Internet Connection", 50.0);  
    Payment payment("PAY123");

    testing::internal::CaptureStdout();
    EXPECT_FALSE(payment.processPayment(30.0, &service));
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Payment amount does not match the service cost!"), std::string::npos);
}

