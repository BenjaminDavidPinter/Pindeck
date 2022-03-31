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
  /*Set all pins to default pullup*/
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  _TotalKeys = sizeof(PinDeck_Config1) / sizeof(PinDeck_Config1[0]);
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < _TotalKeys; i++)
  {
    while (!digitalRead(PinDeck_Config1[i].Pin))
    {
      Serial.println("Key pressed: " + PinDeck_Config1[i].Pin);
      //Functionality for Chord Based Macros
      if (PinDeck_Config1->KeyType == PinkeyType::Chord)
      {
        for (int j = 0; j < MAX_STROKES; j++)
        { 
          if(PinDeck_Config1[i].Keys[j] != 0){
            Serial.print("Chord Key: ");
            Serial.println(PinDeck_Config1[i].Keys[j]);
            Keyboard.press(PinDeck_Config1[i].Keys[j]);
          }
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
      delay(500);
    }
    Keyboard.releaseAll();
  }
}