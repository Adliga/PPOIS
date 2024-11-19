#include "User.h"

User::User(const std::string& name, const std::string& email, const std::string& role)
    : name(name), email(email), role(role) {}

void User::displayUserInfo() const {
    std::cout << "Имя: " << name << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Роль: " << role << "\n";
}
