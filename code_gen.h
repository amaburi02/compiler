#ifndef CODE_GEN
#define CODE_GEN

#include <iostream>
#include <fstream>

class code_generator {
    public:
        void generate_asm_file(std::ifstream& parse_output_file);
};

#endif