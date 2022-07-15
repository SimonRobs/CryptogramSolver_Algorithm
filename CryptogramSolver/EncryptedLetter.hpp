//
//  EncryptedLetter.h
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//

#ifndef EncryptedLetter_h
#define EncryptedLetter_h

#include <ostream>
#include <vector>

class EncryptedLetter {
    
public:
    EncryptedLetter(char key, char value);
    char getKey() const;
    char getValue() const;
    void setValue(char value);
    
    friend std::ostream& operator<<(std::ostream& os, const EncryptedLetter& letter);
    
private:
    char _value;
    char _key;
};

#endif /* EncryptedLetter_h */
