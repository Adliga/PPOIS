#include "Announcement.h"

Announcement::Announcement(Property* property, Landlord* landlord, const std::string& description)
    : property(property), landlord(landlord), description(description) {}

void Announcement::displayAnnouncementInfo() const {
    std::cout << "=== Announcement ===\n";
    std::cout << "Description: " << description << "\n";

    std::cout << "\n--- Property Info ---\n";
    if (property) {
        property->displayPropertyInfo();
    }
    else {
        std::cout << "No property available!" << std::endl;
    }

    std::cout << "\n--- Landlord Info ---\n";
    if (landlord) {
        landlord->displayUserInfo();
    }
    else {
        std::cout << "No landlord information available!" << std::endl;
    }

    std::cout << "=====================" << std::endl;
}
