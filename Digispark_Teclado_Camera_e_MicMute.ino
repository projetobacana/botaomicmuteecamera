/* *************************
 *  Projeto Bacana - 09/2021
 *  www.projetobacana.com.br
 *  Júlio Vansan Gonçalves
 *  Principais teclas que podem ser usadas:
 *  MOD_CONTROL_LEFT
 *  MOD_SHIFT_LEFT
 *  MOD_ALT_LEFT
 *  MOD_CONTROL_RIGHT
 *  MOD_SHIFT_RIGHT
 *  MOD_ALT_RIGHT
 *  
 *  Teclas de A até Z = KEY_A, KEY_B ... KEY_Z
 *  Números = KEY_0, KEY_1 ... KEY_9
 *  Teclas de Função = KEY_F1, KEY_F2 ... KEY_F12
 *  
 *  ************************
 */

//https://sourceforge.net/projects/micmute/
//https://youtu.be/L9fJkZuyses

#include "DigiKeyboard.h"

int botaoSom = 0;
int botaoVideo = 2;

const int LED=1;

void setup() {
  pinMode(botaoSom,INPUT_PULLUP);
  pinMode(botaoVideo,INPUT_PULLUP);
  pinMode(LED,OUTPUT);

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  
}

void loop() {
  delay(50);
  if (digitalRead(botaoSom)==LOW){
    digitalWrite(LED,HIGH);
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(100); 
    DigiKeyboard.sendKeyStroke(KEY_M, MOD_SHIFT_LEFT | MOD_CONTROL_LEFT | MOD_ALT_LEFT);
    delay(50);
    while (digitalRead(botaoSom)==LOW){
        delay(50);
    }//while  
    digitalWrite(LED,LOW);  
  } //if som

if (digitalRead(botaoVideo)==LOW){
  digitalWrite(LED,HIGH);
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(100); 
    DigiKeyboard.sendKeyStroke(KEY_O, MOD_SHIFT_LEFT | MOD_CONTROL_LEFT);
    delay(50);
    while (digitalRead(botaoVideo)==LOW){
        delay(50);
    }//while  
    digitalWrite(LED,LOW);  
  } //if Video

}// loop
