#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <fstream>

class table_driven_dfsa {
    private:
        int state_table[41][18];
    public:
        table_driven_dfsa();
        void initialize_table_dfsa(std::ifstream& table_file);
        void print_state_table();
        int char_convert(char current_char);
        int reserved_convert(std::string current_token);
        std::string clean_token(std::string current_token);
        void tokenizer(std::string code_line, std::fstream& token_file);
};

class symbol_table_dfsa {
    private:
        int state_table2[14][24];
    public:
        symbol_table_dfsa();
        void initialize_symbol_dfsa(std::ifstream& table_file2);
        void print_state_table();
        int token_convert(std::string s_token);
        void create_sym_table(std::fstream& token_file, std::fstream& symbol_file);
};

#endif