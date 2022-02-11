#include <Pinkey.cpp>

/*
[01] [02] [03] [04]
[05] [06] [07] [08]
*/

Pinkey PinDeck_Config1[] = {
    {0, {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_DELETE}, PinkeyType::Chord}, // Classic Control+Alt+Delete
    {1, {KEY_LEFT_GUI, 'l'}, PinkeyType::Chord},                       // Lock Computer
    {3, {KEY_LEFT_ALT, 'h', 'o', 'i'}, PinkeyType::Sequence}           // EXCEL Auto-Fit column size to selection
};
