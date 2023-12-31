/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2023
 */

#include <iostream>

#include "cpu.h"

int main(int argc, char * argv[]) {
    std::cout << "Chip-8 Emulator" << std::endl;
    cpu::reset();
    cpu::RAM = {0x13,0xF1};
    cpu::cycle();
    printf("Value: %X", cpu::PC);
    return 0;
}