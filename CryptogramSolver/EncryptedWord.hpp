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
    EncryptedWord(std::string encryptedWord, std::string keys);

    void tryValue(std::string val);
    
    std::vector<EncryptedLetter>& getLetters();
    
    size_t size() const;
    
    bool operator<(const EncryptedWord& word) const;
    EncryptedLetter operator[](int index);
    friend std::ostream& operator<<(std::ostream& os, const EncryptedWord& word);
    
private:
    std::vector<EncryptedLetter> _letters;
};


#endif /* EncryptedWord_hpp */
