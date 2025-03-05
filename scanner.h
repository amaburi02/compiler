#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <fstream>

class table_driven_dfsa {
    private:
        int state_table[32][15];
    public:
        table_driven_dfsa();
        table_driven_dfsa(int tab_data[]);
        int char_convert(char current_char);
        std::string clean_token(std::string current_token);
        void tokenizer(std::string code_line, std::ofstream& token_file);
};

#endif