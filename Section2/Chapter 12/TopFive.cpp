#include <iostream>
#include <cstring>

using namespace std;

//global constant
const int itemLength = 51;

//function declaration
void alpha_sort(char items [][itemLength], int size);
void reset_stream();

int main(){
    //create 2D array to hold C strings from user
    const int size = 5;
    char list[size][itemLength];

    char itemType[itemLength] = "";
    cout << "What kind of items are going to be on your list? ";
    cin.getline(itemType, itemLength);
    reset_stream();
    cout << endl;

    //get line from user
    cout << "Please enter you top " << size << " " << itemType << ":\n";
    for(int i = 0; i < size; ++i){
        cout << "#" << (i+1) << ": ";
        cin.getline(list[i], itemLength);
        reset_stream();
    }
    cout << endl;

    //sort and display the items in the list
    alpha_sort(list, size);
    cout << "Your top " << size << " " << itemType << ", sorted alphabetically: \n"
         << "----------------------------------------\n";
    for(int i = 0; i < size; ++i){
        cout << list[i] << endl;
    }  
}

//an alphabetical bubble sort
void alpha_sort(char items [][itemLength], int size){
    bool isSwap;
    char temp[itemLength] = ""; //temporary C String
    do {
        isSwap = false; //reset flag to false

        for(int i = 0; i < (size - 1); ++i){ //stop at second to last
            if(strcmp(items[i], items[i + 1]) > 0){
                //swap current and next values
                strncpy(temp, items[i], itemLength - 1);
                strncpy(items[i], items[i + 1], itemLength - 1);
                strncpy(items[i + 1], temp, itemLength - 1);

                //set flag to indicate a swap occured
                isSwap = true;
            }
        }
    } while(isSwap); //if swaped occured continue to loop
}

void reset_stream(){
    if(cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
    }
}