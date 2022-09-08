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
    toLowerCase(cryptogramDef);
    
    std::string keys;
    std::getline(file, keys);
    toLowerCase(keys);
    
    file.close();
    
    if(cryptogramDef.size() != keys.size()) throw file_format_error();
    
    return createCryptogram(keys, cryptogramDef);
}


std::vector<EncryptedWord*> FileParser::createCryptogram(const std::string& keys,const std::string& values) {
    std::vector<EncryptedWord*> cryptogram;
    
    std::istringstream cryptogramISS(values);
    std::string word;
    
    std::istringstream keyISS(keys);
    std::string key;
    
   while (std::getline(cryptogramISS, word, ' ')) {
       std::getline(keyISS, key, ' ');
       cryptogram.push_back(new EncryptedWord(word, key));
   }
    
    return cryptogram;
}
