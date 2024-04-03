#include "lettre.h"
#include <Arduino.h>


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
        for (int line_index = 0; line_index <11; line_index++) {
        for (int column_index = 0; column_index < 11; column_index++) {
        unsigned int valeur = pgm_read_word(&listecharactere[letter_index][line_index][column_index]);   //lecture de la valeur de la matrice au indice
        if(valeur==1){
         Serial.print(valeur); 
        } else {
        Serial.print(" ");
      }
    }
    Serial.println();
   }
   Serial.println();
  }
 }
}
