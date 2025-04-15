#include "Payment.h"

Payment::Payment(const std::string& paymentID)
    : paymentID(paymentID), amount(0), property(nullptr), service(nullptr) {}

double Payment::getAmount() const {
    return amount;
}

void Payment::setAmount(double newAmount) {
    if (newAmount < 0) {
        std::cout << "Payment amount cannot be negative!" << std::endl;
        return;
    }
    amount = newAmount;
}

bool Payment::processPayment(double paymentAmount, Property* property) {
    if (!property) {
        std::cout << "Property is null!" << std::endl;
        return false;
    }

    if (!property->getIsAvailable()) {
        std::cout << "Property is not available for rent!" << std::endl;
        return false;
    }

    if (paymentAmount == property->getCost()) {
        setAmount(paymentAmount);
        this->property = property;
        property->setIsAvailable(false);
        std::cout << "Payment successful for property rental!" << std::endl;
        property->displayPropertyInfo();
        return true;
    }
    else {
        std::cout << "Payment amount does not match the property cost!" << std::endl;
        return false;
    }
}

bool Payment::processPayment(double paymentAmount, Service* service) {
    if (!service) {
        std::cout << "Service is null!" << std::endl;
        return false;
    }

    if (paymentAmount == service->getServiceCost()) {
        setAmount(paymentAmount);
        this->service = service;
        std::cout << "Payment successful for service!" << std::endl;
        service->displayServiceInfo();
        return true;
    }
    else {
        std::cout << "Payment amount does not match the service cost!" << std::endl;
        return false;
    }
}