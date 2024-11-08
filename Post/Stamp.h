#pragma once 

#ifndef STAMP_H
#define STAMP_H

#include <iostream>
#include <string>

class Stamp {
private:
    std::string design;         
    double price;              

public:
    Stamp(const std::string& design, double price);

    std::string getDesign() const;
    double getPrice() const;
};
#endif