//
//  utils.cpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-09-08.
//

#include "utils.hpp"

void toLowerCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c);});
}
