#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include "scanner.h"

std::set<std::string> reserved_words = {"IF", "THEN", "ELSE", "CONST", "CLASS", "VAR", "PROCEDURE", "WHILE", "CALL", "DO", "ODD"};

table_driven_dfsa::table_driven_dfsa() {
    for(int row = 0; row < 41; row++) {
        for(int col = 0; col < 18; col++) {
            state_table[row][col] = 0;
        }
    }
}

void table_driven_dfsa::initialize_table_dfsa(std::ifstream& table_file) {
    std::string line;
    int value;
    int row = 0;

    while (std::getline(table_file, line) && row < 41) {
        std::istringstream line_input(line);
        for (int col = 0; col < 18; col++) {
            line_input >> value;
            state_table[row][col] = value;
        }
        row += 1;
    }
    table_file.close();
}

symbol_table_dfsa::symbol_table_dfsa() {
    for(int row = 0; row < 14; row++) {
        for(int col = 0; col < 24; col++) {
            state_table2[row][col] = 0;
        }
    }
}

void symbol_table_dfsa::initialize_symbol_dfsa(std::ifstream& table_file2) {
    std::string line;
    int value;
    int row = 0;

    while (std::getline(table_file2, line) && row < 14) {
        std::istringstream line_input(line);
        for (int col = 0; col < 24; col++) {
            line_input >> value;
            state_table2[row][col] = value;
        }
        row += 1;
    }
    table_file2.close();
}


