#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\Package.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\Sender.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F\Recipient.h"

TEST(PackageTest, ConstructorTest) {
    Sender sender("John Doe", "123 Main St", "555-1234");
    Recipient recipient("Jane Smith", "456 Oak St", "555-5678");

    Package package("Books", "TRACK12345", "01-12-2024", "05-12-2024", &sender, &recipient, 2.5, "30x20x10");

    EXPECT_EQ(package.getContent(), "Books");
    EXPECT_EQ(package.getTrackingNumber(), "TRACK12345");
    EXPECT_EQ(package.getIsPaid(), false); 

    EXPECT_EQ(package.getWeight(), 2.5);
    EXPECT_EQ(package.getDimensions(), "30x20x10");
}
