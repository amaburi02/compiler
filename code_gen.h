#ifndef CODE_GEN
#define CODE_GEN

#include <iostream>
#include <fstream>

class Code_Generator {
    public:
        void generate_asm_file(std::fstream& parse_output_file, std::fstream& symbol_file, std::fstream& assembly_file);
};

#endif