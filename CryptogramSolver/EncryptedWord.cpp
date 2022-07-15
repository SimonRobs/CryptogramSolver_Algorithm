//
//  EncryptedWord.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//

#include "EncryptedWord.hpp"

EncryptedWord::EncryptedWord(std::string encryptedWord, std::string keys) {
    for(int i = 0; i < encryptedWord.size(); ++i) {
        char value = encryptedWord[i];
        char key = keys[i];
        _letters.push_back(EncryptedLetter(key, value));
    }
}

void EncryptedWord::tryValue(std::string val) {
    if(_letters.size() != val.size()) throw std::bad_exception();
    for(int i = 0; i < _letters.size(); ++i) {
        _letters[i].setValue(val[i]);
    }
}

std::vector<EncryptedLetter>& EncryptedWord::getLetters() {
    return _letters;
}

size_t EncryptedWord::size() const {
    return _letters.size();
}

bool EncryptedWord::operator<(const EncryptedWord& word) const {
    return size() < word.size();
}

EncryptedLetter EncryptedWord::operator[](int index) {
    return _letters[index];
}

std::ostream& operator<<(std::ostream& os, const EncryptedWord& word)
{
    for(auto letter: word._letters)
        os << letter;
    return os;
}
