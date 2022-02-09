#include <Arduino.h>
#include "Keyboard.h"
#include <Pinkey.cpp>

int _TotalKeys;

//Key Definitions
Pinkey _Keys[] = {
    {0, {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_DELETE}},
    {1, {KEY_LEFT_GUI, 'l'}
  }
};

void setup() {
  _TotalKeys = sizeof(_Keys)/sizeof(_Keys[0]);
}

void loop() {
  for(int i = 0; i < _TotalKeys; i++){
    while(digitalRead(_Keys[i].Pin)){
      for(int j = 0; j < _Keys[i].Keys.size(); j++){
        Keyboard.press(_Keys[i].Keys.at(j));
      }
    }
    Keyboard.releaseAll();
  }
}