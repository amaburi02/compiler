#include <iostream>
#include <fstream>
#include <string>
#include "scanner.cpp"

int main() {
    std::string user_input;

    std::ofstream token_list("token_list.txt");

    table_driven_dfsa FSA1;

    while (std::getline(std::cin, user_input)) {
        FSA1.tokenizer(user_input);        
    }

    return 0;
}