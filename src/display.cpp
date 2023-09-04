/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2023
 */

#include "display.h"

namespace display {

std::array<bool, NUM_PIXELS> pixels;

void display::clear() {
    pixels.fill(false);
}
}  // namespace display