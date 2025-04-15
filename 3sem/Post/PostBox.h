#pragma once

#ifndef POSTBOX_H
#define POSTBOX_H

#include <iostream>
#include <string>
#include "Mail.h" 

class Mail;

class PostBox {
private:
    std::string location;
    int number;
    bool hasPackage;

public:
    PostBox(const std::string& loc, int num, bool packageStatus);

    std::string getLocation() const;
    bool getBoxStatus() const;
    int getNumber() const;
};
#endif