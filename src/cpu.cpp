/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2023
 */

#include "cpu.h"

#include "display.h"
#include "font.h"

namespace cpu {

std::array<uint8_t, 0x1000> RAM;
std::array<uint8_t, 16> V;
uint16_t PC, I;
uint8_t SP;
std::array<uint16_t, 16> stack;

void op0() {
    switch (opcode.value) {
        case 0x00E0:
            display::clear();
            break;
        case 0x00EE:
            // TODO: Assert SP != 0? Could be definedish
            // Return from subroutine.
            PC = stack[SP--];
            break;
        default:
            // SYS addr, ignored in modern intepreters.
            break;
    }
}

void op1() {
    PC = opcode.NNN;
}

void op2() {
    // TODO
}

void op3() {
    // TODO
}

void op4() {
    // TODO
}

void op5() {
    // TODO
}

void op6() {
    V[opcode.X] = opcode.LSB;
}

void op7() {
    V[opcode.X] += opcode.LSB;
}

void op8() {
    // TODO
}

void op9() {
    // TODO
}

void opA() {
    I = opcode.NNN;
}

void opB() {
    // TODO
}

void opC() {
    // TODO
}

void opD() {
    // TODO
}

void opE() {
    // TODO
}

void opF() {
    // TODO
}

void cycle() {
    // Fetch.
    opcode = {.LSB = RAM[PC + 1], .MSB = RAM[PC]};
    PC += 2;

    // Decode and execute
    OPCODES[opcode.OP]();
}

void reset() {
    RAM = {0x13, 0xF1};
    PC = 0;
    I = 0;
    SP = 0;
    // stack;

    // Initialising the font at its conventional space
    RAM.fill(0);
    for (int i = 0; i < FONT.size(); i++) {
        RAM[FONT_START_ADDR + i] = FONT[i];
    }
}
}  // namespace cpu