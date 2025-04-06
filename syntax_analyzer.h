#ifndef SYNTAX_ANALYZER
#define SYNTAX_ANALYZER

#include <iostream>
#include <fstream>

struct stack_elements {
    std::string token;
    std::string token_class;
    int precedence; //Uses 0 for no function, 1 for '<', 2 for '>', 3 for '=', 4 for nonterminal
};

class syntax_dpda {
    private:
        int state_table[20][20];
    public:
        syntax_dpda();
        void initialize_syntax_dpda(std::ifstream& syntax_table_file);
        int operator_convert(std::string token_name, std::string token_class);
        void parse_precedence(std::ifstream& token_file, std::ifstream& symbol_file, std::fstream& parse_output_file);

};

#endif