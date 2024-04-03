#include "/home/guy/ESEO/Arduino/Projet2/Projet2/charactere_copy_20240311162125/lettre.h"

  
void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = int('N');
  lettre(value);
  return;
}
