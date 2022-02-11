#include <Arduino.h>
#include "Keyboard.h"
#include <vector>


#ifndef PINKEY
#define PINKEY

enum PinkeyType {
    Chord,
    Sequence
};
struct Pinkey {
    short Pin;
    std::vector<uint8_t> Keys;
    PinkeyType KeyType;
};

#endif 
