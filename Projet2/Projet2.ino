#include "lettre.h"

Servo servoDroite;
Servo servoGauche;
Servo raisepen;
Servo paper;

const int pinpaper = 7;
const int pinraisepen = 8;

const int pinServoDroite = 9;
const int pinServoGauche = 10;

int inangle = 90;
int outangle = 50;
int angleDroite = 90;
int angleGauche = 120;

void setup() {
  Serial.begin(9600);

  // Attacher les servomoteurs aux broches correspondantes
  servoDroite.attach(pinServoDroite);
  servoGauche.attach(pinServoGauche);

  // Placer les servomoteurs à leurs positions initiales
  servoDroite.write(angleDroite);
  servoGauche.write(angleGauche);
}

void loop() {
  enter_exit_letter();
}
