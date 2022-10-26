/*
 * Name:
 * Date Submitted:
 * Assignment Name:
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

static int counter = 0;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

//hash function based on word size
size_t hash_size(const string word) {
    return word.size();
}

char hash_letter(const string word) {
    return word[0];
}

//find sum of ASCII codes for all letters in word
int findVal(string word) {
    int wordVal = 0;

    for(int i = 0; i < word.size(); i++) {
        wordVal += word[i];
    }
    return wordVal;
}


int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist) {

    vector<string> anagrams;

    //iterate thru wordlist
    for(int i = 0; i < wordlist.size(); i++) {
        
        //if wordlist.word is the same size as word
        if(wordlist.at(i).size() == word.size()){
            string tempWord = word;
            string wordToTest = wordlist.at(i);
            //iterate thru letters in word
            for(int j = 0; j < tempWord.size(); j++){

                //if first letter in wordlist.word is in word
                if(tempWord[j] == wordToTest[0]) {                  
                    //remove letter from wordlist.word
                    wordToTest.erase(0, 1);
                    //remove letter from tempword
                    tempWord.erase(j, 1);
                    j = -1;
                }
                if(tempWord.empty()) {anagrams.push_back(wordlist.at(i));}
            }
            
        }
    }
    return anagrams;
}