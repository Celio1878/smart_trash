// Bibliotecas
#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>

// Define pino Servo
#define SERVO 8

// Variável do Servo
Servo s;

// Variável de posição do Servo
int pos;

// Define porta Buzzer
int inBuzzer = 7;

void setup() {

  // Modo de entrada do sinal do Buzzer
  pinMode (inBuzzer, INPUT);

  s.attach (SERVO);

  // Sinal de operação do sistema eletrônico
  Serial.begin (9600);

  // Escreve posição inicial do Servo
  s.write (0);

  // Lê valor inicial do Buzzer = 0
  digitalWrite (inBuzzer, LOW);
}

void loop() {

  // Se sinal de entrada do Buzzer = 1
  // Movimenta Servo para posição desejada
  // E retorna para valor inicial depois de 2 segundos
  if (digitalRead (inBuzzer) == HIGH) {
    for (pos = 0; pos < 45; pos++) {
    s.write (pos);
    delay (15);
    }
   
    delay (2000);
    
    for (pos = 45; pos >= 0; pos--) {
    s.write (pos);
    delay (15);
    }
  }
 }
