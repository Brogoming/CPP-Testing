#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> load_words(string fileName);
map<string, int> get_word_count(const vector<string>& words);
void display(pair<string, int> p);
bool over_1(pair<string, int> p);

struct FileNotFound{
    string message;
    string fileName;
};

int main(){
    cout << "The Word Counter Program\n\n";

    string fileName = "";
    cout << "Enter file name: ";
    cin >> fileName;

    vector<string> words;

    try {
		words = load_words(fileName);
	}
	catch (const FileNotFound e) {
		cout << e.message << "\n";
		cout << "You entered: " << e.fileName << ".\n";
		cout << "Exiting program...\n\n";
		return 0;
	}
	catch (...) {
		cout << "An unexpected error occurred!\n\n";
		throw;
	}

    cout << "\n" << words.size() << " WORDS: ";
    for (string word: words){
        cout << word << ' ';
    }
    cout << endl << endl;

    auto wordCount = get_word_count(words); //returns a map of the words, the keys are words and the values are how many times they show up

    cout << wordCount.size() << " UNIQUE WORDS: ";
    for (auto pair: wordCount){
        cout << pair.first << ' ';
    }
    cout << endl << endl;

    cout << "COUNT PER WORD: ";
    for_each(wordCount.begin(), wordCount.end(), display);
    cout << endl << endl;

    int repeatedWords = count_if(wordCount.begin(), wordCount.end(), over_1);
    cout << repeatedWords << " Duplicate Words";
}

void display(pair<string, int> p){
    cout << p.first << '=' << p.second << ' ';
}

bool over_1(pair<string, int> p){
    if(p.second > 1){
        return true;
    } else {
        return false;
    }
}

vector<string> load_words(string fileName){ 
    vector<string> words;
    ifstream infile(fileName);
    if(infile){
        string word;
        while(infile >> word){
            string newWord = "";
            for(char c : word){
                if (c == '.' || c == ','){
                    continue; //remove punctuation
                } else if (isupper(c)){
                    newWord += tolower(c); //convert to lower case
                } else {
                    newWord += c;
                }
            }
            words.push_back(newWord); //add word
        }
        infile.close();
        return words;
    } else {
		FileNotFound error;
		error.message = "File not found.";
		error.fileName = fileName;
		throw error;
	}
}

map<string, int> get_word_count(const vector<string>& words){
    map<string, int> wordCount {};

    for(string word: words){
        auto search = wordCount.find(word);
        if(search == wordCount.end()){
            wordCount[word] = 1; //not found - add word with count of 1
        } else {
            wordCount[word] += 1; //found - increment count for word
        }
    }
    return wordCount;
}