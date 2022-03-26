#include <Arduino.h>
#include "Keyboard.h"
#include <Pinkey.cpp>
#include <KeyDefinitions.cpp>

int _TotalKeys;
static const int MAX_STROKES = 4;

/*
Configs
*/

void setup()
{
  _TotalKeys = sizeof(PinDeck_Config1) / sizeof(PinDeck_Config1[0]);
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < _TotalKeys; i++)
  {
    while (digitalRead(PinDeck_Config1[i].Pin))
    {
      Serial.println("Key pressed: " + PinDeck_Config1[i].Pin);
      //Functionality for Chord Based Macros
      if (PinDeck_Config1->KeyType == PinkeyType::Chord)
      {
        for (int j = 0; j < MAX_STROKES; j++)
        {
          Serial.println("Chord key: " + PinDeck_Config1[i].Keys[j]);
          if(PinDeck_Config1[i].Keys[j] == 0){
            continue;
          }
          Keyboard.press(PinDeck_Config1[i].Keys[j]);
        }
      }

      //Functionality for Sequential Macros
      if(PinDeck_Config1->KeyType == PinkeyType::Sequence){
        for (size_t j = 0; j < MAX_STROKES; j++)
        {
          Serial.println("Sequence key: " + PinDeck_Config1[i].Keys[j]);
          if(PinDeck_Config1[i].Keys[j] == 0){
            continue;
          }
          Keyboard.press(PinDeck_Config1[i].Keys[j]);
          delay(250);
          Keyboard.release(PinDeck_Config1[i].Keys[j]);
        }
      }
    }
    Keyboard.releaseAll();
  }
}