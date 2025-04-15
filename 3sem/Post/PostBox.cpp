#include "PostBox.h"

PostBox::PostBox(const std::string& loc, int num, bool packageStatus)
    : location(loc), number(num), hasPackage(packageStatus) {}

std::string PostBox::getLocation() const {
    return location;
}

bool PostBox::getBoxStatus() const {
    return hasPackage;
}

int PostBox::getNumber() const {
    return number;
}
