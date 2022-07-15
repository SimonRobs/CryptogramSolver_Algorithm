//
//  main.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//  Copyright © 2022 Simon Robatto. All rights reserved.
//

#include <algorithm>
#include <map>
#include <set>
#include <iostream>

#include "CommandLineArgumentParser.hpp"
#include "FileParser.hpp"

int main(int argc, const char * argv[]) {
    
    CommandLineArgumentParser args = CommandLineArgumentParser(argv);
    
    // Load and parse the files
    std::vector<std::string> words = FileParser::readWordsFile(args.getWordsFilePath());
    std::vector<EncryptedWord> cryptogram = FileParser::readCryptogramFile(args.getCryptogramFilePath());
    std::map<char, char> cryptogramDictionary;
    std::set<char> foundLetters;
    
    for(auto cryptoWord: cryptogram)
        for(auto letter: cryptoWord.getLetters())
            if(letter.getKey() != '_')
                cryptogramDictionary[letter.getKey()] = letter.getValue();
            else
                foundLetters.insert(letter.getValue());
    
    // Organize the words by length
    auto byLength = [](const std::string& s1,const std::string& s2) {
        return s1.size() < s2.size();
    };
    size_t longestWordSize = std::max_element(words.begin(), words.end(), byLength)->size();
    std::vector<std::vector<std::reference_wrapper<std::string>>> wordsByLength(longestWordSize + 1);
    for(auto word: words)
        wordsByLength[word.size()].push_back(word);
    
    // Organize the cryptogram words by length
    size_t longestCryptogramSize = std::max_element(cryptogram.begin(), cryptogram.end())->size();
    std::vector<std::vector<std::reference_wrapper<EncryptedWord>>> cryptogramByWordLength(longestCryptogramSize + 1);
    for(auto cryptoWord: cryptogram)
        cryptogramByWordLength[cryptoWord.size()].push_back(cryptoWord);

    
    // Find the list of possible
    for(int i = 0; i < 3; ++i) {
        for (auto cryptoWord: cryptogramByWordLength[i]) {
            std::vector<std::string> possibleWords;
            for(auto word: wordsByLength[i]) {
                bool possible = true;
                bool alreadyFull = true;
                for(int j = 0; j < i; ++j) {
                    bool isFilled = cryptoWord.get()[j].getValue() != '_';
                    if(!isFilled && alreadyFull) alreadyFull = false;
                    bool isLetterUsed = foundLetters.find(word.get()[j]) != foundLetters.end();
                    bool equalsFilledLetter = cryptoWord.get()[j].getValue() == word.get()[j];
                    if((!isFilled && isLetterUsed) || (isFilled && !equalsFilledLetter)) {
                        possible = false;
                        break;
                    }
                }
                if(!alreadyFull && possible) {
                    possibleWords.push_back(word);
                }
            }
            
            for(auto possibleWord: possibleWords) {
                cryptoWord.get().tryValue(possibleWord);
                for(auto letter: cryptoWord.get().getLetters())
                    if(letter.getKey() != '_')
                        cryptogramDictionary[letter.getKey()] = letter.getValue();
                for(auto c: possibleWord)
                    foundLetters.insert(c);
            }
            
        }
    }
    
    
    /**
        Possible classes:
            Cryptogram - Responsible of holding the encrypted words and updating all keys when trying a word
            CryptogramSolver - Responsible of finding all the possible words and trying them in a DFS until the end
     */
    
    
    // For every possible word, set the values of the dictionary to the guessed value
    
    // Find the next shortest word that was modified by the letter change and repeat the possible words / dictionary change loop
    // If no word was modified, simply find the next shortest
    
    // If we cannot find any word with the current letter combination, backtrack and try with another combination
    
    // Continue until all words were tried or a match was found
    
    return 0;
}
