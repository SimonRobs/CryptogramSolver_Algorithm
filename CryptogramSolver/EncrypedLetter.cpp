//
//  EncrypedLetter.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//

#include "EncryptedLetter.hpp"

EncryptedLetter::EncryptedLetter(char key, char value): _key(key), _value(value) {}

bool EncryptedLetter::setValue(char value) {
    if(_key == '_') return false;
    _value = value;
    return true;
}

char EncryptedLetter::getKey() const {
    return _key;
}

char EncryptedLetter::getValue() const {
    return _value;
}

std::ostream& operator<<(std::ostream& os, const EncryptedLetter& letter)
{
    os << letter._value;
//    if(letter._key != '_')
//        os << '(' << letter._key << ')';
    return os;
}
