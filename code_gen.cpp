#include <iostream>
#include <fstream>
#include <sstream>
#include "code_gen.h"

std::string line;
std::string token, type, value, address, segment;
std::string op, left, right, target;
std::string then, label;

void Code_Generator::generate_asm_file(std::fstream& parse_output_file, std::fstream& symbol_file, std::fstream& assembly_file) {
    assembly_file << "sys_exit equ 1\n"
                  << "sys_read equ 3\n"
                  << "sys_write equ 4\n"
                  << "stdin equ 0\n"
                  << "stdout equ 1\n"
                  << "stderr equ 3\n" << std::endl;

    assembly_file << "section .data" << std::endl;
    while (std::getline(symbol_file, line)) {
        std::istringstream line_input(line);
        line_input >> token >> type >> value >> address >> segment;

        if (segment == "CS") {
            continue;
        }
        else if (type == "$CONST" || type == "<integer>") {
            assembly_file << token << " DW " << value << std::endl;
        }
    }

    assembly_file << "section .bss" << std::endl;
    symbol_file.clear();
    symbol_file.seekg(0, std::ios::beg);
    while (std::getline(symbol_file, line)) {
        std::istringstream line_input(line);
        line_input >> token >> type >> value >> address >> segment;

        if (segment == "CS") {
            continue;
        }
        else if (type == "<var>" || type == "tempvar") {
            assembly_file << token << " RESW 1" << std::endl;
        }
    }

    assembly_file << "global _start\n" 
                  << "section .text\n" << std::endl
                  << "_start:\n";
    while (std::getline(parse_output_file, line)) {
        std::istringstream line_input(line);
        line_input >> op >> left >> right >> target;

        op.pop_back(); //remove comma
        left.pop_back();
        right.pop_back();

        if (op == "+") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "add ax, [" << right << "]\n"
                          << "mov [" << target << "], ax" << std::endl;
        }
        else if (op == "-") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "sub ax, [" << right << "]\n"
                          << "mov [" << target << "], ax" << std::endl;
        }
        else if (op == "*") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "mul [" << right << "]\n"
                          << "mov [" << target << "], ax" << std::endl;
        }
        else if (op == "/") {
            assembly_file << "mov dx, 0\n"
                          << "mov ax, [" << left << "]\n"
                          << "mov bx, [" << right << "]\n"
                          << "div bx\n"
                          << "mov [" << target << "], ax" << std::endl;
        } 
        else if (op == "=") {
            assembly_file << "mov ax, [" << left << "]" << std::endl;
            assembly_file << "mov [" << target << "], ax" << std::endl;
        }
        else if (op == "==") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line); //for THEN
            std::istringstream then_quad(line);
            line_input >> then >> label;
            assembly_file << "JNE " << label << std::endl;
        }
        else if (op == "!=") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            line_input >> then >> label;
            assembly_file << "JE " << label << std::endl;
        }
        else if (op == ">") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            line_input >> then >> label;
            assembly_file << "JLE " << label << std::endl;
        }
        else if (op == "<") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            line_input >> then >> label;
            assembly_file << "JGE " << label << std::endl;
        }
        else if (op == ">=") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            line_input >> then >> label;
            assembly_file << "JL " << label << std::endl;
        }
        else if (op == "<=") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            line_input >> then >> label;
            assembly_file << "JG " << label << std::endl;
        }
        else if (op[0] == 'L') {
            assembly_file << op << ": nop" << std::endl;
        }
    }
    
    assembly_file << "mov eax, sys_exit\n"
                  << "xor ebx, ebx\n"
                  << "int 80h" << std::endl;
}