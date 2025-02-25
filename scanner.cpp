#include <iostream>
#include <string>
#include <fstream>
#include "scanner.h"

std::ofstream token_file("token_list.txt");

table_driven_dfsa::table_driven_dfsa() {
    state_table[0][0] = 0; state_table[0][1] = 2; state_table[0][2] = 4; state_table[0][3] = 6; state_table[0][4] = 7; state_table[0][5] = 8; state_table[0][6] = 9; state_table[0][7] = 10; state_table[0][8] = 13; state_table[0][9] = 16; state_table[0][10] = 19; state_table[0][11] = 20; state_table[0][12] = 21; state_table[0][13] = 22; state_table[0][14] = 1;
    state_table[1][0] = 1; state_table[1][1] = 1; state_table[1][2] = 1; state_table[1][3] = 1; state_table[1][4] = 1; state_table[1][5] = 1; state_table[1][6] = 1; state_table[1][7] = 1; state_table[1][8] = 1; state_table[1][9] = 1; state_table[1][10] = 1; state_table[1][11] = 1; state_table[1][12] = 1; state_table[1][13] = 1; state_table[1][14] = 1;
    state_table[2][0] = 3; state_table[2][1] = 2; state_table[2][2] = 3; state_table[2][3] = 3; state_table[2][4] = 3; state_table[2][5] = 3; state_table[2][6] = 3; state_table[2][7] = 3; state_table[2][8] = 3; state_table[2][9] = 3; state_table[2][10] = 3; state_table[2][11] = 3; state_table[2][12] = 3; state_table[2][13] = 3; state_table[2][14] = 1;
    state_table[3][0] = 3; state_table[3][1] = 3; state_table[3][2] = 3; state_table[3][3] = 3; state_table[3][4] = 3; state_table[3][5] = 3; state_table[3][6] = 3; state_table[3][7] = 3; state_table[3][8] = 3; state_table[3][9] = 3; state_table[3][10] = 3; state_table[3][11] = 3; state_table[3][12] = 3; state_table[3][13] = 3; state_table[3][14] = 1;
    state_table[4][0] = 5; state_table[4][1] = 4; state_table[4][2] = 4; state_table[4][3] = 5; state_table[4][4] = 5; state_table[4][5] = 5; state_table[4][6] = 5; state_table[4][7] = 5; state_table[4][8] = 5; state_table[4][9] = 5; state_table[4][10] = 5; state_table[4][11] = 5; state_table[4][12] = 5; state_table[4][13] = 5; state_table[4][14] = 1;
    state_table[5][0] = 5; state_table[5][1] = 5; state_table[5][2] = 5; state_table[5][3] = 5; state_table[5][4] = 5; state_table[5][5] = 5; state_table[5][6] = 5; state_table[5][7] = 5; state_table[5][8] = 5; state_table[5][9] = 5; state_table[5][10] = 5; state_table[5][11] = 5; state_table[5][12] = 5; state_table[5][13] = 5; state_table[5][14] = 1;
    state_table[6][0] = 6; state_table[6][1] = 6; state_table[6][2] = 6; state_table[6][3] = 6; state_table[6][4] = 6; state_table[6][5] = 6; state_table[6][6] = 6; state_table[6][7] = 6; state_table[6][8] = 6; state_table[6][9] = 6; state_table[6][10] = 6; state_table[6][11] = 6; state_table[6][12] = 6; state_table[6][13] = 6; state_table[6][14] = 1;
    state_table[7][0] = 7; state_table[7][1] = 7; state_table[7][2] = 7; state_table[7][3] = 7; state_table[7][4] = 7; state_table[7][5] = 7; state_table[7][6] = 7; state_table[7][7] = 7; state_table[7][8] = 7; state_table[7][9] = 7; state_table[7][10] = 7; state_table[7][11] = 7; state_table[7][12] = 7; state_table[7][13] = 7; state_table[7][14] = 1;
    state_table[8][0] = 8; state_table[8][1] = 8; state_table[8][2] = 8; state_table[8][3] = 8; state_table[8][4] = 8; state_table[8][5] = 8; state_table[8][6] = 8; state_table[8][7] = 8; state_table[8][8] = 8; state_table[8][9] = 8; state_table[8][10] = 8; state_table[8][11] = 8; state_table[8][12] = 8; state_table[8][13] = 8; state_table[8][14] = 1;
    state_table[9][0] = 9; state_table[9][1] = 9; state_table[9][2] = 9; state_table[9][3] = 9; state_table[9][4] = 9; state_table[9][5] = 9; state_table[9][6] = 9; state_table[9][7] = 9; state_table[9][8] = 9; state_table[9][9] = 9; state_table[9][10] = 9; state_table[9][11] = 9; state_table[9][12] = 9; state_table[9][13] = 9; state_table[9][14] = 1;
    state_table[10][0] = 11; state_table[10][1] = 11; state_table[10][2] = 11; state_table[10][3] = 11; state_table[10][4] = 11; state_table[10][5] = 11; state_table[10][6] = 11; state_table[10][7] = 12; state_table[10][8] = 11; state_table[10][9] = 11; state_table[10][10] = 11; state_table[10][11] = 11; state_table[10][12] = 11; state_table[10][13] = 11; state_table[10][14] = 1;
    state_table[11][0] = 11; state_table[11][1] = 11; state_table[11][2] = 11; state_table[11][3] = 11; state_table[11][4] = 11; state_table[11][5] = 11; state_table[11][6] = 11; state_table[11][7] = 11; state_table[11][8] = 11; state_table[11][9] = 11; state_table[11][10] = 11; state_table[11][11] = 11; state_table[11][12] = 11; state_table[11][13] = 11; state_table[11][14] = 1;
    state_table[12][0] = 12; state_table[12][1] = 12; state_table[12][2] = 12; state_table[12][3] = 12; state_table[12][4] = 12; state_table[12][5] = 12; state_table[12][6] = 12; state_table[12][7] = 12; state_table[12][8] = 12; state_table[12][9] = 12; state_table[12][10] = 12; state_table[12][11] = 12; state_table[12][12] = 12; state_table[12][13] = 12; state_table[12][14] = 1;
    state_table[13][0] = 14; state_table[13][1] = 14; state_table[13][2] = 14; state_table[13][3] = 14; state_table[13][4] = 14; state_table[13][5] = 14; state_table[13][6] = 14; state_table[13][7] = 15; state_table[13][8] = 14; state_table[13][9] = 14; state_table[13][10] = 14; state_table[13][11] = 14; state_table[13][12] = 14; state_table[13][13] = 14; state_table[13][14] = 1;
    state_table[14][0] = 14; state_table[14][1] = 14; state_table[14][2] = 14; state_table[14][3] = 14; state_table[14][4] = 14; state_table[14][5] = 14; state_table[14][6] = 14; state_table[14][7] = 14; state_table[14][8] = 14; state_table[14][9] = 14; state_table[14][10] = 14; state_table[14][11] = 14; state_table[14][12] = 14; state_table[14][13] = 14; state_table[14][14] = 1;
    state_table[15][0] = 15; state_table[15][1] = 15; state_table[15][2] = 15; state_table[15][3] = 15; state_table[15][4] = 15; state_table[15][5] = 15; state_table[15][6] = 15; state_table[15][7] = 15; state_table[15][8] = 15; state_table[15][9] = 15; state_table[15][10] = 15; state_table[15][11] = 15; state_table[15][12] = 15; state_table[15][13] = 15; state_table[15][14] = 1;
    state_table[16][0] = 17; state_table[16][1] = 17; state_table[16][2] = 17; state_table[16][3] = 17; state_table[16][4] = 17; state_table[16][5] = 17; state_table[16][6] = 17; state_table[16][7] = 18; state_table[16][8] = 17; state_table[16][9] = 17; state_table[16][10] = 17; state_table[16][11] = 17; state_table[16][12] = 17; state_table[16][13] = 17; state_table[16][14] = 1;
    state_table[17][0] = 17; state_table[17][1] = 17; state_table[17][2] = 17; state_table[17][3] = 17; state_table[17][4] = 17; state_table[17][5] = 17; state_table[17][6] = 17; state_table[17][7] = 17; state_table[17][8] = 17; state_table[17][9] = 17; state_table[17][10] = 17; state_table[17][11] = 17; state_table[17][12] = 17; state_table[17][13] = 17; state_table[17][14] = 1;
    state_table[18][0] = 18; state_table[18][1] = 18; state_table[18][2] = 18; state_table[18][3] = 18; state_table[18][4] = 18; state_table[18][5] = 18; state_table[18][6] = 18; state_table[18][7] = 18; state_table[18][8] = 18; state_table[18][9] = 18; state_table[18][10] = 18; state_table[18][11] = 18; state_table[18][12] = 18; state_table[18][13] = 18; state_table[18][14] = 1; 
    state_table[19][0] = 19; state_table[19][1] = 19; state_table[19][2] = 19; state_table[19][3] = 19; state_table[19][4] = 19; state_table[19][5] = 19; state_table[19][6] = 19; state_table[19][7] = 19; state_table[19][8] = 19; state_table[19][9] = 19; state_table[19][10] = 19; state_table[19][11] = 19; state_table[19][12] = 19; state_table[19][13] = 19; state_table[19][14] = 1; 
    state_table[20][0] = 20; state_table[20][1] = 20; state_table[20][2] = 20; state_table[20][3] = 20; state_table[20][4] = 20; state_table[20][5] = 20; state_table[20][6] = 20; state_table[20][7] = 20; state_table[20][8] = 20; state_table[20][9] = 20; state_table[20][10] = 20; state_table[20][11] = 20; state_table[20][12] = 20; state_table[20][13] = 20; state_table[20][14] = 1; 
    state_table[21][0] = 21; state_table[21][1] = 21; state_table[21][2] = 21; state_table[21][3] = 21; state_table[21][4] = 21; state_table[21][5] = 21; state_table[21][6] = 21; state_table[21][7] = 21; state_table[21][8] = 21; state_table[21][9] = 21; state_table[21][10] = 21; state_table[21][11] = 21; state_table[21][12] = 21; state_table[21][13] = 21; state_table[21][14] = 1; 
    state_table[22][0] = 22; state_table[22][1] = 22; state_table[22][2] = 22; state_table[22][3] = 22; state_table[22][4] = 22; state_table[22][5] = 22; state_table[22][6] = 22; state_table[22][7] = 22; state_table[22][8] = 22; state_table[22][9] = 22; state_table[22][10] = 22; state_table[22][11] = 22; state_table[22][12] = 22; state_table[22][13] = 22; state_table[22][14] = 1; 
    state_table[23][0] = 23; state_table[23][1] = 23; state_table[23][2] = 23; state_table[23][3] = 23; state_table[23][4] = 23; state_table[23][5] = 23; state_table[23][6] = 23; state_table[23][7] = 23; state_table[23][8] = 23; state_table[23][9] = 23; state_table[23][10] = 23; state_table[23][11] = 23; state_table[23][12] = 23; state_table[23][13] = 23; state_table[23][14] = 1; 
    state_table[24][0] = 24; state_table[24][1] = 24; state_table[24][2] = 24; state_table[24][3] = 24; state_table[24][4] = 24; state_table[24][5] = 24; state_table[24][6] = 24; state_table[24][7] = 24; state_table[24][8] = 24; state_table[24][9] = 24; state_table[24][10] = 24; state_table[24][11] = 24; state_table[24][12] = 24; state_table[24][13] = 24; state_table[24][14] = 1; 
    state_table[25][0] = 25; state_table[25][1] = 25; state_table[25][2] = 25; state_table[25][3] = 25; state_table[25][4] = 25; state_table[25][5] = 25; state_table[25][6] = 25; state_table[25][7] = 25; state_table[25][8] = 25; state_table[25][9] = 25; state_table[25][10] = 25; state_table[25][11] = 25; state_table[25][12] = 25; state_table[25][13] = 25; state_table[25][14] = 1; 
    state_table[26][0] = 26; state_table[26][1] = 26; state_table[26][2] = 26; state_table[26][3] = 26; state_table[26][4] = 26; state_table[26][5] = 26; state_table[26][6] = 26; state_table[26][7] = 26; state_table[26][8] = 26; state_table[26][9] = 26; state_table[26][10] = 26; state_table[26][11] = 26; state_table[26][12] = 26; state_table[26][13] = 26; state_table[26][14] = 1; 
    state_table[27][0] = 27; state_table[27][1] = 27; state_table[27][2] = 27; state_table[27][3] = 27; state_table[27][4] = 27; state_table[27][5] = 27; state_table[27][6] = 27; state_table[27][7] = 27; state_table[27][8] = 27; state_table[27][9] = 27; state_table[27][10] = 27; state_table[27][11] = 27; state_table[27][12] = 27; state_table[27][13] = 27; state_table[27][14] = 1; 
    state_table[28][0] = 28; state_table[28][1] = 28; state_table[28][2] = 28; state_table[28][3] = 28; state_table[28][4] = 28; state_table[28][5] = 28; state_table[28][6] = 28; state_table[28][7] = 28; state_table[28][8] = 28; state_table[28][9] = 28; state_table[28][10] = 28; state_table[28][11] = 28; state_table[28][12] = 28; state_table[28][13] = 28; state_table[28][14] = 1; 
    state_table[29][0] = 29; state_table[29][1] = 29; state_table[29][2] = 29; state_table[29][3] = 29; state_table[29][4] = 29; state_table[29][5] = 29; state_table[29][6] = 29; state_table[29][7] = 29; state_table[29][8] = 29; state_table[29][9] = 29; state_table[29][10] = 29; state_table[29][11] = 29; state_table[29][12] = 29; state_table[29][13] = 29; state_table[29][14] = 1; 
    state_table[30][0] = 30; state_table[30][1] = 30; state_table[30][2] = 30; state_table[30][3] = 30; state_table[30][4] = 30; state_table[30][5] = 30; state_table[30][6] = 30; state_table[30][7] = 30; state_table[30][8] = 30; state_table[30][9] = 30; state_table[30][10] = 30; state_table[30][11] = 30; state_table[30][12] = 30; state_table[30][13] = 30; state_table[30][14] = 1; 
    state_table[31][0] = 31; state_table[31][1] = 31; state_table[31][2] = 31; state_table[31][3] = 31; state_table[31][4] = 31; state_table[31][5] = 31; state_table[31][6] = 31; state_table[31][7] = 31; state_table[31][8] = 31; state_table[31][9] = 31; state_table[31][10] = 31; state_table[31][11] = 31; state_table[31][12] = 31; state_table[31][13] = 31; state_table[31][14] = 1; 
    state_table[32][0] = 32; state_table[32][1] = 32; state_table[32][2] = 32; state_table[32][3] = 32; state_table[32][4] = 32; state_table[32][5] = 32; state_table[32][6] = 32; state_table[32][7] = 32; state_table[32][8] = 32; state_table[32][9] = 32; state_table[32][10] = 32; state_table[32][11] = 32; state_table[32][12] = 32; state_table[32][13] = 32; state_table[32][14] = 1; 
}

