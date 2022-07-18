//
//  Cryptogram.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-07-18.
//

#include "Cryptogram.hpp"

Cryptogram::Cryptogram(const std::vector<EncryptedWord*>& encryptedWords, Codebook& codebook): codebook(codebook) {
    longestEncryptedWordSize = 0;
    for(EncryptedWord* encryptedWord: encryptedWords)
        if(encryptedWord->size() > longestEncryptedWordSize)
            longestEncryptedWordSize = encryptedWord->size();
    encryptedWordsByLength = std::vector<std::vector<EncryptedWord*>>(longestEncryptedWordSize + 1);
    for(auto encryptedWord: encryptedWords)
        encryptedWordsByLength[encryptedWord->size()].push_back(encryptedWord);
}

void Cryptogram::setCodebook(const Codebook& codebook) {
    this->codebook = codebook;
    applyCodebook();
}

std::vector<std::map<char,char>> Cryptogram::getPossibleLetterCombinations() {
    EncryptedWord* wordWithFewerPossibilities = nullptr;
    std::vector<std::string> fewerPossibleWords;
    for(int i = 1; i <= longestEncryptedWordSize; ++i) {
        for (EncryptedWord* encryptedWord: encryptedWordsByLength[i]) {
            std::vector<std::string> possibleWords = codebook.getPossibleWords(encryptedWord);
            if(fewerPossibleWords.size() == 0 || (possibleWords.size() > 0 && possibleWords.size() < fewerPossibleWords.size())) {
                fewerPossibleWords = possibleWords;
                wordWithFewerPossibilities = encryptedWord;
            }
        }
    }
    
    std::vector<std::map<char,char>> combinations;
    if(wordWithFewerPossibilities != nullptr) {
        for(std::string possibleWord: fewerPossibleWords) {
            std::map<char,char> combination;
            for(int i = 0; i < wordWithFewerPossibilities->getLetters().size(); ++i) {
                EncryptedLetter* encryptedLetter = (*wordWithFewerPossibilities)[i];
                if(encryptedLetter->getKey() != '_')
                    combination[encryptedLetter->getKey()] = possibleWord[i];
            }
            combinations.push_back(combination);
        }
    }
    
    return combinations;
}


bool Cryptogram::wasSolutionFound() const {
    for(int i = 1; i <= longestEncryptedWordSize; ++i) {
        for (EncryptedWord* encryptedWord: encryptedWordsByLength[i]) {
            if(encryptedWord->hasUnknownLetters()) return false;
        }
    }
    return true;
}


void Cryptogram::applyCodebook() {
    for(int i = 1; i <= longestEncryptedWordSize; ++i) {
        for (EncryptedWord* encryptedWord: encryptedWordsByLength[i]) {
            codebook.applyTo(encryptedWord);
        }
    }
}
