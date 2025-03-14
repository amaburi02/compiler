#include <iostream>
#include <fstream>
#include <string>
#include "scanner.h"

int main() {
    std::fstream token_file ("token_list.txt");
    std::ifstream table_file ("token_fsa.txt");
    std::fstream symbol_file ("symbol_table.txt");
    std::ifstream table_file2 ("symbol_fsa.txt");
    
    table_driven_dfsa FSA1;
    std::string user_input;
    std::string code_line;

    FSA1.initialize_table_dfsa(table_file);
    FSA1.print_state_table();

    while (std::getline(std::cin, user_input)) {
        std::cout << "DEBUG: Read line: " << user_input << std::endl;
        code_line = user_input + " ";
        FSA1.tokenizer(code_line, token_file);
    }

    token_file.clear();
    token_file.seekg(0, std::ios::beg);

    symbol_table_dfsa FSA2;
    FSA2.initialize_symbol_dfsa(table_file2);
    FSA2.print_state_table();

    FSA2.create_sym_table(token_file, symbol_file);

    return 0;
}