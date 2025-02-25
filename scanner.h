#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <fstream>

extern std::ofstream token_file;

class table_driven_dfsa {
    private:
        int state_table[32][15];
    public:
        table_driven_dfsa();
        table_driven_dfsa(int tab_data[]);
        int char_convert(char current_char);
        void tokenizer(std::string code_line);
};

#endif