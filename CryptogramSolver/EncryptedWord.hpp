//
//  EncryptedWord.hpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//

#ifndef EncryptedWord_hpp
#define EncryptedWord_hpp

#include <ostream>
#include <iterator>
#include <vector>
#include <string>

#include "EncryptedLetter.hpp"

class EncryptedWord {
    
public:
    EncryptedWord();
    EncryptedWord(std::string encryptedWord, std::string keys);

    // Returns the affected keys
    std::vector<char> tryValue(std::string val);
    // Returns true if the word was modified by the change
    bool changeKey(char key, char value);
    
    std::vector<EncryptedLetter*>& getLetters();
    bool hasUnknownLetters() const;
    
    size_t size() const;
    std::vector<EncryptedLetter*>::iterator begin();
    std::vector<EncryptedLetter*>::iterator end();
    
    bool operator<(const EncryptedWord& word) const;
    EncryptedLetter* operator[](int index);
    bool operator==(std::string word) const;
    friend std::ostream& operator<<(std::ostream& os, const EncryptedWord& word);
    
private:
    std::vector<EncryptedLetter*> _letters;
};


#endif /* EncryptedWord_hpp */
