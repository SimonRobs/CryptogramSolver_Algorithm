//
//  FileParser.hpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//  Copyright © 2022 Simon Robatto. All rights reserved.
//


#ifndef FileParser_hpp
#define FileParser_hpp

#include <algorithm>
#include <vector>
#include <fstream>
#include <exception>
#include <string>
#include <sstream>
#include <cctype>

#include "common.hpp"
#include "EncryptedWord.hpp"

class FileParser {
public:
    FileParser() = delete;
    static std::vector<std::string> readWordsFile(const std::string& path);
    static std::vector<EncryptedWord> readCryptogramFile(const std::string& path);
};

#endif /* FileParser_hpp */
