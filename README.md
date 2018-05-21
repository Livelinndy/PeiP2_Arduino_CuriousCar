![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'NiceSophia.

# Projet Arduino : Curious Car (en cours de développement)
Curious Car est une petite voiture controllable par Wi-Fi via un ordinateur ou un smartphone avec caméra embarquée. Cette caméra nous permet de voir où va la voiture et d'observer ce qui se passe autour. Les capteurs de distance devant et derrière la voiture permettent d'éviter des obstacles en arrêtant la voiture quand l'obstacle est trop près. Un mini haut-parleur sur la voiture permet de jouer des messages audio prédéfinis. On peut aussi allumer et éteindre les lumières et le clignottant de la voiture. Curious Car fait un bel exemple de robot de téléprésence.

On va voir en détail toutes les étapes de conception de Curious Car.

Etape 1 : Matériel
-
Après avoir défini les objectifs du projet et toutes les fonctionnalités voulues, j'ai commencé par acquérir le matériel nécessaire pour réaliser le projet. Bien sûr, je n'avais pas tout le matériel au début et j'avançais les parties du projet avec le matériel que j'avais déjà en attendant que le reste arrive.

Voici la liste complète du matériel utilisé :

<table>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/RCcar.png" alt="RC car" height="150">
      <br>Voiture radiocommandée (x1)<br><em>Le support</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/IPcamera.png" alt="IP camera" height="150">
      <br>Caméra IP (x1)<br><em>Transmet la vidéo via Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Speaker.png" alt="Mini speaker"  height="150">
      <br>Mini haut-parleur (x1)<br><em>Joue les messages audio</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/ArduinoATmega328P-XMINI.png" alt="ATmega328P-XMINI" height="150">
      <br>Carte Arduino (x1)<br><em>Gère le mouvement de la voiture</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/NodeMcu1.0.png" alt="Node Mcu 1.0" height="150">
      <br>Carte Node Mcu 1.0 (x1)<br><em>Assure la connexion Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/MicroSDmodule.png" alt="Micro SD module" height="150">
      <br>Module carte micro SD (x1)<br><em>Ressort les messages audio de la mémoire</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/L293D.png" alt="L293D" height="150">
      <br>Pilote moteur L293D (x1)<br><em>Assure le mouvement de la voiture</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/HC-SR04.png" alt="HC-SR04" height="150">
      <br>Capteurs de distance HC-SR04 (x2)<br><em>Assurent l'évasion des obstacles</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/MicroSD.png" alt="Micro SD" height="150">
      <br>Cartes micro SD (x2)<br><em>Stockent les messages audio et les vidéos</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/RedLED.png" alt="Red LED" height="150">
      <br>LED rouge (x1)<br><em>Pour le clignottant</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/BlueLED.png" alt="Blue LED" height="150">
      <br>LED bleue (x1)<br><em>Pour le clignottant</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/220OhmResistor.png" alt="220 Ohm" height="150">
      <br>Résistances 220 Ohm (x6)<br><em>Pour les diodes et le pont diviseur de tension</em>
    </td>
    
  </tr>
  <tr>
    <td width="300">
      <img alt="White LED" src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/WhiteLED.png" height="150">
      <br>LED blanches (x2)<br><em>Pour les lumières de devant</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Breadboard.jpg" alt="Breadboard" height="150">
      <br>Carte de test 400 pts (x1)<br><em>Pour ne pas souder la carte Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Powerbank.png" alt="Powerbank" height="150">
      <br>Mini powerbank 2200 mAh (x1)<br><em>Pour alimenter le système</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/USBmicro.png" alt="USB micro" height="150">
      <br>Cable USB micro (x1)<br><em>Pour télécharger les programmes sur l'Arduino et la carte Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Wires.png" alt="Wires" height="150">
      <br>Fils<br><em>Pour réaliser le câblage</em>
    </td>
    <td width="300">
        <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Computer.png" alt="Computer" height="150">
        <br>Un ordinateur<br><em>Pour programmer les cartes Arduino et Node Mcu</em>
    </td>
  </tr>
</table>

Etape 2 : Environnement informatique
-
On installe [Arduino IDE](https://www.arduino.cc/en/main/software) sur l'ordinateur si ce n'est pas encore fait. Cet environnement va nous permettre de programmer les cartes Arduino et Node Mcu 1.0.

Ensuite, il faut installer le driver USB pour pouvoir utiliser votre carte Arduino. Dans ce projet, j'utilise la carte [ATmega328P Xplained MINI](https://www.microchip.com/developmenttools/productdetails.aspx?partno=atmega328p-xmini), donc j'ai installé le driver correspondant qu'on peut trouver sur cette [page](http://users.polytech.unice.fr/~pmasson/Enseignement-arduino.htm).

Pour pouvoir travailler avec [Node Mcu 1.0](http://www.hotmcu.com/nodemcu-lua-wifi-board-based-on-esp8266-cp2102-module-p-265.html), on doit installer le driver [USB to UART](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers).

Maintenant, il va falloir installer le paquétage nous permettant de programmer la carte Wi-Fi.

On connecte la carte Node Mcu 1.0 à l'ordinateur. On lance Arduino IDE. On va dans le menu "File > Preferences". Dans "Additional Boards Managers URLs", on ajoute l'url suivante :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Preferences.png" alt="Preferences" width="600">

Dans le menu "Tools > Board > Boards Manager", on choisit le paquétage "esp8266" et on l'installe.

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/BoardsManager.png" alt="Boards Manager" width="600">

Après l'installation de ce paquétage, on relance Arduino IDE. Et finalement dans le menu "Tools > Board" on peut trouver notre carte Node Mcu 1.0 pour travailler avec.

Remarque : avant de télécharger un programme sur Node Mcu 1.0, il faut bien vérifier que dans le menu "Tools > Upload Speed" on a "9600", car c'est la vitesse de téléchargement qui correspond à cette carte, comme c'est marqué sur sa face arrière :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/NodeMcuBackSide.JPG" alt="Node Mcu back side">

Une fois l'environnement informatique est préparé, on peut passer aux étapes suivantes où on va réaliser le montage et la programmation du système.

Par la suite, on va réaliser séparement chaqune des fonctionnalités prévues, et à la fin on va les mettre ensemble.

Etape 3 : Serveur Wi-Fi
-
On souhaite utiliser la carte Node Mcu en mode serveur pour qu'on ait une page web interactive qui nous permetterait d'envoyer les commandes à la voiture. Le code de base pour créer un serveur avec Node Mcu 1.0 est le suivant :

<pre>
<code>
  #include &lt;ESP8266WiFi.h&gt;
  const char* ssid = "your wifi name";
  const char* password = "your password";
  // le serveur va être créé sur le port 80
  WiFiServer server(80);
  // on déclare toutes les autres variables globales
  // ...
  
  void setup(){
    // on initialise les pins dont on a besoin
    // ...
    // on connecte la carte au Wi-Fi
    WiFi.begin(ssid,password);
    // et on lance le serveur
    server.begin();
  }
  
  void loop(){
    // si un client s'est connecté au serveur
    WiFiClient client = server.available();
    if(!client) return;
    while(!client.available()) delay(1);
    // on récupère sa requête
    String request = client.readStringUntil('\r');
    client.flush();
    // on analyse la requête du client et trouve la commande envoyée
    // ...
    // on met à jour le système en fonction de cette commande
    // ...
    // et on retourne la réponse du serveur
    // d'abord l'en-tête
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    // et puis la page html
    // ...
  }
</code>
</pre>

Après avoir téléchargé ce code sur la carte Node Mcu, je vois que la carte s'est bien connectée à ma box Wi-Fi. Maintenant on va dans le navigateur Internet d'un ordinateur (ou smartphone) qui est aussi connecté à ce réseau. On tape l'adresse IP de la carte (qu'on trouve dans les appareils connectés à la box) dans la barre de navigation, et une page vide s'affiche. C'est normal puisqu'on n'a rien mis après l'en-tête dans la réponse du serveur.

Etape 4 : Phares
-
Dans cette étape, on va ajouter les phares (2 LED blanches) à notre voiture. Les LED vont être connectés directement à la carte Node Mcu 1.0 comme dans cette [vidéo](https://www.youtube.com/watch?v=ZPUg4Uw3A0E).

Sur la carte de test, on branche 2 LED blanches et 2 résistances de 220 Ohm comme ceci :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Lights.png" alt="Lights">

Maintenant il faut écrire le programme. Il ne nous reste qu'à ajouter quelques détails au programme de l'étape précedent.

Au début :
<pre>
<code>
  // on déclare les variables globales
  const int led1 = 5; // D1
  const int led2 = 4; // D2
  boolean lights = false; // indique si les phares sont allumées
</code>
</pre>

Dans setup() :
<pre>
<code>
  // on initialise les pins dont on a besoin
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  // et on éteint les phares au début
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
</code>
</pre>

Dans loop() :
<pre>
<code>
  // on analyse la requête du client et trouve la commande envoyée
  if(request.indexOf("cmd=turnOnLights") != -1) lights = true;
  else if(request.indexOf("cmd=turnOffLights") != -1) lights = false;
  // on met à jour le système en fonction de cette commande
  if(lights){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  }else{
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
  }
  // la page html envoyée par le serveur est
  client.println("&lt;!DOCTYPE HTML&gt;");
  client.println("&lt;html&gt;");
  client.println("&lt;head&gt;");
  client.println("&lt;title&gt;Curious Car&lt;/title&gt;");
  client.println("&lt;/head&gt;");
  client.println("&lt;body&gt;");
  client.print("The lights are now: ");
  if(lights) client.println("On");
  else client.println("Off");
  client.print("&lt;a href=\"?cmd=turnOnLights\"&gt;&lt;button&gt;Turn on lights&lt;/button>&lt;/a&gt;");
  client.println("&lt;a href=\"?cmd=turnOffLights\"&gt;&lt;button&gt;Turn off lights&lt;/button&gt;&lt;/a&gt;");
  client.println("&lt;/body&gt;");
  client.println("&lt;/html&gt;");
</code>
</pre>

On télécharge le programme sur la carte. Et maintenant quand on va sur l'adresse IP de la carte, la page n'est plus vide, il y a une phrase qui indique l'état des phares et 2 boutons qui permettent de changer leur état.

(image)

On accroche chaque diode à sa résistace par des soudures, on prolonge les pattes des composants avec des fils en faisant des soudures aussi, on met du scotch isolant dessus, et les phares sont prêtes.

(image)

Etape 5 : Mouvement
-
J'ai décidé d'enlever le circuit qui était à l'intérieur de la voiture parce qu'il prenait trop de place et je n'allais pas me servir de la connexion radio 27 MHz qu'il permettait. J'ai décidé de commander les moteurs directement par l'Arduino à l'aide d'un pilote moteur L293D qui transforme les signaux de faible puissance en courants suffisants pour piloter les moteurs.

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/L293D.png" alt="L293D" width="200">

Son schéma est le suivant :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/L293Dscheme.jpg" alt="L293D" width="200">

Un L293D peut piloter 2 moteurs en même temps et changer leur sens de rotation à l'aide des ponts en H.

On va connecter L293D à l'Arduino comme ceci :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Motors.png" alt="Motors" width="600">

J'ai connecté les enable à Vcc pour simplifier le câblage et comme ça on peut controler les moteurs à tout moment.

Les input pour le moteur à droite sont connectés aux sorties PWM de l'Arduino pour que le moteur de derrière, qui est responsable du mouvement en avant ou en arrière, puisse changer de vitesse.

Les fonctions de mouvement téléchargées sur l'Arduino sont :

<pre>
<code>

</code>
</pre>

Etape 6 : Communication entre Node Mcu et Arduino
-
Comme c'est Node Mcu qui reçoit les commandes du client mais c'est Arduino qui est responsable du mouvement de la voiture, il faut établir la connexion entre les deux. Ils vont se parler à l'aide des ports RX TX.

J'ai décide de laisser les ports RX TX par défaut libres pour les messages internes de chaque carte, et j'ai utilise la bibliothèque SoftwareSerial pour déclarer des ports RX TX en plus sur chaque carte.

Sur Node Mcu :

<pre>
<code>
  int command = 0;
  #include &lt;SoftwareSerial.h&gt;
  SoftwareSerial mySerial1(13,15); // RX (D7), TX (D8)
  
  void setup(){
    mySerial1.begin(9600);
  }
</code>
</pre>

Dans loop(), à chaque commande on affecte un numéro, la variable command prend ce numéro, et la commande est envoyée avec mySerial.write(command).

Sur Arduino :

<pre>
<code>
  int command = 0;
  #include &lt;SoftwareSerial.h&gt;
  SoftwareSerial mySerial2(
  
  void setup(){
    mySerial2.begin(9600);
  }
  
  void loop(){
  if(mySerial2.available()){
    // on lit le numéro de la commande sur le Serial port
    command = mySerial2.read() - '0';
    // on effectue la commande qui correspond au numéro réçu
    switch(command){
      // case 1: ...
      // ...
      default: return;
    }
  }
}
</code>
</pre>

On télécharge les programmes sur les deux cartes.

N.B. Il vaut mieux télécharger les programmes sans que les 2 cartes soient connectées (sinon ça donne un peu de fumée, je ne sais pas pourquoi).

Maintenant on connecte :
- Le RX de l'Arduino au TX du Node Mcu
- Le TX de l'Arduino au RX du Node Mcu par un pont diviseur de tension

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/VoltageDivider.jpg" alt="Voltage divider" width="200">

Il faut un diviseur de tension car Arduino marche sur une logique de 5 V, Node Mcu marche sur une logique de 3.3 V, et on ne veut pas que Node Mcu reçoit quelque chose plus grand que 3.3 V et donne de la fumée. Même si c'est Node Mcu qui envoie des informations à l'Arduino et non pas l'inverse, j'ai pris cette mesure de précaution.

(image)

Etape 7 : Evasion d'obstacles
-
L'évasion des obstacles s'éffectue par deux capteurs de distance HC-SR04, devant et derrière. Ils sont branchés sur l'Arduino, et comme les moteurs sont aussi branchés sur l'Arduino il n'est pas difficile de programmer l'arrêt de la voiture quand elle est trop proche d'un obstacle.

(à compléter)

Etape 8 : Caméra
-
La caméra que j'ai choisie n'a pas besoin d'être connectée à l'Arduino ou d'être alimentée avec tout le reste du système. C'est une caméra IP qui a sa propre batterie, elle peut se connecter à un réseau Wi-Fi, et on peut accéder à l'image via son application en étant connecté sur le même réseau Wi-Fi. Pour commencer à travailler avec la caméra il faut seulement la bien [configurer](https://www.youtube.com/watch?v=lPglF5r2YqU&vl=fr). Une fois tout est configuré, on accroche la caméra sur le toit de la voiture.

(photo)

Etape 9 : Haut-parleur (optionnel, s'il y a de la place)
-
Guide complet [ici](https://www.youtube.com/watch?v=gi9mqIha8n0).

Etape 10 : Alimentation
-
Pour la source d'alimentation du système j'ai choisi un mini powerbank.

Etape 11 : Optimisation
-
(à compléter)

Etape 12 : PROFIT!!!
-
Résultat final. Des essais.

(à compléter)
