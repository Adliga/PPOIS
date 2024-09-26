#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

class Polynomial {
private:
    std::vector<double> coefficients; // массив коэффициентов

public:
    // Конструктор с заданием массива коэффициентов
    Polynomial(const std::vector<double>& coeffs) : coefficients(coeffs) {}

    // Доступ к коэффициентам через оператор []
    double operator[](int i) const {
        if (i < 0 || i >= coefficients.size())
            throw std::out_of_range("Index out of bounds");
        return coefficients[i];
    }

    // Оператор для вычисления значения многочлена при заданном x
    double operator()(double x) const {
        double result = 0.0;
        for (int i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    // Оператор сложения многочленов
    Polynomial operator+(const Polynomial& other) const {
        std::vector<double> result_coeffs(std::max(coefficients.size(), other.coefficients.size()), 0.0);

        for (int i = 0; i < coefficients.size(); ++i) {
            result_coeffs[i] += coefficients[i];
        }

        for (int i = 0; i < other.coefficients.size(); ++i) {
            result_coeffs[i] += other.coefficients[i];
        }

        return Polynomial(result_coeffs);
    }

    // Оператор вычитания многочленов
    Polynomial operator-(const Polynomial& other) const {
        std::vector<double> result_coeffs(std::max(coefficients.size(), other.coefficients.size()), 0.0);

        for (int i = 0; i < coefficients.size(); ++i) {
            result_coeffs[i] += coefficients[i];
        }

        for (int i = 0; i < other.coefficients.size(); ++i) {
            result_coeffs[i] -= other.coefficients[i];
        }

        return Polynomial(result_coeffs);
    }

    // Оператор умножения многочленов
    Polynomial operator*(const Polynomial& other) const {
        std::vector<double> result_coeffs(coefficients.size() + other.coefficients.size() - 1, 0.0);

        for (int i = 0; i < coefficients.size(); ++i) {
            for (int j = 0; j < other.coefficients.size(); ++j) {
                result_coeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(result_coeffs);
    }

    // Оператор деления многочленов (для деления многочлена на другой многочлен)
    Polynomial operator/(const Polynomial& other) const {
        if (other.coefficients.size() == 0 || other.coefficients[0] == 0) {
            throw std::invalid_argument("Division by zero polynomial");
        }

        std::vector<double> result_coeffs(coefficients.size(), 0.0);
        std::vector<double> remainder(coefficients);

        for (int i = coefficients.size() - 1; i >= other.coefficients.size() - 1; --i) {
            result_coeffs[i - (other.coefficients.size() - 1)] = remainder[i] / other.coefficients.back();
            for (int j = 0; j < other.coefficients.size(); ++j) {
                remainder[i - j] -= result_coeffs[i - (other.coefficients.size() - 1)] * other.coefficients[other.coefficients.size() - 1 - j];
            }
        }

        return Polynomial(result_coeffs);
    }

    // Оператор += для сложения
    Polynomial& operator+=(const Polynomial& other) {
        *this = *this + other;
        return *this;
    }

    // Оператор -= для вычитания
    Polynomial& operator-=(const Polynomial& other) {
        *this = *this - other;
        return *this;
    }

    // Оператор *= для умножения
    Polynomial& operator*=(const Polynomial& other) {
        *this = *this * other;
        return *this;
    }

    // Оператор /= для деления
    Polynomial& operator/=(const Polynomial& other) {
        *this = *this / other;
        return *this;
    }

    // Вывод многочлена
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
        for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
            if (poly.coefficients[i] != 0) {
                os << (poly.coefficients[i] > 0 && i != poly.coefficients.size() - 1 ? "+" : "") << poly.coefficients[i];
                if (i > 0) os << "x^" << i << " ";
            }
        }
        return os;
    }
};

// Функция для чтения многочлена от пользователя
Polynomial readPolynomial() {
    int degree;
    std::cout << "Введите степень многочлена: ";
    std::cin >> degree;

    std::vector<double> coeffs(degree + 1);
    std::cout << "Введите коэффициенты многочлена (от свободного члена до старшего коэффициента):\n";
    for (int i = 0; i <= degree; ++i) {
        std::cin >> coeffs[i];
    }

    return Polynomial(coeffs);
}

// Главное меню программы
int main() {
    setlocale(0, "");
    Polynomial p1 = readPolynomial();
    Polynomial p2 = readPolynomial();

    std::cout << p1 << '\n';
    std::cout << p2 << '\n';

    int choice;

    do {
        std::cout << "\nВыберите операцию:\n";
        std::cout << "1. Сложение\n";
        std::cout << "2. Вычитание\n";
        std::cout << "3. Умножение\n";
        std::cout << "4. Деление\n";
        std::cout << "5. Вычисление значений многочленов\n";
        std::cout << "6. Вычисление значения многочлена для заданного аргумента\n";
        std::cout << "7. Выйти из программы\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Polynomial result = p1 + p2;
            std::cout << "Результат сложения: " << result << std::endl;
            break;
        }
        case 2: {
            Polynomial result = p1 - p2;
            std::cout << "Результат вычитания: " << result << std::endl;
            break;
        }
        case 3: {
            Polynomial result = p1 * p2;
            std::cout << "Результат умножения: " << result << std::endl;
            break;
        }
        case 4: {
            try {
                Polynomial result = p1 / p2;
                std::cout << "Результат деления: " << result << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            double x;
            std::cout << "Введите значение x: ";
            std::cin >> x;
            std::cout << "p1(" << x << ") = " << p1(x) << std::endl;
            std::cout << "p2(" << x << ") = " << p2(x) << std::endl;
            break;
        }
        case 7:
            std::cout << "Программа завершена.\n";
            break;
        default:
            std::cout << "Неверный выбор." << std::endl;
            break;
        }

    } while (choice != 7);

    return 0;
}
