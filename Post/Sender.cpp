#include "Sender.h"

Sender::Sender(const std::string& senderName, const std::string& addr, const std::string& ph)
    : name(senderName), address(addr), phone(ph) {}

std::string Sender::getName() const {
    return name;
}

std::string Sender::getAddress() const {
    return address;
}

void Sender::attachStampToMail(Mail& mail, Stamp* stamp) {
    std::cout << "Stamp with design '" << stamp->getDesign() << "' has been attached to the mail with tracking number "
        << mail.getTrackingNumber() << "." << std::endl;
}

void Sender::placeMailInPostBox(Mail& mail, PostBox& postBox) {
    std::cout << "Sender " << getName() << " placed a mail with content: "
        << mail.getContent() << " in the mailbox at location " << postBox.getLocation() << ".\n";
}

