//
//  EncryptedWord.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//

#include "EncryptedWord.hpp"


EncryptedWord::EncryptedWord():_letters() { }

EncryptedWord::EncryptedWord(std::string encryptedWord, std::string keys) {
    for(int i = 0; i < encryptedWord.size(); ++i) {
        char value = encryptedWord[i];
        char key = keys[i];
        _letters.push_back(new EncryptedLetter(key, value));
    }
}

std::vector<char> EncryptedWord::tryValue(std::string val) {
    std::vector<char> changedKeys;
    if(_letters.size() != val.size()) throw std::bad_exception();
    for(int i = 0; i < _letters.size(); ++i) {
        bool valueChanged =  _letters[i]->setValue(val[i]);
        if(valueChanged)
            changedKeys.push_back(_letters[i]->getKey());
    }
    return changedKeys;
}

bool EncryptedWord::changeKey(char key, char value) {
    bool modified = false;
    for(EncryptedLetter* letter : _letters)
        if(letter->getKey() == key)
            modified |= letter->setValue(value);
    return modified;
}

std::vector<EncryptedLetter*>& EncryptedWord::getLetters() {
    return _letters;
}

bool EncryptedWord::hasUnknownLetters() const {
    for(EncryptedLetter* letter: _letters)
        if(letter->getValue() == '_')
            return true;
    return false;
}

size_t EncryptedWord::size() const {
    return _letters.size();
}

std::vector<EncryptedLetter*>::iterator EncryptedWord::begin() {
    return _letters.begin();
}

std::vector<EncryptedLetter*>::iterator EncryptedWord::end() {
    return _letters.end();
}

bool EncryptedWord::operator<(const EncryptedWord& word) const {
    return size() < word.size();
}

EncryptedLetter* EncryptedWord::operator[](int index) {
    return _letters[index];
}

std::ostream& operator<<(std::ostream& os, const EncryptedWord& word)
{
    for(auto letter: word._letters)
        os << *letter;
    return os;
}
