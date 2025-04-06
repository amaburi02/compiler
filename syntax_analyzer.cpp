#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include "syntax_analyzer.h"

syntax_dpda::syntax_dpda() {
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            state_table[row][col] = 0;
        }
    }
}

void syntax_dpda::initialize_syntax_dpda(std::ifstream& syntax_table_file) {
    std::string line;
    int value;
    int row = 0;

    while (std::getline(syntax_table_file, line) && row < 20) {
        std::istringstream line_input(line);
        for (int col = 0; col < 20; col++) {
            line_input >> value;
            state_table[row][col] = value;
        }
        row += 1;
    }
    syntax_table_file.close();
}

int syntax_dpda::operator_convert(std::string token_name, std::string token_class) {
    if (token_class == "$CLASS") {
        return 0;
    }
    else if (token_class == "<assign>") {
        return 1;
    }
    else if (token_class == "<addop>") { //+
        return 2;
    }
    else if (token_class == "<addop>") { //-
        return 3;
    }
    else if (token_class == "$l_paren") {
        return 4;
    }
    else if (token_class == "$r_paren") {
        return 5;
    }
    else if (token_class == "<mop>") { //*
        return 6;
    }
    else if (token_class == "<mop>") { // /
        return 7;
    }
    else if (token_class == "IF") {
        return 8;
    }
    else if (token_class == "$THEN") {
        return 9;
    }
    else if (token_class == "$ODD") {
        return 10;
    }
    else if (token_class == "<relop>") { //==
        return 11;
    }
    else if (token_class == "<relop>") { //!=
        return 12;
    }
    else if (token_class == "<relop>") { //>
        return 13;
    }
    else if (token_class == "<relop>") { //<
        return 14;
    }
    else if (token_class == "<relop>") { //>=
        return 15;
    }
    else if (token_class == "<relop>") { //<=
        return 16;
    }
    else if (token_class == "$l_brack") {
        return 17;
    }
    else if (token_class == "$r_brack") {
        return 18;
    }
    else if (token_class == "$CALL") {
        return 19;
    }
}

void syntax_dpda::parse_precedence(std::ifstream& token_file, std::ifstream& symbol_file, std::fstream& parse_output_file) {
    std::string line;
    std::stack<stack_elements> parsing_stack;
    int next_state = 0;
    std::string token_name;
    std::string token_class;
    std::string last_op_name = "CLASS";
    std::string last_op_class = "$CLASS";
    int prec_head;
    int temp_counter = 0;

    std::string temp_left_nonterminal;
    std::string temp_right_nonterminal;

    while (std::getline(token_file, line)) {
        std::istringstream line_input(line);
        line_input >> token_name >> token_class;

        switch(next_state) {
            case 0:
                std::cout << "Invalid syntax!" << std::endl;
                break;
            case 1:
                parsing_stack.push(stack_elements{token_name, token_class, 1});
                prec_head = 1;
                next_state = state_table[operator_convert(last_op_name, last_op_class)][operator_convert(token_name, token_class)];
                break;
            case 2:
                temp_right_nonterminal = parsing_stack.top().token;
                parsing_stack.pop();

                if (parsing_stack.top().token == "+") {
                    parse_output_file << "mov ax,[" << temp_right_nonterminal << "]" << std::endl;
                    temp_left_nonterminal = parsing_stack.top().token;
                    parsing_stack.pop();
                    parse_output_file << "add ax,[ " << temp_left_nonterminal << "]" << std::endl;
                    parse_output_file << "mov [T" << temp_counter << "], ax" << std::endl;
                }
                else if (parsing_stack.top().token == "-") {
                    parse_output_file << "mov ax,[" << temp_right_nonterminal << "]" << std::endl;
                    temp_left_nonterminal = parsing_stack.top().token;
                    parsing_stack.pop();
                    parse_output_file << "sub ax,[ " << temp_left_nonterminal << "]" << std::endl;
                    parse_output_file << "mov [T" << temp_counter << "], ax" << std::endl;
                }
                else if (parsing_stack.top().token == "*") {
                    parse_output_file << "mov ax,[" << temp_right_nonterminal << "]" << std::endl;
                    temp_left_nonterminal = parsing_stack.top().token;
                    parsing_stack.pop();
                    parse_output_file << "mul ax,[ " << temp_left_nonterminal << "]" << std::endl;
                    parse_output_file << "mov [T" << temp_counter << "], ax" << std::endl;
                }
                else if (parsing_stack.top().token == "/") {

                }
                else if (parsing_stack.top().token == "=") {
                    
                }
                temp_counter += 1;
                /*while (parsing_stack.top().precedence != prec_head) {
                    parsing_stack.pop();
                }*/
                last_op_name = parsing_stack.top().token;
                last_op_class = parsing_stack.top().token_class;
                prec_head = parsing_stack.top().precedence;
                parsing_stack.push(stack_elements{"T" + std::to_string(temp_counter), "temp_var", 4});
                next_state = state_table[operator_convert(last_op_name, last_op_class)][operator_convert(token_name, token_class)];
                break;
            case 3:
                parsing_stack.push(stack_elements{token_name, token_class, 3});
                prec_head = 3;
                next_state = state_table[operator_convert(last_op_name, last_op_class)][operator_convert(token_name, token_class)];
                break;
            default:
                parsing_stack.push(stack_elements{token_name, "nonterminal", 4});
                break;
        }
    }
}