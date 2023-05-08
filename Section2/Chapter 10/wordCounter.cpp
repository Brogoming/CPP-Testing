#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

multiset<string> display_and_load_words(string fileName);
set<string> get_unique_words(const multiset<string>& words);
// map<string, int> get_word_count(const multiset<string>& words);

int main(){
    cout << "The Word Counter Program\n\n";

    string fileName = "dickens.txt";
    cout << "File text: ";
    auto words = display_and_load_words(fileName); //returns a vector of all of the words in the file

    cout << "Word Count: " << words.size();
    cout << endl << endl;

    auto uniqueWords = get_unique_words(words);

    // auto wordCount = get_word_count(words); //returns a map of the words, the keys are words and the values are how many times they show up

    cout << uniqueWords.size() << " UNIQUE WORDS: ";
    for (string word : uniqueWords){
        cout << word << ' ';
    }
    cout << endl << endl;

    cout << "COUNT PER WORD: ";
    for (string word: uniqueWords){
        cout << word << '=' << words.count(word) << ' ';
    }
    cout << endl << endl;
}

multiset<string> display_and_load_words(string fileName){ 
    multiset<string> words;
    ifstream infile(fileName);
    if(infile){
        string word;
        while(infile >> word){
            cout << word << ' ';
            string newWord = "";
            for(char c : word){
                if (c == '.' || c == ','){
                    continue; //remove punctuation
                }else if (isupper(c)) {
                    newWord += tolower(c); // convert to lowercase
                } else {
                    newWord += c;
                }
            }
            words.insert(newWord); //add word
        }
        cout << endl << endl;
        infile.close();
    }
    return words;
}

// map<string, int> get_word_count(const multiset<string>& words){
//     map<string, int> wordCount {};

//     for(string word: words){
//         auto search = wordCount.find(word);
//         if(search == wordCount.end()){
//             wordCount[word] = 1; //not found - add word with count of 1
//         } else {
//             wordCount[word] += 1; //found - increment count for word
//         }
//     }
//     return wordCount;
// }

set<string> get_unique_words(const multiset<string>& words){
    set<string> uniqueWords;

    for(string word: words){
        auto search = uniqueWords.find(word);
        if(search == uniqueWords.end()){
            uniqueWords.insert(word);
        }
    }
    return uniqueWords;
}