#pragma once
#ifndef SUPPORTSTAFF_H
#define SUPPORTSTAFF_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Request.h"

class SupportStaff : public User {
private:
    std::vector<Request*> assignedRequests;

public:
    SupportStaff(const std::string& name, const std::string& email);

    void getRequests() const;
    void assignRequest(Request* newRequest);
    void completeRequest(const std::string& requestID);
};

#endif
