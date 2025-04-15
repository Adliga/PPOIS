#include "Mail.h"

Mail::Mail(const std::string& content, const std::string& trackNum, const std::string& send, const std::string& delivery,
    Sender* sender, Recipient* recipient)
    : content(content), trackingNumber(trackNum), sendDate(send), deliveryDate(delivery), sender(sender),
    recipient(recipient), delivered(false), isPaid(false) {} 

std::string Mail::getTrackingNumber() const {
    return trackingNumber;
}

std::string Mail::getContent() const {
    return content;
}

bool Mail::getIsPaid() const {
    return isPaid; 
}

void Mail::markAsDelivered() {
    delivered = true;
    std::cout << "Mail with tracking number " << trackingNumber << " delivered.\n";
}

void Mail::markAsPaid() {
    isPaid = true;
}
