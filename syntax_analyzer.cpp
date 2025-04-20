#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include "syntax_analyzer.h"

syntax_dpda::syntax_dpda() {
    for (int row = 0; row < 22; row++) {
        for (int col = 0; col < 22; col++) {
            state_table[row][col] = 0;
        }
    }
}

void syntax_dpda::initialize_syntax_dpda(std::ifstream& syntax_table_file) {
    std::string line;
    int value;
    int row = 0;

    while (std::getline(syntax_table_file, line) && row < 22) {
        std::istringstream line_input(line);
        for (int col = 0; col < 22; col++) {
            line_input >> value;
            state_table[row][col] = value;
        }
        row += 1;
    }
    syntax_table_file.close();
}

void syntax_dpda::print_syntax_dpda() {
    std::cout << "State Table for Parser:\n";
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 22; j++) {
            std::cout << state_table[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int syntax_dpda::operator_convert(std::string token_name, std::string token_class) {
    if (token_class == "$bottom") {
        return 0;
    }
    else if (token_class == "<assign>") {
        return 1;
    }
    else if (token_name == "+" && token_class == "<addop>") {
        return 2;
    }
    else if (token_name == "-" && token_class == "<addop>") {
        return 3;
    }
    else if (token_class == "$l_paren") {
        return 4;
    }
    else if (token_class == "$r_paren") {
        return 5;
    }
    else if (token_name == "*" && token_class == "<mop>") {
        return 6;
    }
    else if (token_name == "/" && token_class == "<mop>") {
        return 7;
    }
    else if (token_class == "$IF") {
        return 8;
    }
    else if (token_class == "$THEN") {
        return 9;
    }
    else if (token_class == "$ODD") {
        return 10;
    }
    else if (token_name == "==" && token_class == "<relop>") {
        return 11;
    }
    else if (token_name == "!=" && token_class == "<relop>") {
        return 12;
    }
    else if (token_name == ">" && token_class == "<relop>") {
        return 13;
    }
    else if (token_name == "<" && token_class == "<relop>") {
        return 14;
    }
    else if (token_name == ">=" && token_class == "<relop>") {
        return 15;
    }
    else if (token_name == "<=" && token_class == "<relop>") {
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
    else if (token_class == "<var>" || token_class == "<integer>") {
        return 20;
    }
    else if (token_class == "<semi>"){
        return 21;
    }
    else {
        return 22;
    }
}

void syntax_dpda::parse_precedence(std::fstream& token_file, std::fstream& symbol_file, std::fstream& parse_output_file) {
    std::string line;
    std::stack<stack_elements> parsing_stack;
    int next_state = 0;
    bool finished = false;
    bool reprocess_line = false;
    bool if_statement = false;
    std::string saved_line;
    std::string token_name;
    std::string token_class;
    std::string last_op_name = "stack_bottom";
    std::string last_op_class = "$bottom";
    parsing_stack.push(stack_elements{last_op_name, last_op_class, 0});
    int temp_counter = 1;
    int label_counter = 1;
   
    std::string left;
    std::string right;
    std::string op;

    bool skip_declarations = false;

    while (!finished) {
        if (reprocess_line) {
            line = saved_line;
            reprocess_line = false;
        }
        else {
            std::getline(token_file, line);
        }
        std::istringstream line_input(line);
        line_input >> token_name >> token_class;

        std::cout << "Reading line: " << line << std::endl;

        if (token_class == "$CLASS" || token_class == "$CONST" || token_class == "<$var>") {
            skip_declarations = true;
            continue;
        }

        if (skip_declarations) {
            if (token_class == "<semi>") {
                skip_declarations = false;
            }
            continue;
        }

        next_state = state_table[operator_convert(last_op_name, last_op_class)][operator_convert(token_name, token_class)];
        std::cout << "using state_table[" << last_op_name << "][" << token_name << "], which is: " << next_state << std::endl;
        switch(next_state) {
            case 0:
                std::cout << "Invalid syntax!" << std::endl;
                finished = true;
                break;
            case 1:
                std::cout << "In state 1, pushing " << token_name << " to the stack" << std::endl;
                parsing_stack.push(stack_elements{token_name, token_class, 1});
                last_op_name = token_name;
                last_op_class = token_class;
                if (token_class == "$IF") {
                    if_statement = true;
                }
                break;
            case 2:
                std::cout << "In state 2, popping from the stack" << std::endl;
                if (token_class == "$r_brack" && if_statement == true) {
                    if_statement = false;
                    parse_output_file << "L" << std::to_string(label_counter) << ", , ," << std::endl;
                    while (parsing_stack.top().token_class != "$IF") {
                        parsing_stack.pop();
                    }
                    parsing_stack.pop();
                    last_op_name = parsing_stack.top().token;
                    last_op_class = parsing_stack.top().token_class;
                    label_counter++;
                    break;
                }
                right = parsing_stack.top().token;
                parsing_stack.pop();
                op = parsing_stack.top().token;
                parsing_stack.pop();
                left = parsing_stack.top().token;
                parsing_stack.pop();

                last_op_name = parsing_stack.top().token;
                last_op_class = parsing_stack.top().token_class;

                if (op == "+" || op == "-" || op == "*" || op == "/" ) {
                    parse_output_file << op << ", " << left << ", " << right << ", T" << std::to_string(temp_counter) << std::endl;
                    parsing_stack.push(stack_elements{"T" + std::to_string(temp_counter), "<var>", 4});
                    temp_counter += 1;
                }
                else if (op == "=") {
                    parse_output_file << op << ", " << right << ", , " << left << std::endl;
                }
                else if (op == "==" || op == "!=" || op == ">" || op == "<" || op == ">=" || op == "<=") {
                    parse_output_file << op << ", " << left << ", " << right << ", ?" << std::endl;
                }

                std::cout << "Reprocessing token: " << token_name << " " << token_class << std::endl;
                if (parsing_stack.top().token_class != "$bottom") {
                    reprocess_line = true; //to avoid skipping over operators that trigger a reduction
                    saved_line = token_name + " " + token_class;
                    std::cout << "top operator is: " << last_op_name << std::endl;
                }
                break;
            case 3:
                std::cout << "In state 3, pushing " << token_name << " to the stack" << std::endl;
                parsing_stack.push(stack_elements{token_name, token_class, 3});
                last_op_name = token_name;
                last_op_class = token_class;
                if (token_class == "$THEN") {
                    parse_output_file << "THEN, L" << std::to_string(label_counter) << ", ," << std::endl;
                }
                break;
            case 4:
                std::cout << "In state 3, pushing nonterminal " << token_name << " to the stack" << std::endl;
                if (token_class == "<integer>") {
                    parsing_stack.push(stack_elements{"lit" + token_name, "<integer>", 4});
                }
                else {
                    parsing_stack.push(stack_elements{token_name, "<var>", 4});
                }
                break;
            default:
                std::cout << "Error!" << std::endl;
                break;
        }
    }
    
    int address_count = 0;
    std::getline(symbol_file, line); //skip over program name line
    while (std::getline(symbol_file, line)) {
        address_count += 2;
    }

    symbol_file.clear();
    symbol_file.seekp(0, std::ios::end);

    for (int i = 1; i < temp_counter; i++) {
        symbol_file << "T" << i << " tempvar ? " << address_count << " DS" << std::endl;
        address_count += 2;
    }
}