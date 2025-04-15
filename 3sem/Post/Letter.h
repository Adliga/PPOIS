#pragma once

#ifndef LETTER_H
#define LETTER_H

#include "Mail.h"

class Letter : public Mail {
public:
    Letter(const std::string& cont, const std::string& trackNum, const std::string& send, const std::string& delivery,
        Sender* sender, Recipient* recipient);
};
#endif