/*
 * Name: Shaine O'Neal
 * Date Submitted: 10/27/2022
 * Assignment Name: Single Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <array>

using namespace std;

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

struct Alphabet {
        array<int, 26> alpha = {0};
    public:
        Alphabet() = default;
        Alphabet(string word) {
            for(int i = 0; i < word.size(); i++) {
                pushLetter(word.at(i));
            }
        }
        void pushLetter(int letter) {
            letter -= 97; 
            alpha[letter]++;
        }
        array<int, 26> final() {return alpha; }
        
};

struct alphabetHash {
    size_t operator()(const Alphabet &a) const{
            return ;
        }
};

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
/*vector<string> anagram(string word, vector<string> wordlist) {

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
}*/

vector<string> anagram(string word, vector<string> wordlist) {
    
    //create freq map for word
    Alphabet wordFreq(word);
    //create unordered_map
    unordered_map<array<int, 26>, vector<string>, Alphabet> miniDict;

    //iterate thru wordlist
    for(int i = 0; i < wordlist.size(); i++) {
        
        //if wordlist.word is the same size as word
        if(wordlist.at(i).size() == word.size()){

            //iterate thru letters in word
            for(int j = 0; j < word.size(); j++){

                //if first letter in wordlist.word is in word
                if(word[j] == wordlist.at(i)[0]) { 
                    //create freq list
                    Alphabet freq(wordlist.at(i));

                    //add word to miniDict
                    miniDict[freq.final()].push_back(wordlist.at(i));
                }
            }
        }
        
    }
    return miniDict[wordFreq.final()];



    //key = number of times each letter occurs in word
    //value = vector<string> anagrams

}