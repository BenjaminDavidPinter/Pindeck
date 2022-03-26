#include <Arduino.h>
#include "Keyboard.h"

#ifndef PINKEY
#define PINKEY

enum PinkeyType {
    Chord,
    Sequence
};
struct Pinkey {
    short Pin;
    uint8_t Keys[4];
    PinkeyType KeyType;
};

#endif 
