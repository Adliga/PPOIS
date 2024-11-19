#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <string>
#include "Service.h" 

class Request {
private:
    std::string requestID;
    Service* service;
    std::string requestDate;
    std::string status;

public:
    Request(const std::string& requestID, const std::string& requestDate, const std::string& status);

    std::string getRequestID() const;
    std::string getRequestDate() const;
    std::string getStatus() const;

    void setStatus(const std::string& newStatus);
    void displayRequestInfo() const;
};

#endif 
