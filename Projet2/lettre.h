#ifndef LETTRE_H
#define LETTRE_H

#include <Arduino.h>
#include <Servo.h>

extern const unsigned int listecharactere[40][11][11];
extern int ordre[40];
extern Servo servoDroite;
extern Servo servoGauche;
extern Servo raisepen;
extern Servo paper;

// Déclaration des broches de connexion pour les servomoteurs
extern const int pinServoDroite;
extern const int pinServoGauche;
extern const int pinraisepen;
extern const int pinpaper;

// Déclaration des angles de départ pour les servomoteurs
extern int angleDroite;
extern int angleGauche;
extern int inangle;
extern int outangle;

// Déclaration des fonctions
void bras(int value);
void put_pencil(int value);
void TPE_intercolumn();
void TPE_interlettre();
void enter_exit_letter();

#endif
