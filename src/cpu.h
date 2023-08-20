/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2023
 */

#pragma once

#include <cinttypes>
#include <array>

struct cpu {
    std::array<uint8_t, 0x1000> RAM:

    // 16 8-bit data registers named V0 to VF.
    // V[F] is the control register.
    std::array<uint8_t, 16> V;

    // 12-bit address registers, which were actually 16-bits long.
    uint16_t PC, I;

    // 8-bit Stack Pointer.
    uint8_t SP;
};


