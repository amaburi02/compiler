#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string src_code;
    std::string user_input;

    std::ofstream token_list("token_list.txt");

    while (std::getline(std::cin, user_input)) {
        src_code += user_input + "\n";
    }

    return 0;
}