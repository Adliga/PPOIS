#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Sender.cpp"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Mail.cpp"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/PostBox.cpp"
#include <sstream>

TEST(SenderTest, AttachStampToMailTest) {
    Mail myMail("Important document", "123456", "2024-11-01", "2024-11-05", nullptr, nullptr);
    Stamp myStamp("Holiday Theme", 3.0);
    Sender mySender("John Doe", "123 Main St", "555-1234");

    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());

    mySender.attachStampToMail(myMail, &myStamp);

    std::cout.rdbuf(prevCoutBuf);

    std::string expectedOutput = "Stamp with design 'Holiday Theme' has been attached to the mail with tracking number 123456.\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(SenderTest, PlaceMailInPostBoxTest) {
    Mail myMail("Greeting card", "654321", "2024-11-01", "2024-11-05", nullptr, nullptr);
    PostBox myPostBox("Downtown", 101, true);
    Sender mySender("Jane Smith", "456 Oak St", "555-5678");

    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());

    mySender.placeMailInPostBox(myMail, myPostBox);

    std::cout.rdbuf(prevCoutBuf);

    std::string expectedOutput = "Sender Jane Smith placed a mail with content: Greeting card in the mailbox at location Downtown.\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}
TEST(SenderTest, GetAddressTest) {
    Sender mySender("John Doe", "123 Oak St", "555-1234");
    EXPECT_EQ(mySender.getAddress(), "123 Oak St");
}
