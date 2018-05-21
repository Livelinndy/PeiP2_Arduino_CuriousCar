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
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/RCcar.png" alt="RC car" height="100">
      <br>Voiture radiocommandée (x1)<br><em>Le support</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/IPcamera.png" alt="IP camera" height="100">
      <br>Caméra IP (x1)<br><em>Transmet la vidéo via Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Speaker.png" alt="Mini speaker"  height="100">
      <br>Mini haut-parleur (x1)<br><em>Joue les messages audio</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/ArduinoATmega328P-XMINI.png" alt="ATmega328P-XMINI" height="100">
      <br>Carte Arduino (x1)<br><em>Gère le mouvement de la voiture</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/NodeMcu1.0.png" alt="Node Mcu 1.0" height="100">
      <br>Carte Node Mcu 1.0 (x1)<br><em>Assure la connexion Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/MicroSDmodule.png" alt="Micro SD module" height="100">
      <br>Module carte micro SD (x1)<br><em>Ressort les messages audio de la mémoire</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/L293D.png" alt="L293D" height="100">
      <br>Pilote moteur L293D (x1)<br><em>Assure le mouvement de la voiture</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/HC-SR04.png" alt="HC-SR04" height="100">
      <br>Capteurs de distance HC-SR04 (x2)<br><em>Assurent l'évasion des obstacles</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/MicroSD.png" alt="Micro SD" height="100">
      <br>Cartes micro SD (x2)<br><em>Stockent les messages audio et les vidéos</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/RedLED.png" alt="Red LED" height="100">
      <br>LED rouge (x1)<br><em>Pour le clignottant</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/BlueLED.png" alt="Blue LED" height="100">
      <br>LED bleue (x1)<br><em>Pour le clignottant</em>
    </td>
    <td width="300">
      <img alt="White LED" src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/WhiteLED.png" height="100">
      <br>LED blanches (x2)<br><em>Pour les lumières de devant</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Resistors220Ohm.png" alt="220 Ohm" height="100">
      <br>Résistances 220 Ohm (x8)<br><em>Pour les diodes</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Breadboard.jpg" alt="Breadboard" height="100">
      <br>Carte de test 400 pts (x1)<br><em>Pour ne pas souder la carte Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Powerbank.jpg" alt="Powerbank" height="100">
      <br>Mini powerbank 2200 mAh (x1)<br><em>Pour alimenter le système</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/USBmicro.png" alt="USB micro" height="100">
      <br>Cable USB micro (x1)<br><em>Pour télécharger les programmes sur l'Arduino et la carte Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Wires.png" alt="Wires" height="100">
      <br>Fils<br><em>Pour réaliser le câblage</em>
    </td>
    <td width="300">
        <br><br><em></em>
    </td>
  </tr>
</table>

Et bien sûr on aura besoin d'un ordi pour programmer les cartes Arduino et Node Mcu.

Etape 2 : Environnement informatique
-
On installe [Arduino IDE](https://www.arduino.cc/en/main/software) sur l'ordinateur si ce n'est pas encore fait. Cet environnement va nous permettre de programmer les cartes Arduino et Node Mcu 1.0.

Ensuite, il faut installer le driver USB pour pouvoir utiliser votre carte Arduino. Dans ce projet, j'utilise la carte [ATmega328P Xplained MINI](https://www.microchip.com/developmenttools/productdetails.aspx?partno=atmega328p-xmini), donc j'ai installé le driver correspondant qu'on peut trouver sur cette [page](http://users.polytech.unice.fr/~pmasson/Enseignement-arduino.htm).

Pour pouvoir travailler avec [Node Mcu 1.0](http://www.hotmcu.com/nodemcu-lua-wifi-board-based-on-esp8266-cp2102-module-p-265.html), on doit installer le driver [USB to UART](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers).

Maintenant, il va falloir installer le paquétage nous permettant de programmer la carte Wi-Fi.

On connecte la carte Node Mcu 1.0 à l'ordinateur. On lance Arduino IDE. On va dans le menu "File > Preferences". Dans "Additional Boards Managers URLs", on ajoute l'url suivante :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Preferences.png" alt="Preferences" width="600">

Dans le menu "Tools > Board > Boards Manager", on choisit le paquétage "esp8266" et on l'installe.

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Boards%20Manager.png" alt="Boards Manager" width="600">

Après l'installation de ce paquétage, on relance Arduino IDE. Et finalement dans le menu "Tools > Board" on peut trouver notre carte Node Mcu 1.0 pour travailler avec.

Remarque : avant de télécharger un programme sur Node Mcu 1.0, il faut bien vérifier que dans le menu "Tools > Upload Speed" on a "9600", car c'est la vitesse de téléchargement qui correspond à cette carte, comme c'est marqué sur sa face arrière :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Node%20Mcu%20face%20arri%C3%A8re.JPG" alt="Node Mcu face arrière">

Une fois l'environnement informatique est préparé, on peut passer aux étapes suivantes où on va réaliser le montage et la programmation du système.

Par la suite, on va réaliser séparement chaqune des fonctionnalités prévues, et à la fin on va les mettre ensemble.

Etape 3 : Lumières
-
On commence par le plus facile : les lumières. Cette étape va aussi nous permettre de tester le fonctionnement de la carte Node Mcu 1.0.

(à compléter)

Etape 4 : Mouvement
-
J'ai décidé d'enlever la carte qui était à l'intérieur de la voiture car elle prenait trop de place et je n'allais pas me servir de la connexion radio 27 MHz qu'elle permettait. J'ai décidé de commander les moteurs directement par l'Arduino à l'aide d'un pilote moteur L293D.

(à compléter)

Etape 5 : Evasion d'obstacles
-
L'évasion des obstacles s'éffectue par deux capteurs de distance HC-SR04, devant et derrière. Ils sont branchés sur l'Arduino, et comme les moteurs sont aussi branchés sur l'Arduino il n'est pas difficile de programmer l'arrêt de la voiture quand elle est trop proche d'un obstacle.

(à compléter)

Etape 6 : Caméra
-
La caméra que j'ai choisie n'a pas besoin d'être connectée à l'Arduino ou d'être alimentée avec tout le reste du système, donc il faut seulement la [configurer](https://www.youtube.com/watch?v=lPglF5r2YqU&vl=fr) et accrocher sur le toit de la voiture.

(photo)

Etape 7 : Haut-parleur (optionnel, s'il y a de la place)
-
(à compléter)

Etape 8 : Alimentation
-
(à compléter)

Etape 9 : Optimisation
-
(à compléter)

Etape 10 : PROFIT!!!
-
Résultat final. Des essais.

(à compléter)