void table_driven_dfsa::print_state_table() {
    std::cout << "State Table for Tokenizer:\n";
    for (int i = 0; i < 41; i++) {
        for (int j = 0; j < 18; j++) {
            std::cout << state_table[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void symbol_table_dfsa::print_state_table() {
    std::cout << "State Table for Symbol Table:\n";
    for (int row = 0; row < 14; row++) {
        for (int col = 0; col < 24; col++) {
            std::cout << state_table2[row][col] << " ";
        }
        std::cout << std::endl;
    }
}



int table_driven_dfsa::char_convert(char current_char) {
    if (current_char == ' ') {
        return 0;
    }
    else if (current_char >= '0' && current_char <= '9') {
        return 1;
    }
    else if ((current_char >= 'a' && current_char <= 'z') || (current_char >= 'A' && current_char <= 'Z')) {
        return 2;
    }
    else if (current_char == '*') {
        return 3;
    }
    else if (current_char == '/') {
        return 4;
    }
    else if (current_char == '+') {
        return 5;
    }
    else if (current_char == '-') {
        return 6;
    }
    else if (current_char == '=') {
        return 7;
    }
    else if (current_char == '>') {
        return 8;
    }
    else if (current_char == '<') {
        return 9;
    }
    else if (current_char == '!') {
        return 10;
    }
    else if (current_char == '{') {
        return 11;
    }
    else if (current_char == '}') {
        return 12;
    }
    else if (current_char == '(') {
        return 13;
    }
    else if (current_char == ')') {
        return 14;
    }
    else if (current_char == ';') {
        return 15;
    }
    else if (current_char == ',') {
        return 16;
    }
    else {
        return 17;
    }    
}

int table_driven_dfsa::reserved_convert(std::string current_token) {
    if (current_token == "IF") {
        return 30;
    }
    else if (current_token == "THEN") {
        return 31;
    }
    else if (current_token == "ELSE") {
        return 32;
    }
    else if (current_token == "CONST") {
        return 33;
    }
    else if (current_token == "CLASS") {
        return 34;
    }
    else if (current_token == "VAR") {
        return 35;
    }
    else if (current_token == "PROCEDURE") {
        return 36;
    }
    else if (current_token == "WHILE") {
        return 37;
    }
    else if (current_token == "CALL") {
        return 38;
    }
    else if (current_token == "DO") {
        return 39;
    }
    else if (current_token == "ODD") {
        return 40;
    }
    else {
        return 1;
    }
}

int symbol_table_dfsa::token_convert(std::string s_token) {
    if (s_token == "$CLASS") {
        return 0;
    }
    else if (s_token == "<var>") {
        return 1;
    }
    else if (s_token == "$l_brack") {
        return 2;
    }
    else if (s_token == "$CONST") {
        return 3;
    }
    else if (s_token == "<assign>") {
        return 4;
    }
    else if (s_token == "<integer>") {
        return 5;
    }
    else if (s_token == "<semi>") {
        return 6;
    }
    else if (s_token == "<$var>") {
        return 7;
    }
    else if (s_token == "<comma>") {
        return 8;
    }
    else if (s_token == "IF") {
        return 9;
    }
    else if (s_token == "$THEN") {
        return 10;
    }
    else if (s_token == "$ELSE") {
        return 11;
    }
    else if (s_token == "$PROCEDURE") {
        return 12;
    }
    else if (s_token == "$WHILE") {
        return 13;
    }
    else if (s_token == "$CALL") {
        return 14;
    }
    else if (s_token == "$DO") {
        return 15;
    }
    else if (s_token == "$ODD") {
        return 16;
    }
    else if (s_token == "$l_paren") {
        return 17;
    }
    else if (s_token == "$r_paren") {
        return 18;
    }
    else if (s_token == "$r_brack") {
        return 19;
    }
    else if (s_token == "<addop>") {
        return 20;
    }
    else if (s_token == "<mop>") {
        return 21;
    }
    else if (s_token == "<relop>") {
        return 22;
    }
    else {
        return 23;
    }
}

std::string table_driven_dfsa::clean_token(std::string current_token) {
    for (int i = 0; i < current_token.length(); i++) {
        if (current_token[i] == ' ') {
            current_token.erase(i, 1);
            i--;
        }
    }
    
    //current_token.erase(remove(current_token.begin(), current_token.end(), ' '), current_token.end());
    
    if (current_token.size() > 1) { //To remove trailing delimiters without affecting standalone delimiter tokens
        if (current_token.back() == ';' || current_token.back() == ',' || current_token.back() == '(') {
            current_token.pop_back();
        }
    }
    return current_token;
}

void table_driven_dfsa::tokenizer(std::string code_line, std::fstream& token_file) {
    int next_state = 0;
    int line_index = 0;
    std::string current_token;

        while (line_index < code_line.length()) {
            char current_char = code_line[line_index];

            std::cout << "On character: " << current_char << ", collected token: " << current_token << ", next state: " << next_state << std::endl;
    
            switch (next_state) {
                case 0:
                    current_token += current_char;
                    next_state = state_table[0][char_convert(current_char)];
                    line_index++;
                    break;
                case 1:
                    std::cout << "Illegal token!" << std::endl;
                    return;
                case 2:
                    next_state = state_table[2][char_convert(current_char)];
                    current_token += current_char;
                    line_index++;
                    break;
                case 3:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <integer>" << std::endl; //Integer
                    std::cout << "Inputting token: " << current_token << "with type Integer" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 4:
                    current_token += current_char;
                    next_state = state_table[4][char_convert(current_char)];
                    line_index++;
                    break;
                case 5:
                    line_index--;
                    current_token = clean_token(current_token);
                    if (reserved_words.find(current_token) != reserved_words.end()) {
                        next_state = state_table[reserved_convert(current_token)][0];
                        break;
                    }
                    else {
                        token_file << current_token << " <var>" << std::endl; //Variable
                        std::cout << "Inputting token: " << current_token << "with type Variable" << std::endl;
                        current_token.clear();    
                        next_state = 0;
                        std::cout << "The next state is: " << next_state << std::endl;
                        break;
                    }
                case 6: 
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <mop>" << std::endl; //*
                    std::cout << "Inputting token: " << current_token << "with type <mop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 7:
                    current_token += current_char;
                    next_state = state_table[7][char_convert(current_char)];
                    line_index++;
                    break;
                case 8:
                    current_token += current_char;
                    next_state = state_table[8][char_convert(current_char)];
                    line_index++;
                    break;
                case 9:
                    current_token += current_char;
                    next_state = state_table[9][char_convert(current_char)];
                    line_index++;
                    break;
                case 10:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <mop>" << std::endl; // /
                    std::cout << "Inputting token: " << current_token << "with type <mop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 11:
                    line_index--;
                    current_token = clean_token(current_token);  
                    token_file << current_token << " <addop>" << std::endl; //+
                    std::cout << "Inputting token: " << current_token << "with type <addop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 12:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <addop>" << std::endl; //-
                    std::cout << "Inputting token: " << current_token << "with type <addop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 13:
                    next_state = state_table[13][char_convert(current_char)];
                    current_token += current_char;
                    line_index++;
                    break;
                case 14:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <assign>" << std::endl; //=
                    std::cout << "Inputting token: " << current_token << "with type <assign>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 15:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <relop>" << std::endl; //==
                    std::cout << "Inputting token: " << current_token << "with type <relop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 16:
                    next_state = state_table[16][char_convert(current_char)];
                    current_token += current_char;
                    line_index++;
                    break;
                case 17:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <relop>" << std::endl; //>
                    std::cout << "Inputting token: " << current_token << "with type <relop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 18:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <relop>" << std::endl; //>=
                    std::cout << "Inputting token: " << current_token << "with type <relop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 19:
                    next_state = state_table[19][char_convert(current_char)];
                    current_token += current_char;
                    line_index++;
                    break;
                case 20:
                    next_state = state_table[20][char_convert(current_char)];
                    current_token += current_char;
                    line_index++;
                    break;
                case 21:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <relop>" << std::endl; //<
                    std::cout << "Inputting token: " << current_token << "with type <relop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 22:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <relop>" << std::endl; //<=
                    std::cout << "Inputting token: " << current_token << "with type <relop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 23:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " <relop>" << std::endl; //!=
                    std::cout << "Inputting token: " << current_token << "with type <relop>" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 24:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " $l_brack" << std::endl; //{
                    std::cout << "Inputting token: " << current_token << "with type l_brack" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 25:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " $r_brack" << std::endl; //}
                    std::cout << "Inputting token: " << current_token << "with type r_brack" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 26:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " $l_paren" << std::endl; //(
                    std::cout << "Inputting token: " << current_token << "with type l_paren" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 27:
                    line_index--;
                    current_token = clean_token(current_token);
                    token_file << current_token << " $r_paren" << std::endl; //)
                    std::cout << "Inputting token: " << current_token << "with type r_paren" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    line_index++;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 28:
                    current_token = clean_token(current_token);
                    token_file << current_token << " <semi>" << std::endl; //;
                    std::cout << "Inputting token: " << current_token << "with type semi" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 29:
                    current_token = clean_token(current_token);
                    token_file << current_token << " <comma>" << std::endl; //,
                    std::cout << "Inputting token: " << current_token << "with type comma" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    std::cout << "The next state is: " << next_state << std::endl;
                    break;
                case 30:
                    token_file << current_token << " $IF" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type IF" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 31:
                    token_file << current_token << " $THEN" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type THEN" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 32:
                    token_file << current_token << " $ELSE" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type ELSE" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 33:
                    token_file << current_token << " $CONST" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type CONST" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 34:
                    token_file << current_token << " $CLASS" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type CLASS" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 35:
                    token_file << current_token << " <$var>" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type VAR DECLARE" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 36:
                    token_file << current_token << " $PROCEDURE" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type PROCEDURE" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 37:
                    token_file << current_token << " $WHILE" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type WHILE" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 38:
                    token_file << current_token << " $CALL" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type CALL" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 39:
                    token_file << current_token << " $DO" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type DO" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                case 40:
                    token_file << current_token << " $ODD" << std::endl;
                    std::cout << "Inputting token: " << current_token << "with type ODD" << std::endl;
                    current_token.clear();
                    next_state = 0;
                    break;
                default:
                    std::cout << "Illegal input!" << std::endl;
                    return;
            }
        }    
}

void symbol_table_dfsa::create_sym_table(std::fstream& token_file, std::fstream& symbol_file) {
    int next_state = 0;
    int current_address_value = 0;
    std::string line;
    std::string s_token;
    std::string s_class;
    
    while (std::getline(token_file, line)) {
        std::istringstream line_input(line);
        line_input >> s_token >> s_class;
        switch (next_state) {
            case 0:
                next_state = state_table2[0][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 1:
                symbol_file << s_token << " <Program Name> 0 " << current_address_value << " CS" << std::endl;
                next_state = state_table2[1][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 2:
                next_state = state_table2[2][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 3:
                next_state = state_table2[3][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 4:
                symbol_file << s_token << " $CONST ";
                next_state = state_table2[4][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 5:
                next_state = state_table2[5][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 6:
                symbol_file << s_token;
                next_state = state_table2[6][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 7:
                symbol_file << " " << current_address_value << " DS" << std::endl;
                current_address_value += 2;
                next_state = state_table2[7][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 8:
                symbol_file << s_token << " <var> ? " << current_address_value << " DS" << std::endl;
                next_state = state_table2[8][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 9:
                next_state = state_table2[9][token_convert(s_class)];
                current_address_value += 2;
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 10:
                next_state = state_table2[10][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                if (s_class == "<integer>") {
                    symbol_file << "lit" << s_token << " " << s_class << " " << s_token << " " << current_address_value << " DS" << std::endl;
                }
                break;
            case 11:
                current_address_value += 2;
                next_state = state_table2[11][token_convert(s_class)];
                std::cout << "Reading token's class: " << s_class << ", Next state is: " << next_state << std::endl;
                break;
            case 12:
                break;
            case 13:
                std::cout << "Error! with token " << s_token << std::endl;
        }
    }
}