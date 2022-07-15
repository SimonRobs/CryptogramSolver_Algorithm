//
//  CommandLineArgumentParser.hpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//  Copyright © 2022 Simon Robatto. All rights reserved.
//

#ifndef CommandLineArgumentParser_hpp
#define CommandLineArgumentParser_hpp

#include <string>

#include "types.hpp"

struct CommandLineArguments {
    std::string wordsFilePath;
    std::string cryptogramFilePath;
};

class CommandLineArgumentParser {
public:
    CommandLineArgumentParser(const char * argv[]);
    std::string getWordsFilePath();
    std::string getCryptogramFilePath();
private:
    CommandLineArguments arguments;
};

#endif /* CommandLineArgumentParser_hpp */
