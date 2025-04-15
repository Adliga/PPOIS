#include "Website.h"

Website::Website(const std::string& URL) : URL(URL) {}

std::string Website::getURL() const {
    return URL;
}

void Website::addAnnouncement(Announcement* newAnnouncement) {
    if (newAnnouncement) {
        announcements.push_back(newAnnouncement);
        std::cout << "Announcement added\n";
    }
    else {
        std::cout << "Error: Attempted to add a null announcement!" << std::endl;
    }
}

void Website::viewAnnouncements() const {
    std::cout << "List of Announcements:\n";
    for (const auto& announcement : announcements) {
        if (announcement) {
            announcement->displayAnnouncementInfo();
            std::cout << std::endl;
        }
    }
}

void Website::addUser(User* newUser) {
    if (newUser) {
        users.push_back(newUser);
        std::cout << "User added\n";
    }
    else {
        std::cout << "Error: Attempted to add a null user!" << std::endl;
    }
}

void Website::viewUsers() const {
    std::cout << "List of Users:\n";
    for (const auto& user : users) {
        if (user) {
            user->displayUserInfo();
            std::cout << std::endl;
        }
    }
}
