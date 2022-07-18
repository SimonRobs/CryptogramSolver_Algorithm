//
//  main.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//  Copyright © 2022 Simon Robatto. All rights reserved.
//

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <iostream>

#include "CommandLineArgumentParser.hpp"
#include "Cryptogram.hpp"
#include "Codebook.hpp"


int main(int argc, const char * argv[]) {
    
    CommandLineArgumentParser args = CommandLineArgumentParser(argv);
    
    std::vector<std::string> words = FileParser::readWordsFile(args.getWordsFilePath());
    std::vector<EncryptedWord*> encryptedWords = FileParser::readCryptogramFile(args.getCryptogramFilePath());
    
    Codebook codebook = Codebook(words, encryptedWords);
    Cryptogram cryptogram = Cryptogram(encryptedWords, codebook);
    
    std::stack<Codebook> codebookStack;
    codebookStack.push(codebook);
    
    while(!codebookStack.empty()) {
        Codebook codebook = codebookStack.top();
        codebookStack.pop();
        cryptogram.setCodebook(codebook);
        
        std::vector<std::map<char,char>> possibleLetterCombinations = cryptogram.getPossibleLetterCombinations();
        for(std::map<char,char> combination: possibleLetterCombinations) {
            Codebook book = Codebook(codebook);
            book.update(combination);
            codebookStack.push(book);
        }
        if(cryptogram.wasSolutionFound()) {
            for(EncryptedWord* encryptedWord: encryptedWords) {
                std::cout << (*encryptedWord) << " ";
            }
            std::cout << std::endl;
        }
    }
    
    
    return 0;
}
