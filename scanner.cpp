#include <iostream>
#include <string>

bool finished = false;

class Table_Driven_DFSA {
    private:
        int state_table[32][15];
    public:
        Table_Driven_DFSA() {
            state_table[0][0] = 0; state_table[0][1] = 0; state_table[0][2] = 0; state_table[0][3] = 0; state_table[0][4] = 0; state_table[0][5] = 0; state_table[0][6] = 0; state_table[0][7] = 0; state_table[0][8] = 0; state_table[0][9] = 0; state_table[0][10] = 0; state_table[0][11] = 0; state_table[0][12] = 0; state_table[0][13] = 0; state_table[0][14] = 0;
        }
};