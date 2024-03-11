#include <Servo.h>

Servo servol;  // Left servo
Servo servor;  // Right servo

int l = 125;
int r = 155;
int compt = 0;

void setup() {
  servol.attach(10);
  servor.attach(9);
  init(l, r);
}

void loop() {
  compt = 0;
  while (l > 24 && r > 54) { // Utilisation de l'opérateur && pour l'ET logique
    delay(1000);
    l = left(l, compt);
    r = right(r, compt);
    init(l, r);
    compt += 1;
  }
  l = 125;
  r = 155;
  init(l, r);
}

void init(int l, int r) {
  servol.write(l);
  servor.write(r);
}

int left(int l, int compt) {
  if (compt == 0 || compt == 1) {
    l -= 10;
  }
  if (compt == 2 || compt == 3 || compt == 4) {
    l -= 30;
  }
  return l;
}

int right(int r, int compt) {
  if (compt == 0 || compt == 1) {
    r -= 30;
  }
  if (compt == 2 || compt == 3 || compt == 4) {
    r -= 10;
  }
  return r;
}
