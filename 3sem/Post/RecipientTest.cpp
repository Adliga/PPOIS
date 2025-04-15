#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Recipient.cpp"
#include <sstream>

TEST(RecipientTest, AcceptMailTest) {
    Mail myMail("Birthday gift", "123789", "2024-11-01", "2024-11-05", nullptr, nullptr);
    Recipient myRecipient("Alice Johnson", "789 Maple St", "555-8765");
    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    myRecipient.acceptMail(myMail);
    std::cout.rdbuf(prevCoutBuf);
    std::string expectedOutput = "Recipient Alice Johnson accepted the mail with content: Birthday gift\nMail with tracking number 123789 delivered.\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}


TEST(RecipientTest, CollectMailFromBoxTest) {
    Mail myMail("Christmas presents", "987654", "2024-12-01", "2024-12-05", nullptr, nullptr);
    PostBox myPostBox("Uptown", 202, true);
    Recipient myRecipient("Bob Smith", "123 Pine St", "555-2345");

    std::stringstream buffer;
    std::streambuf* prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());

    myRecipient.collectMailFromBox(myPostBox, myMail);

    std::cout.rdbuf(prevCoutBuf);

    std::string expectedOutput = "Recipient Bob Smith collected the mail with content: Christmas presents from mailbox No. 202.\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(RecipientTest, GetAdressTest) {
    Recipient myRecipient("Alice Johnson", "789 Maple St", "555-8765");
    EXPECT_EQ(myRecipient.getAddress(), "789 Maple St");
}
