#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <list>

using namespace std;

enum class Command {view = 'v', add = 'a', del = 'd', mod = 'm', exit = 'x'}; //unnessesary but I wanted to test out enums

struct Movie { //creates a Movie object type
	string title = ""; //default values
	unsigned int year = 0;
	unsigned int stars = 0;

	bool equals(Movie& to_compare) { //member function that compares movies (pointers)
		return (title == to_compare.title && year == to_compare.year);
	}
};

const string movieFile = "movies.txt";

list<Movie> read_movies() { //reads the movie file and returns a list of movies
	list<Movie> movies;
	ifstream inputFile(movieFile);
	if (inputFile) { //if the file loads successfuly push it into the list
		Movie movie;
		string line;
		while (getline(inputFile, line)) { //while we are getting lines from the file
			stringstream ss(line); //ss is the stream of strings, 
			// A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream
			getline(ss, movie.title, '\t'); //sets the movie title
			ss >> movie.year >> movie.stars; //sets the year and stars by the next 2 values
			movies.push_back(movie); //adds the movie
		}
		inputFile.close();
	}
	return movies;
}

void write_movies(const list<Movie>& movies) {
	ofstream outputFile(movieFile);
	if (outputFile) {
		for (Movie movie : movies) { //for every movie in movies write in the file the movie
			outputFile << movie.title << '\t'
				<< movie.year << '\t'
				<< movie.stars << '\n';
		}
		outputFile.close();
	}
}
//presents a list of movies to the terminal
void view_movies(const list<Movie>& movies) { //pointer to movies
	int colWidth = 8; //column width
	cout << left
		<< setw(colWidth / 2) << " "
		<< setw(colWidth * 4) << "TITLE"
		<< setw(colWidth) << "YEAR"
		<< setw(colWidth) << "STARS" << endl;
	int number = 1;
	for (Movie movie : movies) {
		cout << left
			<< setw(colWidth / 2) << number
			<< setw(colWidth * 4) << movie.title
			<< setw(colWidth) << movie.year
			<< setw(colWidth) << movie.stars << endl;
		++number;
	}
	cout << endl;
}

Movie get_movie() { //helps us add movies
	Movie movie;
	cout << "Title: ";
	cin.ignore(1000, '\n');
	getline(cin, movie.title);
	cout << "Year: ";
	cin >> movie.year;
	cout << "Stars (1-5): ";
	cin >> movie.stars;
	return movie;
}

void add_movie(list<Movie>& movies) {
	Movie movie = get_movie(); //gets the movie the user inputs

	//check is the movie already exists
	bool exists = false;
	for (Movie& m : movies) {
		if (m.equals(movie)) {
			exists = true;
			break;
		}
	}

	if (exists) { //if the movie already exits the list is updated
		write_movies(movies);
		cout << movie.title << " already exits.\n\n";
	}
	else { //if the movie doesn't already exist the movie is added
		movies.push_back(movie);
		write_movies(movies);
		cout << movie.title << " was added.\n\n";
	}
}

int get_movie_number(const list<Movie>& movies) { //gets the number of movie, used for deleting
	cin.ignore(1000, '\n'); //discards 1000 character in the stream until it hits 1000 characters or the first \n is found
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

void delete_movie(list<Movie>& movies) {
	int number = get_movie_number(movies);

	auto iter = movies.begin();
	for (int i = 1; i < number; ++i) {
		++iter;
	}
	Movie movie = *iter;
	movies.erase(iter);

	write_movies(movies); //rewrites the movie file
	cout << movie.title << " was deleted.\n\n"; 
}

void modify_movie(list<Movie>& movies){
    int number = get_movie_number(movies);

    auto iter = movies.begin();
	for (int i = 1; i < number; ++i) {
		++iter;
	}
	Movie& movie = *iter;

    cout << "Enter new number of stars (1-5) for " << movie.title << ": ";
    cin >> movie.stars;

    write_movies(movies);
    cout << movie.title << " was updated.\n\n";
}

void display_menu() { //displays the commands
	cout << "COMMANDS\n"
		<< static_cast<char>(Command::view) << " - View movie list\n"
		<< static_cast<char>(Command::add) << " - Add a movie\n"
		<< static_cast<char>(Command::del) << " - Delete a movie\n"
        << static_cast<char>(Command::mod) << " - Modify a movie\n"
		<< static_cast<char>(Command::exit) << " - Exit\n\n";
}

int main() {
	cout << "The Movie List Program\n\n";
	display_menu();

	list<Movie> movies = read_movies();
	char command = 'y';
	while (tolower(command) != 'x') {
		cout << "Command: ";
		cin >> command;
		Command op = static_cast<Command>(command); //unnessesary but I wanted to test out enums
		switch (op) {
		case Command::view:
			view_movies(movies);
			break;
		case Command::add:
			add_movie(movies);
			break;
		case Command::del:
			delete_movie(movies);
			break;
        case Command::mod:
            modify_movie(movies);
            break;
		case Command::exit:
			cout << "Bye!\n\n";
			break;
		default:
			cout << "Not a valid command. Please try again.\n\n";
			break;
		}
	}
}