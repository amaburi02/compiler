#include <iostream>
#include <fstream>
#include <string>
#include "scanner.h"

int main() {
    table_driven_dfsa FSA1;
    std::string user_input = " ";
    std::string program_code = " ";

    std::ofstream token_file("token_list.txt");

    if (std::cin.fail()) {
        std::cerr << "ERROR: std::cin is in a failed state before reading input!" << std::endl;
        return 1;
    }
    std::cout << "DEBUG: std::cin is OK, proceeding to getline()" << std::endl;
    std::cout << "DEBUG: Address of user_input: " << &user_input << std::endl;

    std::cout << "DEBUG: Entering input loop..." << std::endl;

    while (std::getline(std::cin, user_input)) {
        std::cout << "DEBUG: Read line: " << user_input << std::endl;
        program_code += user_input + " ";  
    }
    
    std::cout << "DEBUG: Finished reading input!" << std::endl;
    

    std::cout << "DEBUG: Calling tokenizer..." << std::endl;
    FSA1.tokenizer(program_code, token_file);
    std::cout << "DEBUG: Tokenizer finished!" << std::endl;
    

    return 0;
}