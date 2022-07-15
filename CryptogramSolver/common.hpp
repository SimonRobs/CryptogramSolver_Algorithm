//
//  common.hpp
//  CryptogramSolver
//
//  Created by Simon Robatto on 2022-06-27.
//

#ifndef common_h
#define common_h

#include <exception>

class file_not_found: public std::exception { };
class file_format_error: public std::exception { };

#endif /* common_h */
