#pragma once
#ifndef PAYMENT_H
#define PAYMENT_H

#include "Property.h"
#include "Service.h"

class Payment {
private:
    std::string paymentID;
    double amount;
    Property* property;
    Service* service;

public:
    Payment(const std::string& paymentID);

    double getAmount() const;
    void setAmount(double newAmount);

    bool processPayment(double paymentAmount, Property* property);
    bool processPayment(double paymentAmount, Service* service);
};

#endif
