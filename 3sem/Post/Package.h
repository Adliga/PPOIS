#pragma once

#ifndef PACKAGE_H
#define PACKAGE_H

#include "Mail.h"

class Package : public Mail {
private:
    double weight;
    std::string dimensions;

public:
    Package(const std::string& cont, const std::string& trackNum, const std::string& send, const std::string& delivery,
        Sender* sender, Recipient* recipient, double weight, const std::string& dimensions);

    double getWeight() const;
    std::string getDimensions() const;
};

#endif 

