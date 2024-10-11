#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <sstream>

class Polynomial {
private:
    std::vector<double> coefficients; 

public:

    Polynomial(const std::vector<double>& coeffs); 

    double operator[](int i) const; 

    double operator()(double x) const;

    Polynomial operator+(const Polynomial& other) const;

    Polynomial operator-(const Polynomial& other) const;

    Polynomial operator*(const Polynomial& other) const;

    Polynomial operator/(const Polynomial& other) const;

    Polynomial& operator+=(const Polynomial& other);

    Polynomial& operator-=(const Polynomial& other);

    Polynomial& operator*=(const Polynomial& other);

    Polynomial& operator/=(const Polynomial& other);

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
};

#endif 
