/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2023
 */

#include "cpu.h"

namespace cpu {

    std::array<uint8_t, 0x1000> RAM;
    std::array<uint8_t, 16> V;
    uint16_t PC, I;
    uint8_t SP;
    std::array<uint16_t, 16> stack;

    void op0() {
        int PC = 2;
    }

    void op1() {
        PC = opcode.NNN;
    }

    void op2() {

    }

    void op3() {

    }

    void op4() {

    }

    void op5() {

    }

    void op6() {

    }

    void op7() {

    }

    void op8() {

    }

    void op9() {

    }

    void opA() {

    }

    void opB() {

    }

    void opC() {

    }

    void opD() {

    }

    void opE() {

    }

    void opF() {

    }

    void cycle() {
        // Fetch.
        opcode = {.LSB = RAM[PC + 1], .MSB = RAM[PC]};
        PC += 2;

        // Decode and execute
        OPCODES[opcode.OP]();
    }

    void reset() {
        RAM = {0x13,0xF1};
        PC = 0;
        I = 0;
        SP = 0;
        //stack;
    }
}