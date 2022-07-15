//
//  CommandLineArgumentParser.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//  Copyright © 2022 Simon Robatto. All rights reserved.
//

#include "CommandLineArgumentParser.hpp"


CommandLineArgumentParser::CommandLineArgumentParser(const char * argv[]) {
    arguments.wordsFilePath = argv[1];
    arguments.cryptogramFilePath = argv[2];
}

std::string CommandLineArgumentParser::getWordsFilePath() {
    return arguments.wordsFilePath;
}

std::string CommandLineArgumentParser::getCryptogramFilePath() {
    return arguments.cryptogramFilePath;
}
