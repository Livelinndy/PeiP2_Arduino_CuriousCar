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

Remarque : avant de télécharger un programme sur Node Mcu 1.0, il faut bien vérifier que dans le menu "Tools > Upload Speed" on a "9600", car c'est la vitesse de téléchargement qui correspond à cette carte, comme c'est marqué sur sa face arrière :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/NodeMcuBackSide.JPG" alt="Node Mcu back side">

Une fois l'environnement informatique est préparé, on peut passer aux étapes suivantes où on va réaliser le montage et la programmation du système.

Par la suite, on va réaliser séparement chaqune des fonctionnalités prévues, et à la fin on va les mettre ensemble.

Etape 3 : Phares
-
On va commencer par le plus facile : les phares. Pour les phares on a besoin de 2 LED blanches et de 2 résistances de 220 Ohm. Le schéma de branchement est le suivant :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/schematics/Lights.png" alt="Schéma des phares">

Quand les pins D1 et D2 sont en mode LOW, les phares sont allumées. Sinon, elles sont éteintes.

Pour assembler les phares, il va falloir souder chaque diode avec sa résistance et encore prolonger les pattes des composants par des fils pour que les phares puissent atteindre leur place devant.

Le code pour les phares est disponible (ici).
