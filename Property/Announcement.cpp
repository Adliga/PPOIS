#include "Announcement.h"

Announcement::Announcement(Property* property, Landlord* landlord, const std::string& description)
    : property(property), landlord(landlord), description(description) {}

//std::string Announcement::getDescription() const {
//    return description;
//}
//
//void Announcement::displayAnnouncementInfo() const {
//    std::cout << "Announcement Description: " << description << "\n";
//
//    std::cout << "\nProperty Info: \n";
//    if (property) {
//        property->displayPropertyInfo();
//    }
//    else {
//        std::cout << "No property available!" << std::endl;
//    }
//
//    std::cout << "\nLandlord Info: \n";
//    if (landlord) {
//        landlord->displayUserInfo();
//    }
//    else {
//        std::cout << "No landlord information available!" << std::endl;
//    }
//
//    std::cout << std::endl;
//}




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
