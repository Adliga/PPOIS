#include "Letter.h"

Letter::Letter(const std::string& cont, const std::string& trackNum, const std::string& send, const std::string& delivery,
    Sender* sender, Recipient* recipient)
    : Mail(cont, trackNum, send, delivery, sender, recipient) {}
