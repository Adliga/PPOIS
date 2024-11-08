#include "Payment.h"

Payment::Payment(double amt, const std::string& method)
    : amount(amt), paymentMethod(method), isProcessed(false) {}

void Payment::processPayment(Mail& mail) {
    if (!isProcessed) {
        isProcessed = true;
        mail.markAsPaid(); 
        std::cout << "Processed payment of " << amount << " via " << paymentMethod
            << " for mail " << mail.getTrackingNumber() << std::endl;
    }
    else {
        std::cout << "Payment has already been processed." << std::endl;
    }
}

double Payment::getAmount() const { 
    return amount; 
}
std::string Payment::getPaymentMethod() const { 
    return paymentMethod; 
}
bool Payment::paymentStatus() const { 
    return isProcessed; 
}
