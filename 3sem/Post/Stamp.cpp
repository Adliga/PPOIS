#include "Stamp.h"

Stamp::Stamp(const std::string& design, double price)
    : design(design), price(price){}

std::string Stamp::getDesign() const {
    return design; 
}
double Stamp::getPrice() const {
    return price;
}
