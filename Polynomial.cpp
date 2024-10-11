#include "Polynomial.h"

Polynomial::Polynomial(const std::vector<double>& coeffs) : coefficients(coeffs) {}

double Polynomial::operator[](int i) const {
    if (i < 0 || i >= coefficients.size())
        throw std::out_of_range("Index out of bounds");
    return coefficients[i];
}

double Polynomial::operator()(double x) const {
    double result = 0;
    for (int i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    std::vector<double> result_coeffs(std::max(coefficients.size(), other.coefficients.size()), 0);

    for (int i = 0; i < coefficients.size(); ++i) {
        result_coeffs[i] += coefficients[i];
    }

    for (int i = 0; i < other.coefficients.size(); ++i) {
        result_coeffs[i] += other.coefficients[i];
    }

    return Polynomial(result_coeffs);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    std::vector<double> result_coeffs(std::max(coefficients.size(), other.coefficients.size()), 0);

    for (int i = 0; i < coefficients.size(); ++i) {
        result_coeffs[i] += coefficients[i];
    }

    for (int i = 0; i < other.coefficients.size(); ++i) {
        result_coeffs[i] -= other.coefficients[i];
    }

    return Polynomial(result_coeffs);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    std::vector<double> result_coeffs(coefficients.size() + other.coefficients.size() - 1, 0);

    for (int i = 0; i < coefficients.size(); ++i) {
        for (int j = 0; j < other.coefficients.size(); ++j) {
            result_coeffs[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    return Polynomial(result_coeffs);
}

Polynomial Polynomial::operator/(const Polynomial& other) const {
    if (other.coefficients.size() == 0 || other.coefficients[0] == 0) {
        throw std::invalid_argument("Division by zero");
    }
    std::vector<double> result_coeffs(coefficients.size(), 0);
    std::vector<double> remainder(coefficients);

    for (int i = coefficients.size() - 1; i >= other.coefficients.size() - 1; --i) {
        result_coeffs[i - (other.coefficients.size() - 1)] = remainder[i] / other.coefficients.back();
        for (int j = 0; j < other.coefficients.size(); ++j) {
            remainder[i - j] -= result_coeffs[i - (other.coefficients.size() - 1)] * other.coefficients[other.coefficients.size() - 1 - j];
        }
    }

    return Polynomial(result_coeffs);
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    *this = *this * other;
    return *this;
}

Polynomial& Polynomial::operator/=(const Polynomial& other) {
    if (other.coefficients.size() == 0 || other.coefficients[0] == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (other.coefficients.size() == 1) {
        for (auto& coeff : coefficients) {
            coeff /= other.coefficients[0];
        }
    }
    else {
        std::vector<double> result_coeffs(coefficients.size(), 0);
        std::vector<double> remainder(coefficients);

        for (int i = coefficients.size() - 1; i >= other.coefficients.size() - 1; --i) {
            result_coeffs[i - (other.coefficients.size() - 1)] = remainder[i] / other.coefficients.back();
            for (int j = 0; j < other.coefficients.size(); ++j) {
                remainder[i - j] -= result_coeffs[i - (other.coefficients.size() - 1)] * other.coefficients[other.coefficients.size() - 1 - j];
            }
        }

        coefficients = result_coeffs;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    bool first = true;
    for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
        if (poly.coefficients[i] != 0) {
            if (!first && poly.coefficients[i] > 0) {
                os << "+ ";
            }
            os << poly.coefficients[i];
            if (i > 0) os << "x^" << i << " ";
            first = false; 
        }
    }
    return os;
}


