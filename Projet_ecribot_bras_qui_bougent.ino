#include <Servo.h>

// Créer des objets Servo pour contrôler les servomoteurs
Servo servoDroite;
Servo servoGauche;

// Définir les broches de connexion pour les servomoteurs
const int pinServoDroite = 9;
const int pinServoGauche = 10;

// Définir les angles de départ pour les servomoteurs
int angleDroite = 90;
int angleGauche = 120;

void setup() {
  // Attacher les servomoteurs aux broches correspondantes
  servoDroite.attach(pinServoDroite);
  servoGauche.attach(pinServoGauche);

  // Placer les servomoteurs à leurs positions initiales
  servoDroite.write(angleDroite);
  servoGauche.write(angleGauche);
}

void loop() {
  // Déplacer les servomoteurs 11 fois
  for (int i = 0; i < 11; i++) {
    // Augmenter l'angle du servomoteur de droite
    angleDroite -= 5;
    servoDroite.write(angleDroite);

    // Réduire l'angle du servomoteur de gauche
    angleGauche += 5;
    servoGauche.write(angleGauche);

    // Attendre 5000 millisecondes entre chaque mouvement
    delay(2000);
  }

  // Remettre les servomoteurs à leurs positions initiales
  angleDroite = 90;
  angleGauche = 120;
  servoDroite.write(angleDroite);
  servoGauche.write(angleGauche);

  // Attendre 1 seconde avant de recommencer
  delay(1000);
}
