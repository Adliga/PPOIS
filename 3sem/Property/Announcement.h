#pragma once
#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include <iostream>
#include <string>
#include "Property.h"
#include "Landlord.h"

class Announcement {
private:
    Property* property;
    Landlord* landlord;
    std::string description;

public:
    Announcement(Property* property, Landlord* landlord, const std::string& description);

    void displayAnnouncementInfo() const;
};

#endif 
