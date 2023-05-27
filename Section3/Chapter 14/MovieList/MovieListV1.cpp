#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Movie{
    private:
        string title;
        int year;
    public:
        void set_title(string);
        string get_title() const;
        void set_year(int);
        int get_year() const;
};

void Movie::set_title(string titleParam){
    title = titleParam;
}

string Movie::get_title() const{
    return title;
}

void Movie::set_year(int yearParam){
    if(yearParam < 1888){
        throw invalid_argument("Year must be 1888 or later.");
    }
    year = yearParam;
}

int Movie::get_year() const{
    return year;
}

int main(){
    cout << "The Movie List program\n\n" << "Enter a movie ... \n\n";

    //get movies from user
    vector<Movie> movies;
    char another = 'y';
    while(tolower(another) == 'y'){
        Movie movie;

        string title;
        cout << "Title: ";
        getline(cin, title);
        movie.set_title(title);

        int year;
        cout << "Year: ";
        cin >> year;
        try{
            movie.set_year(year);
        } catch (const invalid_argument& e){
            cout << e.what() << "\n";
            cout << "Exiting program...\n\n";
            return 0;
        }

        movies.push_back(movie);

        cout << "\nEnter another movie? (y/n): ";
        cin >> another;
        cin.ignore();
        cout << endl;
    }

    //display the movies
    const int w = 10;
    cout << left << setw(w * 3) << "TITLE" << setw(w) << "YEAR" << endl;
    for(Movie movie: movies){
        cout << setw(w * 3) << movie.get_title() << setw(w) << movie.get_year() << endl;
    }
    cout << endl;
}