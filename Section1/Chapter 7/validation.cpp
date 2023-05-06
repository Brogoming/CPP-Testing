#include <iostream>
#include <string>
// #include "validation.h"

using namespace std;

namespace validation{
    bool is_valid_password(string password){
        //set valid flag
        bool validPassword = true;

        //has to be at least 8 characters long
        if(password.length() < 8){
            cout << "Password must be at least 8 characters long.\n";
            validPassword = false;
        }

        //password must include a number
        auto numIndex = password.find_first_of("0123456789"); //returns the first character in the substring
        if(numIndex == -1){
            cout << "Password must include a number.\n";
            validPassword = false;
        }

        //password must include a special character
        bool specialChar = false;
        for(char c : password){
            if(ispunct(c)){
                specialChar = true;
                break;
            }
        }
        if(!specialChar){
            cout << "Password must include a special character.\n";
            validPassword = false;
        }

        //try again message
        if(!validPassword){
            cout << "Please try again.\n";
        }

        return validPassword;
    }

    bool is_valid_email(string email){
        //set valid flag
        bool validEmail = true;

        auto atIndex = email.find('@');
        if(atIndex == -1){
            cout << "Email must include an @ symbol.\n";
            validEmail = false;
        } else {
            string temp = email.substr(0, atIndex);
            if(temp.empty()){
                cout << "Email must have characters before the @.\n";
                validEmail = false;
            }
        }

        auto dotIndex = email.rfind('.');
        if(dotIndex == -1){
            cout << "Email must include a dot character(.).\n";
            validEmail = false;
        } else {
            string betweenStr = email.substr(atIndex + 1, 1);
            if (betweenStr == "."){
                cout << "Email must have characters between @ and (.).\n";
                validEmail = false;
            }

            string domainStr = email.substr(dotIndex + 1, 3);
            if (domainStr.length() < 3){
                cout << "Email has invalid domain name.\n";
                validEmail = false;
            }
        }

        //checks if the rest of the characters are alphaNumeric
        bool alphaNumChar = false;
        for(char e : email){
            if(isalnum(e)){
                alphaNumChar = true;
                break;
            }
        }
        if(!alphaNumChar){
            cout << "The email has a non alphanumeric character.\n";
            validEmail = false;
        }

        //try again message
        if(!validEmail){
            cout << "Please try again.\n";
        }

        return validEmail;
    }
}