table_driven_dfsa::table_driven_dfsa(int tab_data[]) {
    for(int row = 0; row < 33; row++) {
        for(int col = 0; col < 15; col++) {
            state_table[row][col] = tab_data[row*15+col];
        }
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
    else if (current_char == '{') {
        return 10;
    }
    else if (current_char == '}') {
        return 11;
    }
    else if (current_char == ';') {
        return 12;
    }
    else if (current_char == ',') {
        return 13;
    }
    else {
        return 14;
    }    
}

void table_driven_dfsa::tokenizer(std::string code_line) {
    int next_state = 0;
    std::string current_token;

        for(int i = 0; i < code_line.length(); i++) {
            char current_char = code_line[i];
            current_token += current_char;
    
            switch (next_state) {
                case 0: next_state = state_table[0][char_convert(current_char)];
                    break;
                case 1: std::cout << "Illegal token!" << std::endl;
                    return;
                case 2: next_state = state_table[2][char_convert(current_char)];
                    break;
                case 3: token_file << current_token << " Integer" << std::endl; //Integer
                    current_token.clear();
                    break;
                case 4: next_state = state_table[4][char_convert(current_char)];
                    break;
                case 5: token_file << current_token << " Variable" << std::endl; //Variable
                    current_token.clear();    
                    break;
                case 6: token_file << current_token << " <mop>" << std::endl; //*
                    current_token.clear();
                    break;
                case 7: token_file << current_token << " <mop>" << std::endl; // /
                    current_token.clear();
                    break;
                case 8: token_file << current_token << " <addop>" << std::endl; //+
                    current_token.clear();
                    break;
                case 9: token_file << current_token << " <addop>" << std::endl; //-
                    current_token.clear();
                    break;
                case 10: next_state = state_table[10][char_convert(current_char)];
                    break;
                case 11: token_file << current_token << " <assign>" << std::endl; //=
                    current_token.clear();
                    break;
                case 12: token_file << current_token << " <relop>" << std::endl; //==
                    current_token.clear();
                    break;
                case 13: next_state = state_table[13][char_convert(current_char)];
                    break;
                case 14: token_file << current_token << " <relop>" << std::endl; //>
                    current_token.clear();
                    break;
                case 15: token_file << current_token << " <relop>" << std::endl; //>=
                    current_token.clear();
                    break;
                case 16: next_state = state_table[16][char_convert(current_char)];
                    break;
                case 17: token_file << current_token << " <relop>" << std::endl; //<
                    current_token.clear();
                    break;
                case 18: token_file << current_token << " <relop>" << std::endl; //<=
                    current_token.clear();
                    break;
                case 19: token_file << current_token << " l_brack" << std::endl; //{
                    current_token.clear();
                    break;
                case 20: token_file << current_token << " r_brack" << std::endl; //}
                    current_token.clear();
                    break;
                case 21: token_file << current_token << " semi" << std::endl; //;
                    current_token.clear();
                    break;
                case 22: token_file << current_token << " comma" << std::endl; //,
                    current_token.clear();
                    break;
                case 23: token_file << current_token << " $if" << std::endl;
                    current_token.clear();
                    break;
                case 24: token_file << current_token << " $then" << std::endl;
                    current_token.clear();
                    break;
                case 25: token_file << current_token << " $const" << std::endl;
                    current_token.clear();
                    break;
                case 26: token_file << current_token << " $class" << std::endl;
                    current_token.clear();
                    break;
                case 27: token_file << current_token << " var_declare" << std::endl;
                    current_token.clear();
                    break;
                case 28: token_file << current_token << " $procedure" << std::endl;
                    current_token.clear();
                    break;
                case 29: token_file << current_token << " $while" << std::endl;
                    current_token.clear();
                    break;
                case 30: token_file << current_token << " $call" << std::endl;
                    current_token.clear();
                    break;
                case 31: token_file << current_token << " $do" << std::endl;
                    current_token.clear();
                    break;
                case 32: token_file << current_token << " $odd" << std::endl;
                    current_token.clear();
                    break;
                default: std::cout << "Illegal input!" << std::endl;
                    return;
            }
        }
}