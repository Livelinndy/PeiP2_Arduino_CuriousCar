// pour la connexion Wi-Fi et la création d'un serveur
#include <ESP8266WiFi.h>
const char* ssid = "your wifi name"; // nom du Wi-Fi
const char* password = "your password"; // mot de passe
WiFiServer server(80);

// pour les phares
const int led = 5; // D1
boolean lights = false; // indique si les phares sont allumées

// pour le moteur de devant qui fait la voiture tourner ses roues de devant à gauche ou à droite
const int left = 0; // D3
const int right = 2; // D4
// pour le moteur de derrière qui fait la voiture aller en avant ou en arrière
const int forward = 14; // D5
const int backward = 12; // D6

void setup(){
  // initialisation des pins
  pinMode(led,OUTPUT);
  pinMode(left,OUTPUT);
  pinMode(right,OUTPUT);
  pinMode(forward,OUTPUT);
  pinMode(backward,OUTPUT);
  // les phares sont éteintes au début
  digitalWrite(led,HIGH);
  // la voiture ne bouge pas au début
  stopCar();
  // on connecte la carte Wi-Fi au Wi-Fi prédéfini
  WiFi.begin(ssid,password);
  // on lance le serveur
  server.begin();
}

void loop(){
  // on vérifie si un client s'est connecté
  WiFiClient client = server.available();
  if(!client) return;
  // on attend que le client envoie des données
  while(!client.available()) delay(1);
  // on lit la 1ère ligne de la requête du client
  String request = client.readStringUntil('\r');
  client.flush();
  
  // on trouve quelle commande a été envoyée (si elle a été envoyée) et on met à jour le système
  if(request.indexOf("cmd=turnOnLights") != -1){ lights = true; digitalWrite(led,LOW); }
  else if(request.indexOf("cmd=turnOffLights") != -1){ lights = false; digitalWrite(led,HIGH);}
  else if(request.indexOf("cmd=turnLeft") != -1) turnLeft();
  else if(request.indexOf("cmd=turnRight") != -1) turnRight();
  else if(request.indexOf("cmd=forward") != -1) goForward();
  else if(request.indexOf("cmd=backward") != -1) goBackward();
  else if(request.indexOf("cmd=stopCar") != -1) stopCar();
  
  // on retourne la réponse du serveur
                 // l'en-tête
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
                 // la page HTML
  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("    <head>");
  client.println("        <meta charset=\"utf-8\">");
  client.println("        <title>Curious Car</title>");
                          // ce script js reconnait l'appui sur un bouton et renouvelle la page avec la requête qui correspond au bouton appuyé
                          // remarque : javascript s'éxécute dans le navigateur Internet du client
  client.println("        <script type=\"text/javascript\">");
                              // cette fonction est appelée lorsque l'un des boutons prédéfinis est pressé
  client.println("            document.addEventListener(\"keypress\", function onEvent(event){");
  client.println("                switch(event.key){");
                                      // par exemple, si le bouton pressé est "l", la commande transmise sera de changer l'état des phares (allumer ou éteindre)
  if(lights)
  client.println("                    case \"l\": window.location.replace('?cmd=turnOffLights'); break;");
  else
  client.println("                    case \"l\": window.location.replace('?cmd=turnOnLights'); break;");
  client.println("                    case \"q\": window.location.replace('?cmd=turnLeft'); break;");
  client.println("                    case \"d\": window.location.replace('?cmd=turnRight'); break;");
  client.println("                    case \"z\": window.location.replace('?cmd=forward'); break;");
  client.println("                    case \"s\": window.location.replace('?cmd=backward'); break;");
  client.println("                    case \"x\": window.location.replace('?cmd=stopCar'); break;");
  client.println("                    default: return;");
  client.println("                }");
  client.println("            });");
  client.println("        </script>");
                          // fin du script javascript
  client.println("    </head>");
  client.println("    <body>");
  client.println("        <h1>Curious Car</h1>");
  client.println("        <table style=\"border: 0;\">");
  if(lights)
  client.println("                <tr><td><button style=\"width: 50px;\" onclick=\"window.location.replace('?cmd=turnOffLights');\">L</button>Turn OFF lights</td></tr>");
  else
  client.println("                <tr><td><button style=\"width: 50px;\" onclick=\"window.location.replace('?cmd=turnOnLights');\">L</button>Turn ON lights</td></tr>");
  client.println("            <tr></tr>");
  client.println("            <tr>");
  client.println("                <td></td>");
  client.println("                <td><button style=\"width: 50px;\" onclick=\"window.location.replace('?cmd=forward');\">Z</button>Go forward</td>");
  client.println("                <td></td>");
  client.println("            </tr>");
  client.println("            <tr>");
  client.println("                <td><button style=\"width: 50px;\" onclick=\"window.location.replace('?cmd=turnLeft');\">Q</button>Turn left</td>");
  client.println("                <td><button style=\"width: 50px;\" onclick=\"window.location.replace('?cmd=backward');\">S</button>Go backward</td>");
  client.println("                <td><button style=\"width: 50px;\" onclick=\"window.location.replace('?cmd=turnRight');\">D</button>Turn right</td>");
  client.println("            </tr>");
  client.println("            <tr>");
  client.println("                <td></td>");
  client.println("                <td><button style=\"width: 50px;\" onclick=\"window.location.replace('?cmd=stopCar');\">X</button>Stop</td>");
  client.println("                <td></td>");
  client.println("            </tr>");
  client.println("        </table>");
  client.println("    </body>");
  client.println("</html>");
}

// fail la voiture tourner à gauche
void turnLeft(){
  // on tourne les roues à gauche (moteur de devant)
  digitalWrite(left,HIGH);
  digitalWrite(right,LOW);
}

// fait la voiture tourner à droite
void turnRight(){
  // on tourne les roues à droite (moteur de devant)
  digitalWrite(left,LOW);
  digitalWrite(right,HIGH);
}

// fait la voiture aller en avant
void goForward(){
  // on va en avant (moteur derrière)
  digitalWrite(forward,HIGH);
  digitalWrite(backward,LOW);
  // on attend 1 seconde
  delay(1000);
  // et on arrête la voiture
  stopCar();
}

// fait la voiture aller en arrière
void goBackward(){
  // on va en arrière (moteur derrière)
  digitalWrite(forward,LOW);
  digitalWrite(backward,HIGH);
  // on attend 1 seconde
  delay(1000);
  // et on arrête la voiture
  stopCar();
}

// arrête le moteur de devant
void stopFrontMotor(){
  digitalWrite(left,HIGH);
  digitalWrite(right,HIGH);
}

// arrête le moteur de derrière
void stopBackMotor(){
  digitalWrite(forward,HIGH);
  digitalWrite(backward,HIGH);
}

// arrête les 2 moteurs
void stopCar(){
  stopBackMotor();
  stopFrontMotor();
}
