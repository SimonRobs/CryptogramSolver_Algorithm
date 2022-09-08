//
//  CommandLineArgumentParser.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//  Copyright © 2022 Simon Robatto. All rights reserved.
//

#include "CommandLineArgumentParser.hpp"
#include <iostream>


CommandLineArgumentParser::CommandLineArgumentParser(const char * argv[]) {
    arguments.wordsFilePath = argv[1];
    
    std::string cryptogramFileArg = argv[2];
    
    if(cryptogramFileArg.find("-f") != std::string::npos) {
        arguments.cryptogramFilePath = argv[3];
    } else {
        arguments.cryptogramValues = argv[2];
        toLowerCase(arguments.cryptogramValues);
        
        arguments.cryptogramKeys = argv[3];
        toLowerCase(arguments.cryptogramKeys);
    }
}

std::string CommandLineArgumentParser::getWordsFilePath() {
    return arguments.wordsFilePath;
}

std::string CommandLineArgumentParser::getCryptogramFilePath() {
    return arguments.cryptogramFilePath;
}

std::pair<std::string,std::string> CommandLineArgumentParser::getCryptogramKeyValuePair() {
    return std::make_pair(arguments.cryptogramKeys, arguments.cryptogramValues);
}
