#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS2F\PPOIS2F/Stamp.cpp"
#include <sstream>

TEST(StampTest, GetDesignTest) {
    Stamp myStamp("Floral Design", 2.5);  
    EXPECT_EQ(myStamp.getDesign(), "Floral Design");
}

TEST(StampTest, GetPriceTest) {
    Stamp myStamp("Floral Design", 2.5);  
    EXPECT_DOUBLE_EQ(myStamp.getPrice(), 2.5);  
}
