#pragma once

#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <iostream>
#include "Mail.h"

class Payment {
private:
    double amount;
    std::string paymentMethod;
    bool isProcessed;

public:
    Payment(double amt, const std::string& method);
    void processPayment(Mail& mail);
    double getAmount() const;
    std::string getPaymentMethod() const;
    bool paymentStatus() const;
};

#endif 

