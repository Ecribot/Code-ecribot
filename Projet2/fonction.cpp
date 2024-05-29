#include "lettre.h"

void bras(int value) {
   // Déplacer les servomoteurs 11 fois
    // Augmenter l'angle du servomoteur de droite
    angleDroite -= 5;
    servoDroite.write(angleDroite);

    // Réduire l'angle du servomoteur de gauche
    angleGauche += 5;
    servoGauche.write(angleGauche);

    // Attendre 2000 millisecondes entre chaque mouvement
    delay(200);
}


void bras_init(){
  // Remettre les servomoteurs à leurs positions initiales
  angleDroite = 90;
  angleGauche = 120;
  servoDroite.write(angleDroite);
  servoGauche.write(angleGauche);
}
void put_pencil() {
  inangle = 90;
  outangle = 50;
  raisepen.attach(pinraisepen);
  raisepen.write(inangle);
  delay(200);
  raisepen.write(outangle);
  delay(200);
}

void TPE_intercolumn() {
  paper.attach(pinpaper);
  paper.write(2000);
  delay(100);
  paper.write(1400);
}

void TPE_interlettre() {
  paper.attach(pinpaper);
  paper.write(2000);
  delay(500);
  paper.write(1400);
}

void enter_exit_letter() {
  if (Serial.available() > 0) {   // Vérification d'une entrée
    int receivedChar = Serial.read();   // entrée du moniteur série pour le choix de(s/la) phrase(s) à écrire
    // Permet de passer les miniscules en majuscules car l'écribot écrit seulement en majuscule
    if(receivedChar >= 97 && receivedChar <= 122){    // sachant que les minuscule sont compris de 97 à 122 dans les entiers
      receivedChar = receivedChar - 32;    // Permet de passer de minuscule à majuscule car 32 nombres d'écart
    }

    for (int letter_index = 0; letter_index < 40; letter_index++) {    // Parcours les 40 lettres/chiffres/symboles disponible 
      if (receivedChar == ordre[letter_index]) {   // cherche l'indice des lettres/chiffres/symboles
        // Permet d'afficher les lettres dans le moniteur série sous forme de matrice de 1 et 0
        for (int column_index = 0; column_index < 11; column_index++) {
          for (int line_index = 0; line_index < 11; line_index++) {
            unsigned int valeur = pgm_read_word(&listecharactere[letter_index][line_index][column_index]);   //lecture de la valeur de la matrice au indice
            bras(line_index);
            if (valeur == 1) {
              Serial.print(valeur);
              put_pencil();
            } else {
              Serial.print(" ");
            }
          }
          bras_init();
          TPE_intercolumn();
          Serial.println();
        }
        TPE_interlettre();
        Serial.println();
      }
    }
  }
}
