On va voir en détail toutes les étapes de conception de Curious Car.

Etape 1 : Acquérir le matériel nécessaire
-
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
      <br>Mini haut-parleur (x1)<br><em>Joue des messages audio</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/ArduinoATmega328P-XMINI.png" alt="ATmega328P-XMINI" height="150">
      <br>Carte Arduino (x1)<br><em>Gère le mouvement et l'audio</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/NodeMcu1.0.png" alt="Node Mcu 1.0" height="150">
      <br>Carte Node Mcu 1.0 (x1)<br><em>Gère la connexion Wi-Fi, l'allumage des phares et la mesure de distance</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/MicroSDmodule.png" alt="Micro SD module" height="150">
      <br>Module carte micro SD (x1)<br><em>Ressort les messages audio de la mémoire</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/L293D.png" alt="L293D" height="150">
      <br>Pilote moteur L293D (x1)<br><em>Assure le mouvement des moteurs</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/HC-SR04.png" alt="HC-SR04" height="150">
      <br>Capteurs de distance HC-SR04 (x2)<br><em>Assurent l'évasion des obstacles</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/MicroSDcard.png" alt="Carte micro SD" height="150">
      <br>Cartes micro SD (x2)<br><em>Stockent les messages audio et les vidéos enregistrées par la caméra</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/USBmicro.png" alt="USB micro" height="150">
      <br>Cable USB micro (x1)<br><em>Pour télécharger les programmes sur l'Arduino et la carte Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Powerbank.png" alt="Powerbank" height="150">
      <br>Mini powerbank 2200 mAh (x1)<br><em>Pour alimenter le système</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/220OhmResistor.png" alt="220 Ohm" height="150">
      <br>Résistances 220 Ohm (x4)<br><em>Pour les LED et pour le pont diviseur de tension</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img alt="White LED" src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/WhiteLED.png" height="150">
      <br>LED blanches (x2)<br><em>Pour les lumières de devant</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Breadboard.jpg" alt="Breadboard" height="150">
      <br>Carte de test 400 pts (x1)<br><em>Pour faire des tests et pour ne pas souder la carte Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Wires.png" alt="Wires" height="150">
      <br>Fils<br><em>Pour réaliser le câblage</em>
    </td>
  </tr>
</table>

Et, bien sûr, on aura besoin d'un ordinateur pour programmer les cartes Arduino et Node Mcu.

Etape 2 : Préparer l'environnement informatique
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

Une fois l'environnement informatique est préparé, on peut passer aux étapes suivantes où on va réaliser le montage et programmer le système.

Par la suite, on va réaliser séparement chaqune des fonctionnalités prévues, et à la fin on va les mettre ensemble.

Etape 3 : Phares et serveur Wi-Fi
-
On va commencer par le plus facile : les phares. Et on va en même temps créer un serveur avec la carte Wi-Fi.

Pour les phares on a besoin de 2 LED blanches et de 2 résistances de 220 Ohm. Le schéma de branchement est le suivant :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/schematics/Lights.png" alt="Schéma des phares">

Quand le pin D0 est en mode LOW, les phares sont allumées. Sinon, elles sont éteintes.

Pour assembler les phares, j'ai soudé chaque diode avec sa résistance et encore prolongé les pattes des composants avec des fils pour que les phares puissent atteindre leur place devant sur la voiture.

L'exemple du code pour cette partie est disponible [ici](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/examples/WiFiAndLights.ino).

Pour se connecter au serveur créé par la carte Wi-Fi, il faut lire son adresse IP sur l'appareil auquel la carte s'est connectée. Ensuite, il faut connecter son ordinateur ou smartphone au même réseau Wi-Fi. Et finalement, il faut taper l'adresse IP récupéré précédemment dans la barre d'adresse du navigateur Internet.

En se connectant sur le serveur, on voit la page suivante :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Server1.png" alt="Page du serveur">

En appuyant sur le bouton ou en appuyant la touche "L" sur le clavier on peut changer l'état des phares !

Etape 4 : Mouvement
-
Ensuite, j’ai réalisé le contrôle du mouvement par l’Arduino.
J’ai commencé par enlever le circuit qui était déjà à l’intérieur de la voiture car je n’allais pas utiliser la communication radio à 27MHz qu’il permettait et j’avais besoin de la place pour l’Arduino et les autres composants.
Pour piloter les 2 moteurs DC, qu’il y avait dans la voiture, j’ai utilisé un microcircuit pilote moteur L293D. Les signaux en sortie des I/O de l’Arduino sont de faible puissance, et L293D les transforme en courants suffisants pour piloter les moteurs. L293D permet de piloter 2 moteurs en même temps. De plus, il permet de changer leur sens de rotation à l’aide des ponts en H.
Voici le schéma des branchements :

J'ai connecté les enable à 5V pour simplifier le câblage car la table de vérité du microcircuit est la suivante :


Etape 5 : Audio (optionnel)
-
Pour connecter un haut-parleur à l'Arduino, j'ai suivi un [guide complet](https://www.youtube.com/watch?v=gi9mqIha8n0) trouvé sur Internet.

Voici le schéma des branchements que j'ai faits :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/schematics/Audio.png" alt="Connecter un haut-parleur et une carte SD à l'Arduino">

Pour trouver le "+" et le "-" du haut-parleur, je me suis servi de ce schéma-là :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/schematics/AudioConnector.png" alt="Jack audio générique">

Le "+" correspond au "Left" ou "Right", et le "-" correspond au "Ground".

J'ai connecté les fils au jack audio en les pliant autour et en finalisant la connexion avec de la colle en silicone, mais le mieux c'est d'utiliser un adaptateur jack audio, comme ça le son ne sera pas bruité.

En ce qui concerne la carte SD, il faut au préalable y télécharger des fichiers audio au format adapté, wav. Pour cela on va utiliser un convertisseur et on va mettre les paramètres suivants :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/schematics/AudioConversion.png" alt="Convertisseur audio">

Après avoir fait toutes les connexions entre les composants, il ne reste qu'à télécharger le programme sur la carte Arduino.
L'exemple du code pour cette partie est disponible [ici](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/examples/Audio.ino).

Etape 6 : Communication RX TX
-
Comme une partie des fonctions dans le système est effectuée par l'Arduino et c'est seulement la carte Node Mcu qui peut revevoir des commandes, il faut établir la communication entre Node Mcu et Arduino. Pour cela, j'ai choisi la communication RX TX.

Je n'ai pas réussi à établir la communication RX TX sur les ports RX TX par défaut, donc j'utilise la bibliothéque SoftwareSerial qui permet de créer les ports RX TX sur n'importe quels pins numériques.

Etape 7 : Capteurs de distance
-

Etape 8 : Caméra
-
Il faut seulement configurer la caméra pour qu’elle se connecte à notre réseau Wi-Fi et la mettre sur le toit de la voiture. La configuration se fait dans l’application fournie avec la caméra.

Etape 9 : Alimentation
-
J’ai alimenté la carte Node Mcu avec un mini powerbank de charge 2200mAh via un petit cable micro USB. La carte Arduino est alimentée par la carte Node Mcu. J’ai connecté le Vin de la carte Node Mcu (qui donne 5V) au Vcc de la carte Arduino et le GND du Node Mcu au GND de l’Arduino.
