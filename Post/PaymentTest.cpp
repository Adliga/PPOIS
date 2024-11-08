#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\Payment.cpp"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\Package.cpp"
#include <sstream>

//TEST(PaymentTest, ProcessPaymentTest) {
//    Payment payment(150.0, "Credit Card");
//    Package mail("Books", "TRACK12345", "01-12-2024", "05-12-2024", nullptr, nullptr, 2.5, "30x20x10");
//
//    std::stringstream buffer;
//    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
//
//    payment.processPayment(mail);
//
//    std::cout.rdbuf(prevCoutBuf);
//
//    std::string expectedOutput = "Processed payment of 150 via Credit Card for mail 123ABC\n";
//    EXPECT_EQ(buffer.str(), expectedOutput);
//    EXPECT_TRUE(mail.isPaid());
//    EXPECT_TRUE(payment.paymentStatus());
//}
//
//TEST(PaymentTest, ProcessPaymentAlreadyProcessedTest) {
//    Payment payment(100.0, "Cash");
//    Package mail("Books", "TRACK12345", "01-12-2024", "05-12-2024", nullptr, nullptr, 2.5, "30x20x10");
//
//    payment.processPayment(mail);
//
//    std::stringstream buffer;
//    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
//
//    payment.processPayment(mail);
//
//    std::cout.rdbuf(prevCoutBuf);
//
//    std::string expectedOutput = "Payment has already been processed.\n";
//    EXPECT_EQ(buffer.str(), expectedOutput);
//}
//
TEST(PaymentTest, GetAmountTest) {
    Payment payment(200.0, "Bank Transfer");
    EXPECT_EQ(payment.getAmount(), 200.0);
}

TEST(PaymentTest, GetPaymentMethodTest) {
    Payment payment(75.5, "Online Payment");
    EXPECT_EQ(payment.getPaymentMethod(), "Online Payment");
}
//
//TEST(PaymentTest, PaymentStatusTest) {
//    Payment payment(120.0, "Debit Card");
//    EXPECT_FALSE(payment.paymentStatus());
//
//    Package mail("Books", "TRACK12345", "01-12-2024", "05-12-2024", nullptr, nullptr, 2.5, "30x20x10");
//    payment.processPayment(mail);
//
//    EXPECT_TRUE(payment.paymentStatus());
//}

TEST(PaymentTest, ProcessPaymentTest) {
    Payment payment(150.0, "Credit Card");
    Mail mail("Books", "TRACK12345", "01-12-2024", "05-12-2024", nullptr, nullptr);

    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());  // Перехват вывода в строковый поток

    payment.processPayment(mail);  // Обработка платежа

    std::cout.rdbuf(prevCoutBuf);  // Восстановление стандартного потока вывода

    std::string expectedOutput = "Processed payment of 150 via Credit Card for mail TRACK12345\n";
    EXPECT_EQ(buffer.str(), expectedOutput);  // Проверка правильности вывода
    EXPECT_TRUE(mail.getIsPaid());  // Проверка, что платеж был выполнен
    EXPECT_TRUE(payment.paymentStatus());  // Проверка, что платеж был обработан
}

TEST(PaymentTest, ProcessPaymentTwiceTest) {
    Payment payment(150.0, "Credit Card");
    Mail mail("Books", "TRACK12345", "01-12-2024", "05-12-2024", nullptr, nullptr);

    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());  // Перехват вывода в строковый поток

    payment.processPayment(mail);  // Первый вызов метода processPayment

    // Пытаемся обработать платеж снова
    payment.processPayment(mail);

    std::cout.rdbuf(prevCoutBuf);  // Восстановление стандартного потока вывода

    std::string expectedOutput = "Processed payment of 150 via Credit Card for mail TRACK12345\nPayment has already been processed.\n";
    EXPECT_EQ(buffer.str(), expectedOutput);  // Проверка правильности вывода
    EXPECT_TRUE(mail.getIsPaid());  // Проверка, что платеж был выполнен
    EXPECT_TRUE(payment.paymentStatus());  // Проверка, что платеж был обработан
}