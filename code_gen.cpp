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
    assembly_file << "userMsg db 'Enter an integer(less than 32,765)'\n"
                  << "lenUserMsg equ $-userMsg\n"
                  << "displayMsg db 'You entered: '\n"
                  << "lenDisplayMsg equ $-displayMsg\n"
                  << "newline db 0xA\n"
                  << "Ten DW 10\n"
                  << "printTempchar db 'Tempchar=:'\n"
                  << "lenprintTempchar equ $-printTempchar\n"
                  << "Result db 'Ans = '\n"
                  << "ResultValue db 'aaaaa'\n"
                  << "db 0xA\n"
                  << "ResultEnd equ $-Result\n"
                  << "num times 6 db 'ABCDEF'\n"
                  << "numEnd equ $-num" << std::endl;
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

    assembly_file << "section .bss" << std::endl
                  << "TempChar RESB 1\n"
                  << "testchar RESB 1\n"
                  << "ReadInt RESW 1\n"
                  << "tempint RESW 1\n"
                  << "negflag RESB 1\n" << std::endl;
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

    assembly_file << "global _start" << std::endl 
                  << "section .text\n"
                  << "PrintString:\n"
                  << "push ax\n"
                  << "push dx\n"
                  << "mov eax, 4\n"
                  << "mov ebx, 1\n"
                  << "mov ecx, userMsg\n"
                  << "mov edx, lenUserMsg\n"
                  << "int 80h\n"
                  << "pop dx\n"
                  << "pop ax\n"
                  << "ret" << std::endl
                  << "GetAnInteger:\n"
                  << "mov eax, 3\n"
                  << "mov ebx, 2\n"
                  << "mov ecx, num\n"
                  << "mov edx, 6\n"
                  << "int 0x80\n"
                  << "mov edx, eax\n"
                  << "mov eax, 4\n"
                  << "mov ebx, 1\n"
                  << "mov ecx, num\n"
                  << "int 80h" << std::endl
                  << "ConvertStringToInteger:\n"
                  << "mov ax, 0\n"
                  << "mov [ReadInt], ax\n"
                  << "mov ecx, num\n"
                  << "mov bx, 0\n"
                  << "mov bl, byte [ecx]\n"
                  << "Next: sub bl, '0'\n"
                  << "mov ax, [ReadInt]\n"
                  << "mov dx, 10\n"
                  << "mul dx\n"
                  << "add ax, bx\n"
                  << "mov [ReadInt], ax\n"
                  << "mov bx, 0\n"
                  << "add ecx, 1\n"
                  << "mov bl, byte[ecx]\n"
                  << "cmp bl,0xA\n"
                  << "jne Next\n"
                  << "ret" << std::endl
                  << "ConvertIntegerToString:\n"
                  << "mov ebx, ResultValue + 4\n"
                  << "ConvertLoop:\n"
                  << "sub dx, dx\n"
                  << "mov cx, 10\n"
                  << "div cx\n"
                  << "add dl, '0'\n"
                  << "mov [ebx], dl\n"
                  << "dec ebx\n"
                  << "cmp ebx, ResultValue\n"
                  << "jge ConvertLoop\n"
                  << "ret" << std::endl
                  << "_start:\n";
    symbol_file.clear();
    symbol_file.seekg(0, std::ios::beg);
    while (std::getline(symbol_file, line)) { //find uninitialized variables for user input
        std::istringstream line_input(line);
        line_input >> token >> type >> value >> address >> segment;
        
        if (type == "<var>") {
            assembly_file << "call PrintString\n"
                          << "call GetAnInteger\n"
                          << "mov ax, [ReadInt]\n"
                          << "mov [" << token << "], ax" << std::endl;
        }
    }
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
                          << "mul word [" << right << "]\n"
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
            then_quad >> then >> label;
            label.pop_back();
            assembly_file << "JNE " << label << std::endl;
        }
        else if (op == "!=") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            then_quad >> then >> label;
            label.pop_back();
            assembly_file << "JE " << label << std::endl;
        }
        else if (op == ">") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            then_quad >> then >> label;
            label.pop_back();
            assembly_file << "JLE " << label << std::endl;
        }
        else if (op == "<") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            then_quad >> then >> label;
            label.pop_back();
            assembly_file << "JGE " << label << std::endl;
        }
        else if (op == ">=") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            then_quad >> then >> label;
            label.pop_back();
            assembly_file << "JL " << label << std::endl;
        }
        else if (op == "<=") {
            assembly_file << "mov ax, [" << left << "]\n"
                          << "cmp ax, [" << right << "]" << std::endl;
            std::getline(parse_output_file, line);
            std::istringstream then_quad(line);
            then_quad >> then >> label;
            label.pop_back();
            assembly_file << "JG " << label << std::endl;
        }
        else if (op[0] == 'L') {
            assembly_file << op << ": nop" << std::endl;
        }
    }
    
    assembly_file << "mov ax, [" << target << "]\n"
                  << "call ConvertIntegerToString\n"
                  << "mov eax, 4\n"
                  << "mov ebx, 1\n"
                  << "mov ecx, Result\n"
                  << "mov edx, ResultEnd\n"
                  << "int 80h" << std::endl;
    
    assembly_file << "mov eax, sys_exit\n"
                  << "xor ebx, ebx\n"
                  << "int 80h" << std::endl;
}