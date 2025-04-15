#pragma once 

#ifndef SENDER_H
#define SENDER_H

#include <iostream>
#include <string>
#include "Mail.h"  
#include "Stamp.h" 
#include "PostBox.h" 

class Mail;
class PostBox;

class Sender {
private:
    std::string name;
    std::string address;
    std::string phone;

public:
    Sender(const std::string& senderName, const std::string& addr, const std::string& ph);
  
    std::string getName() const;
    std::string getAddress() const;

    void attachStampToMail(Mail& mail, Stamp* stamp);
    void placeMailInPostBox(Mail& mail, PostBox& postBox);
};

#endif 