#include <Arduino.h>
#include "Keyboard.h"
#include <vector>

struct Pinkey {
    short Pin;
    std::vector<uint8_t> Keys;
};