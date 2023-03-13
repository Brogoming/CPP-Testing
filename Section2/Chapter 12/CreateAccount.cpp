#include <iostream>
#include <cstring> //for C string utility functions

using namespace std;

//function declaraitions
void get_name(char firstName[], char fullName[], int size);
void get_password(char password[], int size);
void trim_leading_whitespace(char cstring[]);
int find_space(char cstring[]);
void capitalize_initial_letter(char cstring[]);
void reset_stream();

int main(){
    cout << "Create Account\n\n";

    const int size = 51; //space for 50 characters plus null terminator
    char fullName[size] = "", firstName[size] = "", password[size] = "";

    get_name(firstName, fullName, size);
    get_password(password, size);
    capitalize_initial_letter(firstName);

    //display welcome message
    cout << "\nHi " << firstName << ",\n"
         << "Thanks for creating an account!\n\n";

    return 0;
}

//function definitions
void get_name(char firstName[], char fullName[], int size){
    while(true){
        cout << "Enter full name (" << size-1 << " chars max): ";
        cin.getline(fullName, size);
        reset_stream();

        trim_leading_whitespace(fullName);

        //get first name
        int index = find_space(fullName);
        if(index == -1){
            cout << "You must enter your full name. Try again.\n\n";
        } else {
            strncpy(firstName, fullName, index);
            break;
        }
    }
}

void trim_leading_whitespace(char cstring[]){
    if(isspace(cstring[0])){
        //increment index until first non-space character found 
        int i = 0;
        while(isspace(cstring[i])){
            ++i;
        }

        //start manual capy at index of first non-space character
        int j = 0;
        while(cstring[i] != '\0'){
            cstring[j] = cstring[i]; //shift chars to the left
            ++i;
            ++j;
        }

        //add null terminator to string
        cstring[j] = '\0';
    }
}

int find_space(char cstring[]){
    bool spaceFound = false;
    int i, len = strlen(cstring);
    for(i = 0; i < len; ++i){
        if(isspace(cstring[i])){
            spaceFound = true;
            break; //exit loop
        }
    }
    if(spaceFound){
        return i;
    } else {
        return -1;
    }
}

void get_password(char password[], int size){
    while(true){
        cout << "Enter password (" << size - 1 << " chars max): ";
        cin.getline(password, size);
        reset_stream();

        //make sure the password has at least 8 characters
        int len = strlen(password);
        bool hasLength = (len < 8) ? false : true;

        //make sure password includes a number 
        bool hasNumber = false;
        for(int i = 0; i < len; ++i){
            if(isdigit(password[i])){
                hasNumber = true;
                break; //exit inner loop
            }
        }

        //make sure password includes a special character
        bool hasSpecialChar = false;
        for(int i = 0; i < len; ++i){
            if(ispunct(password[i])){
                hasSpecialChar = true;
                break; //exit inner loop
            }
        }

        //if all tests pass, exit outer loop
        if(hasLength && hasNumber &&hasSpecialChar){
            break; //exit outer loop
        } else {
            cout << "Password must meet the following criteria:\n"
                 << " - at least 8 characters long\n"
                 << " - at least one number\n"
                 << " - at least one special character\n"
                 << "Try again.\n\n";
        }
    }
}

void capitalize_initial_letter(char cstring[]){
    cstring[0] = toupper(cstring[0]); //upper case for first letter
    int len = strlen(cstring);
    for(int i = 1; i < len; ++i){
        cstring[i] = tolower(cstring[i]); //lower case for the rest
    }
}

void reset_stream(){
    if(cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
    }
}