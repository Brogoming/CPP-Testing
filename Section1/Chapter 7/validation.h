#ifndef DGULLICKSEN_VALIDATION_H
#define DGULLICKSEN_VALIDATION_H

#include <string>

namespace validation {
    //declare general purpose functions
    bool is_valid_password(std::string password);
    bool is_valid_email(std::string email);
}

#endif //DGULLICKSEN_VALIDATION_H