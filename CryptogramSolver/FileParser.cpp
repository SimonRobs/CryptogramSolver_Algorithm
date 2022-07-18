//
//  DatasetFileParser.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//  Copyright © 2022 Simon Robatto. All rights reserved.
//

#include "FileParser.hpp"

#include <iostream>

std::vector<std::string> FileParser::readWordsFile(const std::string& path) {
    std::ifstream file(path);
    
    if(!file.is_open()) throw file_not_found();
    
    std::vector<std::string> words;
    
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
    
    file.close();
    
    return words;
}

std::vector<EncryptedWord*> FileParser::readCryptogramFile(const std::string& path) {
    std::ifstream file(path);
    
    if(!file.is_open()) throw file_not_found();
    
    std::string cryptogramDef;
    std::getline(file, cryptogramDef);
    std::transform(cryptogramDef.begin(), cryptogramDef.end(), cryptogramDef.begin(), [](unsigned char c) { return std::tolower(c);});
    
    std::string keys;
    std::getline(file, keys);
    std::transform(keys.begin(), keys.end(), keys.begin(), [](unsigned char c) { return std::tolower(c);});
    
    file.close();
    
    if(cryptogramDef.size() != keys.size()) throw file_format_error();
    
    std::vector<EncryptedWord*> cryptogram;
    
    std::istringstream cryptogramISS(cryptogramDef);
    std::string word;
    
    std::istringstream keyISS(keys);
    std::string key;
    
   while (std::getline(cryptogramISS, word, ' ')) {
       std::getline(keyISS, key, ' ');
       cryptogram.push_back(new EncryptedWord(word, key));
   }
    
    return cryptogram;
}
