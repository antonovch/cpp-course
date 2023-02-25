#include <string>
#include <sstream>
#include <iostream>

#include "funcs.h"

int main(int argc, const char* argv[] ) {
    
    if (argc != 2) {
        std::cout << "Wrong function call! Requires one integer argument.\n";
        return 1;
    }

    int num;
    std::istringstream stream{argv[1]};
    stream >> num;

    std::cout << "Is " << num << " positive? Answer: " << (isPositive(num) ? "yes" : "no") << ".\n"; 

    return 0;

}
