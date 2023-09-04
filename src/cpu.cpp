/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2023
 */

#include "cpu.h"

#include <cstdlib>
#include <ctime>

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
    // TODO Could the PC being incremented previous affect this?.
    stack[++SP] = PC;
    PC = opcode.NNN;
}

void op3() {
    if (V[opcode.X] == opcode.LSB) {
        PC += 2;
    }
}

void op4() {
    if (V[opcode.X] != opcode.LSB) {
        PC += 2;
    }
}

void op5() {
    if (V[opcode.X] == V[opcode.Y]) {
        PC += 2;
    }
}

void op6() {
    V[opcode.X] = opcode.LSB;
}

void op7() {
    V[opcode.X] += opcode.LSB;
}

void op8() {
    // TODO
    switch (opcode.N) {
        case 0:
            V[opcode.X] = V[opcode.Y];
            break;
        case 1:
            V[opcode.X] |= V[opcode.Y];
            break;
        case 2:
            V[opcode.X] &= V[opcode.Y];
            break;
        case 3:
            V[opcode.X] ^= V[opcode.Y];
            break;
        case 4:
            // (result & 0xFF00) != 0
        default:
            // TODO: Assert invalid op?
    }
}

void op9() {
    if (V[opcode.X] != V[opcode.Y]) {
        PC += 2;
    }
}

void opA() {
    I = opcode.NNN;
}

void opB() {
    PC = opcode.NNN + V[0];
}

void opC() {
    V[opcode.X] = ((uint8_t) std::rand()) & opcode.LSB;
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
    // stack; TODO

    // Initialising the font at its conventional space
    RAM.fill(0);
    for (int i = 0; i < FONT.size(); i++) {
        RAM[FONT_START_ADDR + i] = FONT[i];
    }

    // Resetting the random seed.
    // TODO: Better random?
    std::srand(std::time(nullptr));
}
}  // namespace cpu