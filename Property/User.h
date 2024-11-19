#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
protected:
    std::string name;
    std::string email;
    std::string role;

public:
    User(const std::string& name, const std::string& email, const std::string& role);

    virtual ~User() = default;

    virtual void displayUserInfo() const;
};

#endif 
