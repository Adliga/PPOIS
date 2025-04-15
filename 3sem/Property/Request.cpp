#include "Request.h"

Request::Request(const std::string& requestID, const std::string& requestDate, const std::string& status)
    : requestID(requestID), requestDate(requestDate), status(status), service(nullptr) {}

std::string Request::getRequestID() const {
    return requestID;
}

std::string Request::getRequestDate() const {
    return requestDate;
}

std::string Request::getStatus() const {
    return status;
}

void Request::setStatus(const std::string& newStatus) {
    status = newStatus;
}

void Request::displayRequestInfo() const {
    std::cout
        << "Request ID: " << requestID << "\n"
        << "Request date: " << requestDate << "\n"
        << "Request status: " << status << "\n";
}