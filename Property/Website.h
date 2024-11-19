#pragma once
#ifndef WEBSITE_H
#define WEBSITE_H

#include <iostream>
#include <vector>
#include <string>
#include "Announcement.h"
#include "User.h"

class Website {
private:
    std::string URL;
    std::vector<Announcement*> announcements;
    std::vector<User*> users;

public:
    Website(const std::string& URL);

    std::string getURL() const;

    void addAnnouncement(Announcement* newAnnouncement);
    void viewAnnouncements() const;

    void addUser(User* newUser);
    void viewUsers() const;
};

#endif 
