#include "pch.h"
#include "gtest/gtest.h"
#include "D:\Study\VisualStudio\PPOIS1\PPOIS1/Polynomial.h"
#include "D:\Study\VisualStudio\PPOIS1\PPOIS1/Polynomial.cpp"

TEST(PolynomialTest, CoefficientAccessValidIndex) {
    std::vector<double> coeffs = {1, 7.2, 33};
   
    Polynomial p(coeffs);

    EXPECT_EQ(p[0], 1);  
    EXPECT_EQ(p[1], 7.2);  
    EXPECT_EQ(p[2], 33);  
}

TEST(PolynomialTest, CoefficientAccessInvalidIndex) {
    std::vector<double> coeffs = {1, 7.2, 33};
   
    Polynomial p(coeffs);

    EXPECT_THROW(p[3], std::out_of_range);  
    EXPECT_THROW(p[-1], std::out_of_range);
}

TEST(PolynomialTest, EvaluatePolynomial) {
    std::vector<double> coeffs = {1, 2, 3};  
  
    Polynomial p(coeffs);

    EXPECT_DOUBLE_EQ(p(0), 1);  
    EXPECT_DOUBLE_EQ(p(1), 6);  
    EXPECT_DOUBLE_EQ(p(2), 17); 
    EXPECT_DOUBLE_EQ(p(-1), 2); 
}

TEST(PolynomialTest, ZeroPolynomial) {
    std::vector<double> coeffs = {0, 0, 0};
  
    Polynomial p(coeffs);

    EXPECT_DOUBLE_EQ(p(0), 0);  
    EXPECT_DOUBLE_EQ(p(5), 0);  
    EXPECT_DOUBLE_EQ(p(-3), 0); 
}

TEST(PolynomialTest, ConstantPolynomial) {
    std::vector<double> coeffs = {7}; 
   
    Polynomial p(coeffs);

    EXPECT_DOUBLE_EQ(p(0), 7);  
    EXPECT_DOUBLE_EQ(p(1), 7);  
    EXPECT_DOUBLE_EQ(p(10), 7); 
    EXPECT_DOUBLE_EQ(p(-2), 7); 
}

TEST(PolynomialTest, Addition) {
    std::vector<double> coeffs1 = {1, 2, 3}; 
    std::vector<double> coeffs2 = {3, 4};    
    
    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);
    Polynomial result = p1 + p2;

    EXPECT_EQ(result[0], 4);  
    EXPECT_EQ(result[1], 6);  
    EXPECT_EQ(result[2], 3);  
}

TEST(PolynomialTest, Subtraction) {
    std::vector<double> coeffs1 = {1, 2, 3}; 
    std::vector<double> coeffs2 = {3, 4};    
   
    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);
    Polynomial result = p1 - p2;

    EXPECT_EQ(result[0], -2);  
    EXPECT_EQ(result[1], -2);  
    EXPECT_EQ(result[2], 3);  
}

TEST(PolynomialTest, Multiplication) {
    std::vector<double> coeffs1 = {1, 2};  
    std::vector<double> coeffs2 = {3, 4};  
   
    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);
    Polynomial result = p1 * p2;

    EXPECT_EQ(result[0], 3);  
    EXPECT_EQ(result[1], 10); 
    EXPECT_EQ(result[2], 8);  
}

TEST(PolynomialTest, Division) {
    std::vector<double> coeffs1 = {6, 11, 3};  
    std::vector<double> coeffs2 = {3, 1};      
   
    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);
    Polynomial result = p1 / p2;

    EXPECT_EQ(result[0], 2); 
    EXPECT_EQ(result[1], 3);  
    EXPECT_EQ(result[2], 0); 

    Polynomial zero_poly({0});  

    EXPECT_THROW(p1 / zero_poly, std::invalid_argument); 
}

TEST(PolynomialTest, AdditionAssignment) {
    std::vector<double> coeffs1 = {1, 2, 3};  
    std::vector<double> coeffs2 = {3, 4};    
   
    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);
   
    p1 += p2;

    EXPECT_EQ(p1[0], 4);  
    EXPECT_EQ(p1[1], 6);  
    EXPECT_EQ(p1[2], 3);  
}

TEST(PolynomialTest, SubtractionAssignment) {
    std::vector<double> coeffs1 = {5, 3, 2}; 
    std::vector<double> coeffs2 = {2, 1}; 
  
    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);
  
    p1 -= p2;

    EXPECT_EQ(p1[0], 3);  
    EXPECT_EQ(p1[1], 2); 
    EXPECT_EQ(p1[2], 2);  
}

TEST(PolynomialTest, MultiplicationAssignment) {
    std::vector<double> coeffs1 = {1, 2}; 
    std::vector<double> coeffs2 = {3, 4}; 
   
    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);
  
    p1 *= p2;

    EXPECT_EQ(p1[0], 3);   
    EXPECT_EQ(p1[1], 10);  
    EXPECT_EQ(p1[2], 8);  
}

TEST(PolynomialTest, DivisionAssignment) {
    std::vector<double> coeffs1 = {4, 6, 8};  
    std::vector<double> coeffs2 = {2};        
   
    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);
    p1 /= p2;

    EXPECT_EQ(p1[0], 2);  
    EXPECT_EQ(p1[1], 3);  
    EXPECT_EQ(p1[2], 4);  
}

TEST(PolynomialTest, DivisionByZero) {
    std::vector<double> coeffs1 = {1, 2}; 
    std::vector<double> coeffs2 = {0};    
   
    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);

    EXPECT_THROW(p1 /= p2, std::invalid_argument);
}

TEST(PolynomialTest, OutputStream) {
    std::vector<double> coeffs = {3, 0, 2, 1};  
    
    Polynomial p(coeffs);

    std::ostringstream os;
    os << p;

    EXPECT_EQ(os.str(), "1x^3 + 2x^2 + 3");
}