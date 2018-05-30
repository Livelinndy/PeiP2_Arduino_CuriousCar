// pour recevoir les commandes de la carte Wi-Fi sur le Serial port
int command = 0;
#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,8); // RX, TX

// pour les messages audio
#include <SD.h>
#define SD_ChipSelectPin 10
#include <TMRpcm.h>
#include <SPI.h>
TMRpcm tmrpcm;

void setup(){
  // initialisation des pins
  tmrpcm.speakerPin = 9;
  // on fixe le volume du haut-parleur à 4 sur 7
  tmrpcm.setVolume(4);
  // on initialise la carte SD
  SD.begin(SD_ChipSelectPin);
  // on commence la communication via Serial port pour récevoir les commandes de la carte Wi-Fi
  mySerial.begin(9600);
}

void loop(){
  // s'il y a plus de 0 bytes dans le buffer
  if(mySerial.available()){
    // on lit le numéro de la commande sur le Serial port
    command = mySerial.read()-'0';
    // on effectue la commande
    switch(command){
      case 1: tmrpcm.play("1.wav"); break;
      case 2: tmrpcm.play("2.wav"); break;
      case 3: tmrpcm.play("3.wav"); break;
      default: return;
    }
  }
}
