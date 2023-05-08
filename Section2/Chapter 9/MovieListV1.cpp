#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//define the stucture of the Movie object
struct Movie {
    string title = "";
    int year = 0;
};

int main(){
    cout << "The Movie List program\n\n"
         << "Enter a movie...\n\n";

    //get vector of movie objects
    vector<Movie> movieList;
    char another = 'y';
    while(tolower(another) == 'y'){
        Movie movie;

        cout << "Title: ";
        getline(cin, movie.title);

        cout << "Year: ";
        cin >> movie.year;

        movieList.push_back(movie);

        cout << "\nEnter another movie? (y/n): ";
        cin >> another;
        cin.ignore();
        cout << endl;
    }

    //display the objects stored in the vector
    const int w = 10;
    cout << left << setw(w * 3) << "TITLE" << setw(w) << "YEAR" << endl;
    for (Movie movie : movieList){
        cout << setw(w * 3) << movie.title << setw(w) << movie.year << endl << endl;
    }
}