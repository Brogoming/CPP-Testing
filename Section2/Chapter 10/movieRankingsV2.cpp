#include <iostream>
#include <iomanip>
#include <string>
#include <list>

using namespace std;
void display_rankings(const list<string>& movies);
char get_choice();
void change_rankings(list<string>& movies, int current_ranking, int new_ranking);

int main() {
    list<string> movies {"Spider-Man", "Star Wars: IV", "The Batman", "Ghostbusters", "Spider-Man: Into the Spiderverse"};

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

void display_rankings(const list<string>& movies){
    cout << "\nMovie Rankings\n---------------\n"; //I'm pretty sure theres a repeat statement so we wouldn't have to type ----------
    int i = 1;
    for (string movie: movies){
        cout << i << "-" << movie << endl;
        ++i;
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

void change_rankings(list<string>& movies, int current_ranking, int new_ranking){
    //make sure ranking are in bounds
    if (current_ranking > 0 && new_ranking > 0 && current_ranking <= movies.size() && new_ranking <= movies.size()){
        //get iterator that points to first element
        auto iter = movies.begin();

        //increment iterator until it points to current ranking
        for (int i = 1; i < current_ranking; ++i){
            ++iter;
        }

        //store value of element to be moved
        string m = *iter;

        //remove element at old location
        movies.erase(iter);

        //get first iterator again and then increment to new ranking
        iter = movies.begin();
        for (int i = 1; i < new_ranking; ++i){
            ++iter;
        }

        //insert element at new location
        movies.insert(iter, m);
    }
}