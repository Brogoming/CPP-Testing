#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include "Movie.cpp"

using namespace std;

const string movieFile = "movies.txt";

//reads the movies from the file
vector<Movie> read_movies() { //reads the movie file and returns a vector of movies
	vector<Movie> movies;
	ifstream inputFile(movieFile);
	if (inputFile) { //if the file loads successfuly push it into the vector
		string line;
		while (getline(inputFile, line)) { //while we are getting lines from the file
			stringstream ss(line); //ss is the stream of strings, 
			// A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream
			string title;
            int year;
            int stars;
            getline(ss, title, '\t'); //sets the movie title
			ss >> year >> stars; //sets the year and stars by the next 2 values
			movies.push_back(Movie(title, year, stars)); //adds the Movie object to a vector
		}
		inputFile.close();
	}
	return movies;
}

//writes the movies to the file
void write_movies(const vector<Movie>& movies) {
	ofstream outputFile(movieFile);
	if (outputFile) {
		for (Movie movie : movies) { //for every movie in movies write in the file the movie
			outputFile << movie.get_title() << '\t'
				<< movie.get_year() << '\t'
				<< movie.get_stars() << '\n';
		}
		outputFile.close();
	}
}

//presents a list of movies to the terminal
void view_movies(const vector<Movie>& movies) { //pointer to movies
	int colWidth = 8; //column width
	cout << left
		<< setw(colWidth / 2) << " "
		<< setw(colWidth * 4) << "TITLE"
		<< setw(colWidth) << "YEAR"
		<< setw(colWidth) << "STARS" << endl;
        
	int number = 1;
	for (Movie movie : movies) {
		cout << setw(colWidth / 2) << number
			<< setw(colWidth * 4) << movie.get_title()
			<< setw(colWidth) << movie.get_year()
			<< setw(colWidth) << movie.get_stars() << endl;
		++number;
	}
	cout << endl;
}

Movie get_movie() { //helps us add movies
    string title;
	cout << "Title: ";
	cin.ignore(1000, '\n');
	getline(cin, title);

    int year;
	cout << "Year: ";
	cin >> year;

    int stars;
	cout << "Stars (1-5): ";
	cin >> stars;

    Movie movie(title, year, stars);
	return movie;
}

void add_movie(vector<Movie>& movies) {
	Movie movie = get_movie(); //gets the movie the user inputs

	//check is the movie already exists
	bool exists = false;
	for (Movie& m : movies) {
		if (m.iequals(movie)) {
			exists = true;
			m.set_stars(movie.get_stars());
			break;
		}
	}

	if (exists) { //if the movie already exits the vector is updated
		write_movies(movies);
		cout << movie.get_title() << " already exits and was updated.\n\n";
	}
	else { //if the movie doesn't already exist the movie is added
		movies.push_back(movie);
		write_movies(movies);
		cout << movie.get_title() << " was added.\n\n";
	}
}

int get_movie_number(const vector<Movie>& movies) { //gets the number of movie, used for deleting
	int number;
	while (true) {
		cout << "Number: ";
		cin >> number;
		if (number > 0 && number <= movies.size()) {
			return number;
		}
		else {
			cout << "Invalid movie number. Try again.\n";
		}
	}
}

void delete_movie(vector<Movie>& movies) {
	int number = get_movie_number(movies);
	int index = number - 1;
	Movie movie = movies[index]; //movie at that index
	movies.erase(movies.begin() + index); //erase the movie at the index
	write_movies(movies); //rewrites the movie file
	cout << movie.get_title() << " was deleted.\n\n"; 
}

void display_menu() { //displays the commands
	cout << "COMMANDS\n"
		<< "v - View movie list\n"
		<< "a - Add a movie\n"
		<< "d - Delete a movie\n"
		<< "x - Exit\n\n";
}

int main() {
	cout << "The Movie List Program\n\n";
	display_menu();

	vector<Movie> movies = read_movies();
	char command = 'v';
	while (tolower(command) != 'x') {
		cout << "Command: ";
		cin >> command;
		switch (command) {
		case 'v':
			view_movies(movies);
			break;
		case 'a':
			add_movie(movies);
			break;
		case 'd':
			delete_movie(movies);
			break;
		case 'x':
			cout << "Bye!\n\n";
			break;
		default:
			cout << "Not a valid command. Please try again.\n\n";
			break;
		}
	}
	return 0;
}