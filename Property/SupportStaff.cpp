#include "SupportStaff.h"

SupportStaff::SupportStaff(const std::string& name, const std::string& email)
    : User(name, email, "Support staff") {}

void SupportStaff::getRequests() const {
    std::cout << "List of requests:" << std::endl;
    for (const auto& request : assignedRequests) {
        if (request) {
            request->displayRequestInfo();
            std::cout << std::endl;
        }
        else {
            std::cout << "Found null requests!" << std::endl;
        }
    }
}

void SupportStaff::assignRequest(Request* newRequest) {
    if (newRequest) {
        assignedRequests.push_back(newRequest);
        std::cout << "Request added: ";
        newRequest->displayRequestInfo();
    }
    else {
        std::cout << "Error: Attempted to add a null request!" << std::endl;
    }
    std::cout << std::endl;
}

void SupportStaff::completeRequest(const std::string& requestID) {
    for (auto& request : assignedRequests) {
        if (request && request->getRequestID() == requestID) {
            if (request->getStatus() == "Processed") {
                request->setStatus("Completed");
                std::cout << "Request " << requestID << " has been completed." << std::endl;
            }
            else {
                std::cout << "Request " << requestID << " is already " << request->getStatus() << "." << std::endl;
            }
            return;
        }
    }
    std::cout << "Request with ID " << requestID << " not found." << std::endl;
}
