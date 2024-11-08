#pragma once

#ifndef MAIL_H
#define MAIL_H

#include <string>
#include "Sender.h"
#include "Recipient.h"

class Sender;
class Recipient;

class Mail {
protected:
    std::string content;
    std::string trackingNumber;
    std::string sendDate;
    std::string deliveryDate;
    Sender* sender;
    Recipient* recipient;
    bool delivered;
    bool isPaid;

public:
    Mail(const std::string& content, const std::string& trackNum, const std::string& send, const std::string& delivery,
        Sender* sender, Recipient* recipient);

    virtual ~Mail() = default;

    std::string getTrackingNumber() const;
    std::string getContent() const;
    bool getIsPaid() const;

    void markAsDelivered();
    void markAsPaid();
};

#endif 