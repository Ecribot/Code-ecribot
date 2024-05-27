#include "lettre.h"
#include <Arduino.h>
#include <Servo.h>

void bras(int value) {
  Servo servoDroite;
  Servo servoGauche;
  
  // Définir les broches de connexion pour les servomoteurs
  const int pinServoDroite = 9;
  const int pinServoGauche = 10;
  // Définir les angles de départ pour les servomoteurs
  int angleDroite = 90;
  int angleGauche = 120;

  // Attacher les servomoteurs aux broches correspondantes
  servoDroite.attach(pinServoDroite);
  servoGauche.attach(pinServoGauche);

  // Placer les servomoteurs à leurs positions initiales
  Serial.print(5*value);
  servoDroite.write(angleDroite - 5 * value);
  servoGauche.write(angleGauche + 5 * value);


    // Attendre 5000 millisecondes entre chaque mouvement
    delay(2000);
}

void put_pencil(int value) {
  Servo raisepen;
  int pinraisepen = 8;
  int inangle = 90;
  int outangle = 60;
  raisepen.attach(pinraisepen);
  raisepen.write(inangle);
  delay(15);
  raisepen.write(outangle);
}

void TPE_intercolumn() {
  Servo paper;
  int pinpaper = 7;
  paper.attach(pinpaper);
  paper.write(2000); 
  delay(100);
  paper.write(1400);
}

void TPE_interlettre() {
  Servo paper;
  int pinpaper = 7;
  paper.attach(pinpaper);
  paper.write(2000); 
  delay(500);
  paper.write(1400);
}

/*
Fonction pour lire et renvoyer le texte choisi sous forme de 1 et 0
*/
void enter_exit_letter() {
  if (Serial.available() > 0) {   // Vérification d'une entrée
    int receivedChar = Serial.read();   // entrée du moniteur série pour le choix de(s/la) phrase(s) à écrire
    // Permet de passer les miniscules en majuscules car l'écribot écrit seulement en majuscule
    if(receivedChar>=97 and receivedChar <=122){    // sachant que les minuscule sont compris de 97 à 122 dans les entiers
        receivedChar = receivedChar -32;    // Permet de passer de passer de minuscule à majuscule car 32 nombres d'écart
      }
     
    for (int letter_index = 0; letter_index < 40; letter_index++)    // Parcours les 40 lettres/chiffres/symboles disponible 
      if (receivedChar == ordre[letter_index]) {   // cherche l'indice des lettres/chiffres/symboles
        // Permet d'afficher les lettres dans le moniteur série sous forme de matrice de 1 et 0
        for (int column_index = 0; column_index < 11; column_index++) {
        for (int line_index = 0; line_index <11; line_index++) {
        unsigned int valeur = pgm_read_word(&listecharactere[letter_index][line_index][column_index]);   //lecture de la valeur de la matrice au indice
        bras(line_index);
        if(valeur==1){
         Serial.print(valeur);
         put_pencil(valeur);
        } else {
        Serial.print("0");
      }
    }
    TPE_intercolumn();
    Serial.println();
   }
   Serial.println();
  }
  TPE_interlettre();
 }
}
