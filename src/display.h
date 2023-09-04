/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2023
 */

#pragma once

#include <array>

namespace display {

constexpr unsigned int WIDTH = 64;
constexpr unsigned int HEIGHT = 32;
constexpr unsigned int NUM_PIXELS = WIDTH * HEIGHT;

extern std::array<bool, NUM_PIXELS> pixels;

void clear();

}  // namespace display
