#include <string>
#include <iostream>
#include <map>
#include <regex>

using namespace std;


// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const string& str, const string& sub) {
  if (sub.length() == 0) return 0;
  int count = 0;
  for (int offset = str.find(sub); offset != string::npos; offset = str.find(sub, offset + sub.length())) {
    ++count;
  }
  return count;

}

int wordCount(const string& str){
    if (str.length() == 0) return 0;
    int count = 0;
    string word = "";
    regex num("\\d"); // look for 0-9 any length
    for(int i=0; i < str.length(); i = str.find(" ", i+1)){
        word = str.substr(i, str.find(" ", i+1)-i);
        if (!regex_search(word, num)){
            count++;
            // cout << word << endl; // DEBUG
        }
    }
    return count;
}

int uniqueWords(const string& str) {
    if (str.length() == 0) return 0;
    map<string, int> dictionary; // make a dict for the word, timesFound

    string word = "";
    regex num("\\d");
    regex pattern("[,!. ]");
    for(int i=0; i < str.length(); i = str.find(" ", i+1)){
        word = str.substr(i, str.find(" ", i+1)-i);
        word = regex_replace(word, pattern, "");
        if (!regex_search(word, num)){
            if (dictionary.find(word) != dictionary.end()){
                dictionary.insert(make_pair(word, dictionary[word]+1));
            }
            else {
                dictionary.insert(make_pair(word, 1));
                // cout << (word); // debug
            }
        }
    }
    return dictionary.size(); // we only care about the length of the dictionary in this case
    
}

int sentenceCount(const string& str){
    int count = 0;
    string word = "";
    for(int i=0; i < str.length(); i = str.find(".", i+1)){ // loop through every period
        count++;
    }
    return count-1; // it overcounts by one so remove the one overcount
}

int wordPerSentence(int words, int sentences){
    float val = (float) words / (float) sentences; // calculate using floats then round
    val = val + 0.5f; // round (it is not possible for this to be negative)
    int ans = (int) val;
    return ans;


}

int lexileDensity(int words, int uniqueWords){
    double value = (float) uniqueWords / (float) words; 
    value *= 100; // turn to percent
    value += 0.5; // round
    return (int) value;
}

int main() {
    string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.");
    
    cout << "Substring count: " << countSubstring(source, "is") << '\n';
    cout << "Word count: " << wordCount(source) << "\n";
    cout << "Unique word count: " << uniqueWords(source) << "\n"; 
    // cout << "sentence count:\t" << sentenceCount(source) << "\n"; 
    // cout << "words per sentence:\t" << wordPerSentence(wordCount(source), sentenceCount(source)) << "\n";
    cout << "Lexical density: " << lexileDensity(wordCount(source), uniqueWords(source)) << "%\n";

    return 0;

}