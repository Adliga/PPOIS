#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Announcement.cpp"
#include "D:\Study\VisualStudio\PPOIS3\PPOIS3\Website.cpp"

TEST(WebsiteTest, GetURL) {
    Website website("https://example.com");

    EXPECT_EQ(website.getURL(), "https://example.com");
}

TEST(WebsiteTest, AddAnnouncement) {
    Website website("https://example.com");
    Property* property = new Property(true, 1500, "123 Main St", "Apartment");
    Landlord* landlord = new Landlord("Alice", "alice@example.com");
    Announcement* announcement = new Announcement(property, landlord, "Spacious apartment for rent.");

    testing::internal::CaptureStdout();

    website.addAnnouncement(announcement);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Announcement added"), std::string::npos);
}

TEST(WebsiteTest, ViewAnnouncements) {
    Website website("https://example.com");
    Property* property1 = new Property(true, 1500, "123 Main St", "Apartment");
    Landlord* landlord1 = new Landlord("Alice", "alice@example.com");
    Announcement* announcement1 = new Announcement(property1, landlord1, "Spacious apartment for rent.");

    Property* property2 = new Property(true, 2000, "456 Oak St", "House");
    Landlord* landlord2 = new Landlord("Bob", "bob@example.com");
    Announcement* announcement2 = new Announcement(property2, landlord2, "Beautiful house with a garden.");

    website.addAnnouncement(announcement1);
    website.addAnnouncement(announcement2);

    testing::internal::CaptureStdout();

    website.viewAnnouncements();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("List of Announcements:"), std::string::npos);
    EXPECT_NE(output.find("Spacious apartment for rent."), std::string::npos);
    EXPECT_NE(output.find("Beautiful house with a garden."), std::string::npos);
}

TEST(WebsiteTest, AddUser) {
    Website website("https://example.com");
    User* user = new User("John Doe", "john.doe@example.com", "Admin");

    testing::internal::CaptureStdout();

    website.addUser(user);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("User added"), std::string::npos);
}

TEST(WebsiteTest, ViewUsers) {
    Website website("https://example.com");
    User* user1 = new User("John Doe", "john.doe@example.com", "Admin");
    User* user2 = new User("Jane Smith", "jane.smith@example.com", "Member");

    website.addUser(user1);
    website.addUser(user2);

    testing::internal::CaptureStdout();

    website.viewUsers();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("List of Users:"), std::string::npos);
    EXPECT_NE(output.find("John Doe"), std::string::npos);
    EXPECT_NE(output.find("Jane Smith"), std::string::npos);
}