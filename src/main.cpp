#include <Arduino.h>
#include "Keyboard.h"
#include <Pinkey.cpp>
#include <KeyDefinitions.cpp>

int _TotalKeys;

/*
Configs
*/

void setup()
{
  _TotalKeys = sizeof(PinDeck_Config1) / sizeof(PinDeck_Config1[0]);
}

void loop()
{
  for (int i = 0; i < _TotalKeys; i++)
  {
    while (digitalRead(PinDeck_Config1[i].Pin))
    {
      //Functionality for Chord Based Macros
      if (PinDeck_Config1->KeyType == PinkeyType::Chord)
      {
        for (size_t j = 0; j < PinDeck_Config1[i].Keys.size(); j++)
        {
          Keyboard.press(PinDeck_Config1[i].Keys.at(j));
        }
      }

      //Functionality for Sequential Macros
      if(PinDeck_Config1->KeyType == PinkeyType::Sequence){
        for (size_t j = 0; j < PinDeck_Config1[i].Keys.size(); j++)
        {
          Keyboard.press(PinDeck_Config1[i].Keys.at(j));
          delay(250);
          Keyboard.release(PinDeck_Config1[i].Keys.at(j));
        }
      }
    }
    Keyboard.releaseAll();
  }
}