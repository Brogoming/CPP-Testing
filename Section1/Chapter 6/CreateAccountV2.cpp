#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Create Account\n\n";

    //get full name and parse first name
    string fullName;
    string firstName;
    bool validName = false;
    while(!validName){
        cout << "Enter full name: ";
        getline(cin, fullName);

        //get rid of the front whitespace
        auto i = fullName.find_first_not_of(" \n\t"); //returns the first occurnce of a character that doesn't match the substring
        if(i > -1){
            fullName = fullName.substr(i);
        }

        //get first name
        auto spaceIndex = fullName.find(' ');
        if(spaceIndex == -1){
            cout << "You must enter your full name. Please try again.\n";
        } else {
            firstName = fullName.substr(0, spaceIndex); //from beginning to first space
            validName = true;
        }
    }
    cout << endl;

    //get password
    string password;
    bool validPassword = false;
    while(!validPassword){
        //set valid flag
        validPassword = true;

        //get password
        cout << "Enter Password: ";
        getline(cin, password);

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
    }
    cout << endl;

    //get password
    string email;
    bool validEmail = false;
    while(!validEmail){
        //set valid flag
        validEmail = true;

        //get password
        cout << "Enter Email: ";
        getline(cin, email);

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

        auto dotIndex = email.find('.');
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
    }
    cout << endl;

    //make sure first name uses inital cap and then lower case
    char letter = firstName[0];
    firstName[0] = toupper(letter);
    for(int i = 1; i < firstName.length(); ++i){
        letter = firstName[i];
        firstName[i] = tolower(letter);
    }

    //display welcome
    cout << "Hi " << firstName << ",\n"
         << "Thanks for creating an account!\n\n";
}