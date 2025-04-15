#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\Letter.cpp"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\Sender.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\Recipient.h"

TEST(LetterTest, ConstructorTest) {
    Sender sender("John Doe", "123 Street", "555-1234");
    Recipient recipient("Jane Smith", "456 Avenue", "555-5678");
    Letter letter("Important Document", "TRACK67890", "01-02-2024", "05-02-2024", &sender, &recipient);

    EXPECT_EQ(letter.getContent(), "Important Document");
    EXPECT_EQ(letter.getTrackingNumber(), "TRACK67890");
}
