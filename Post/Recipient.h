#pragma once 

#ifndef RECIPIENT_H
#define RECIPIENT_H

#include <string>
#include "Mail.h" 
#include "PostBox.h" 

class Mail;

class Recipient {
private:
    std::string name;
    std::string address;
    std::string phone;

public:
    Recipient(const std::string& recipientName, const std::string& addr, const std::string& ph);
   
    std::string getName() const;
    std::string getAddress() const;
  
    void acceptMail(Mail& mail);
    void collectMailFromBox(PostBox& postBox, Mail& mail);
};

#endif 