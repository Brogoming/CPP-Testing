#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> load_words(string fileName);
map<string, int> get_word_count(const vector<string>& words);

int main(){
    cout << "The Word Counter Program\n\n";

    string fileName = "dickens.txt";
    auto words = load_words(fileName); //returns a vector of all of the words in the file

    cout << words.size() << " WORDS: ";
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
    for (auto pair: wordCount){
        cout << pair.first << '=' << pair.second << ' ';
    }
    cout << endl << endl;
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
    }
    return words;
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