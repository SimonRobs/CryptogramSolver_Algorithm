//
//  Codebook.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-07-18.
//

#include "Codebook.hpp"

Codebook::Codebook(const std::vector<std::string>& allWords, const std::vector<EncryptedWord*>& encryptedWords) {
    
    auto byLength = [](const std::string& s1,const std::string& s2) {
        return s1.size() < s2.size();
    };
    
    size_t longestWordSize = std::max_element(allWords.begin(), allWords.end(), byLength)->size();
    allWordsByLength = std::vector<std::vector<std::string>>(longestWordSize + 1);
    
    for(auto word: allWords)
        allWordsByLength[word.size()].push_back(word);
    
    
    for(EncryptedWord* encryptedWord: encryptedWords) {
        for(EncryptedLetter* letter: encryptedWord->getLetters()) {
            if(letter->getKey() == '_')
                knownLetters.insert(letter->getValue());
            else if(letter->getValue() != '_')
                combinations[letter->getKey()] = letter->getValue();
                // TODO: In the future, check the correctness of the cryptogram by making sure there is only one value associated to one key
        }
    }
}

Codebook::Codebook(const Codebook& codebook) {
    combinations.clear();
    
    knownLetters = codebook.knownLetters;
    allWordsByLength = codebook.allWordsByLength;
    
    for(std::pair<char,char> combination: codebook.combinations) {
        if(combination.first == '_')
            knownLetters.insert(combination.second);
        else
            combinations[combination.first] = combination.second;
    }
}


void Codebook::update(std::map<char,char> combinations) {
    for(std::pair<char,char> combination: combinations) {
        this->combinations[combination.first] = combination.second;
    }
}


std::vector<std::string> Codebook::getPossibleWords(EncryptedWord* encryptedWord) const {
    std::vector<std::string> possibleWords;
    if(encryptedWord->hasUnknownLetters()) {
        for(std::string word: allWordsByLength[encryptedWord->size()]) {
            bool isPossible = true;
            for(int i = 0; i < encryptedWord->size(); ++i) {
                bool isLetterFilled = (*encryptedWord)[i]->getValue() != '_';
                bool isLetterUsed = knownLetters.find(word[i]) != knownLetters.end();
                bool areLettersEqual = (*encryptedWord)[i]->getValue() == word[i];
                if((!isLetterFilled && isLetterUsed) || (isLetterFilled && !areLettersEqual)) {
                    isPossible = false;
                    break;
                }
           }
            if(isPossible) possibleWords.push_back(word);
        }
    }
    return possibleWords;
}


void Codebook::applyTo(EncryptedWord* encryptedWord) {
    for(EncryptedLetter* encryptedLetter: *encryptedWord) {
        char guessedValue = combinations[encryptedLetter->getKey()];
        if(guessedValue != '\0') encryptedLetter->setValue(guessedValue);
        else encryptedLetter->setValue('_');
    }
}
