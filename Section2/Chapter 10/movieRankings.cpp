#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
void display_rankings(const vector<string>& movies);
char get_choice();
void change_rankings(vector<string>& movies, int current_ranking, int new_ranking);

int main() {
    vector<string> movies {"Spider-Man", "Star Wars: IV", "The Batman", "Ghostbusters", "Spider-Man: Into the Spiderverse"};

    cout << "The Movie Rankings Program\n";
    display_rankings(movies);
    char choice = get_choice();

    while (tolower(choice)=='y'){
        int current_ranking = 0;
        cout << "Enter current ranking of a movie: ";
        cin >> current_ranking;

        int new_ranking = 0;
        cout << "Enter new ranking of the movie: ";
        cin >> new_ranking;

        change_rankings(movies, current_ranking, new_ranking);
        display_rankings(movies); //show updated rankings
        choice = get_choice(); //asks if user wants to continue
    }
}

void display_rankings(const vector<string>& movies){
    cout << "\nMovie Rankings\n---------------\n"; //I'm pretty sure theres a repeat statement so we wouldn't have to type ----------
    for (int i = 0; i < movies.size(); ++i){
        cout << (i+1) << "-" << movies[i] << endl;
    }
    cout << endl;
}

char get_choice(){
    char choice;
    cout << "Do you want to change any rankings? (y/n): ";
    cin >> choice;
    cin.ignore(10000, '\n');
    return choice;
}

void change_rankings(vector<string>& movies, int current_ranking, int new_ranking){
    //make sure ranking are in bounds
    if (current_ranking > 0 && new_ranking > 0 && current_ranking <= movies.size() && new_ranking <= movies.size()){
        //decrement rankings to create valid indexes
        --current_ranking;
        --new_ranking;

        //store element
        string movie = movies[current_ranking];

        //remove element at old location
        movies.erase(movies.begin() + current_ranking);

        //insert element at new location
        movies.insert(movies.begin() + new_ranking, movie);
    }
}