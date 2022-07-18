//
//  Codebook.hpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-07-18.
//

#ifndef Codebook_hpp
#define Codebook_hpp

#include <vector>
#include <map>
#include <set>
#include <string>

#include "EncryptedWord.hpp"

class Codebook {
    
public:
    Codebook(const std::vector<std::string>& allWords, const std::vector<EncryptedWord*>& encryptedWords);
    Codebook(const Codebook& codebook);
    
    std::vector<std::string> getPossibleWords(EncryptedWord* encryptedWord) const;
    void update(std::map<char,char> combinations);
    void applyTo(EncryptedWord* encryptedWord);
    
    
private:
    std::vector<std::vector<std::string>> allWordsByLength;
    std::set<char> knownLetters;
    std::map<char, char> combinations;
    
};

#endif /* Codebook_hpp */
