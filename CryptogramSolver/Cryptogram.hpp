//
//  Cryptogram.hpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-07-18.
//

#ifndef Cryptogram_hpp
#define Cryptogram_hpp

#include <vector>
#include <map>
#include <set>

#include "FileParser.hpp"
#include "EncryptedWord.hpp"
#include "Codebook.hpp"

class Cryptogram {
    
public:
    Cryptogram(const std::vector<EncryptedWord*>& encryptedWords, Codebook& codebook);
    
    void setCodebook(const Codebook& codebook);
    std::vector<std::map<char,char>> getPossibleLetterCombinations();
    
    bool wasSolutionFound() const;
    
private:
    
    void applyCodebook();
    
    size_t longestEncryptedWordSize;
    std::vector<std::vector<EncryptedWord*>> encryptedWordsByLength;
    Codebook& codebook;
    
};

#endif /* Cryptogram_hpp */
