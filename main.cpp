#include <iostream>
#include <fstream>
#include <string>
#include "scanner.h"

int main() {
    table_driven_dfsa FSA1;
    std::string user_input;
    std::string code_line;

    std::ofstream token_file("token_list.txt");

    while (std::getline(std::cin, user_input)) {
        std::cout << "DEBUG: Read line: " << user_input << std::endl;
        code_line = user_input + " ";
        FSA1.tokenizer(code_line, token_file);
    }
    
    std::cout << "DEBUG: Finished reading input!" << std::endl;

    return 0;
}