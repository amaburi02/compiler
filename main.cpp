#include <iostream>
#include <fstream>
#include <string>
#include "scanner.h"

int main() {
    std::string user_input;
    table_driven_dfsa FSA1;

    while (std::getline(std::cin, user_input)) {
        std::cout << "Recieved input: " << user_input << std::endl;
        FSA1.tokenizer(user_input);        
    }

    return 0;
}