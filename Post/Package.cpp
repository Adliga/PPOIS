#include "Package.h"

Package::Package(const std::string& cont, const std::string& trackNum, const std::string& send, const std::string& delivery,
    Sender* sender, Recipient* recipient, double weight, const std::string& dimensions)
    : Mail(cont, trackNum, send, delivery, sender, recipient), weight(weight), dimensions(dimensions) {}

double Package::getWeight() const {
    return weight;
}

std::string Package::getDimensions() const {
    return dimensions;
}
