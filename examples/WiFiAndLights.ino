// pour le serveur wifi
#include <ESP8266WiFi.h>
const char* ssid = "your wifi name";
const char* password = "your password";
WiFiServer server(80);

// pour les phares
const int led = 16;
boolean lights = false; // indique si les phares sont allumées

void setup() {
  // initialisation du pin utilisé
  pinMode(led,OUTPUT);
  // on étéint les phares au début
  digitalWrite(led,HIGH);
  // on connecte la carte wifi au réseau wifi
  WiFi.begin(ssid,password);
  // on lance le serveur
  server.begin();
}

void loop() {
  // on vérifie si un client s'est connecté
  WiFiClient client = server.available();
  if(!client) return;
  // on attend que le client envoie des données
  while(!client.available()) delay(1);
  // on lit la 1ère ligne de la requête du client
  String request = client.readStringUntil('\r');
  client.flush();
  
  // on trouve quelle commande a été envoyée (si elle a été envoyée) et on met à jour le système
  if(request.indexOf("cmd=turnOnLights") != -1){
    lights = true;
    digitalWrite(led,LOW);
  }
  else if(request.indexOf("cmd=turnOffLights") != -1){
    lights = false;
    digitalWrite(led,HIGH);
  }

  // on retourne la réponse du serveur
                 // l'en-tête
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
                 // la page elle-même
  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("    <head>");
  client.println("        <meta charset=\"utf-8\">");
                          // ce script js reconnait l'appui sur un bouton et renouvelle la page avec la requête qui correspond au bouton appuyé
                          // remarque : javascript s'éxécute dans le navigateur Internet du client
  client.println("        <script type=\"text/javascript\">");
                              // cette fonction est appelée lorsque l'un des boutons prédéfinis est pressé
  client.println("            document.addEventListener(\"keypress\", function onEvent(event){");
  client.println("                switch(event.key){");
                                      // par exemple, si le bouton pressé est "l", la commande transmise sera de changer l'état des phares (allumer ou éteindre)
  client.println("                    case \"l\":");
  if(lights)
  client.println("                        window.location.replace('?cmd=turnOffLights');");
  else
  client.println("                        window.location.replace('?cmd=turnOnLights');");
  client.println("                        break;");
  client.println("                    default: return;");
  client.println("                }");
  client.println("            });");
  client.println("        </script>");
                          // fin du script javascript
  client.println("    </head>");
  client.println("    <body>");
  if(lights)
  client.println("        <button style=\"width: 50px;\" onclick=\"window.location.replace('?cmd=turnOffLights');\">L</button>Turn OFF lights");
  else
  client.println("        <button style=\"width: 50px;\" onclick=\"window.location.replace('?cmd=turnOnLights');\">L</button>Turn ON lights");
  client.println("    </body>");
  client.println("</html>");
}
