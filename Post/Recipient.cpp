#include "Recipient.h"

Recipient::Recipient(const std::string& recipientName, const std::string& addr, const std::string& ph)
    : name(recipientName), address(addr), phone(ph) {}

std::string Recipient::getName() const {
    return name;
}

std::string Recipient::getAddress() const {
    return address;
}

void Recipient::acceptMail(Mail& mail) {
    std::cout << "Recipient " << name << " accepted the mail with content: " << mail.getContent() << "\n";
    mail.markAsDelivered();
}

void Recipient::collectMailFromBox(PostBox& postBox, Mail& mail) {
    if (postBox.getBoxStatus()) {
        std::cout << "Recipient " << getName() << " collected the mail with content: "
            << mail.getContent() << " from mailbox No. " << postBox.getNumber() << ".\n";
    }
    else {
        std::cout << "There is no mail in mailbox No. " << postBox.getNumber() << ".\n";
    }
}
