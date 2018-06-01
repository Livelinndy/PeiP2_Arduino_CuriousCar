On va voir en détail toutes les étapes de conception de Curious Car.

Etape 1 : Acquérir le matériel nécessaire
-
Voici la liste complète du matériel utilisé :

<table>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/NodeMcu1.0.png" alt="Node Mcu 1.0" height="150">
      <br>Carte Node Mcu 1.0 (x1)<br><em>Gère tout</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/RCcar.png" alt="RC car" height="150">
      <br>Voiture radiocommandée (x1)<br><em>Le support</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/IPcamera.png" alt="IP camera" height="150">
      <br>Caméra IP (x1)<br><em>Transmet la vidéo via Wi-Fi</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/USBmicro.png" alt="USB micro" height="150">
      <br>Cable USB micro (x1)<br><em>Pour télécharger les programmes sur l'Arduino et la carte Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/L293D.png" alt="L293D" height="150">
      <br>Pilote moteur L293D (x1)<br><em>Assure le mouvement des moteurs</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/MicroSDcard.png" alt="Carte micro SD" height="150">
      <br>Carte micro SD (x1)<br><em>Stocke les vidéos enregistrées par la caméra</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Breadboard.jpg" alt="Breadboard" height="150">
      <br>Carte de test 400 pts (x1)<br><em>Pour faire des tests et pour ne pas souder la carte Wi-Fi</em>
    </td>
    <td width="300">
      <img alt="White LED" src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/WhiteLED.png" height="150">
      <br>LED blanches (x2)<br><em>Pour les lumières de devant</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/220OhmResistor.png" alt="220 Ohm" height="150">
      <br>Résistances 220 Ohm (x2)<br><em>Pour les LED</em>
    </td>
  </tr>
  <tr>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Batteries.png" alt="Batteries" height="150">
      <br>Batterie 1,5V (x4)<br><em>Pour alimenter les moteurs séparement du système</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Powerbank.png" alt="Powerbank" height="150">
      <br>Mini powerbank 2200 mAh (x1)<br><em>Pour alimenter le système</em>
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

Etape 3 : Phares
-
On va commencer par le plus facile : les phares.

Pour les phares on a besoin de 2 LED blanches et de 2 résistances de 220 Ohm. Le schéma de branchement est le suivant :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/schematics/Lights.png" alt="Schéma des phares">

Quand le pin D1 est en mode LOW, les phares sont allumées. Sinon, elles sont éteintes.

Pour assembler les phares, j'ai soudé chaque diode avec sa résistance et encore prolongé les pattes des composants avec des fils pour que les phares puissent atteindre leur place devant sur la voiture.

Etape 4 : Mouvement
-
Ensuite, on va réaliser le contrôle du mouvement par la carte Wi-Fi.

J’ai commencé par enlever le circuit qui était déjà à l’intérieur de la voiture car je n’allais pas utiliser la communication radio à 27MHz qu’il permettait et j’avais besoin de la place à l'intérieur de la voiture.

Pour piloter les 2 moteurs DC, qu’il y avait dans la voiture, j’ai utilisé un microcircuit pilote moteur L293D. Les signaux en sortie des I/O du Node Mcu sont de faible puissance, et L293D les transforme en courants suffisants pour piloter les moteurs. L293D permet de piloter 2 moteurs en même temps. De plus, il permet de changer leur sens de rotation à l’aide des ponts en H.

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/schematics/L293D.jpg" alt="L293D">

Voici le schéma des branchements :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/schematics/Motors.png" alt="Schéma de branchement des moteurs">

J'ai connecté les enable à 5V pour simplifier le câblage car la table de vérité du microcircuit est la suivante :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/L293Dlogic.png" alt="La logique du L293D">

Et j’ai utilisé 4 piles de 1,5V pour alimenter les moteurs séparémént du système pour ne pas le surcharger. Sinon, si on alimentait les moteurs par la carte Node Mcu, on ne pouvait pas tourner les 2 moteurs en même temps car il n’y avait pas assez de puissance.

Etape 5 : Caméra
-
Pour rajouter la caméra, il a fallu seulement la configurer pour qu’elle se connecte à notre Wi-Fi et la mettre sur le toit de la voiture. La configuration se fait dans l’application fournie avec la caméra.

Etape 6 : Alimentation
-
J’ai alimenté la carte Node Mcu avec un mini powerbank de charge 2200mAh via un petit cable micro USB. Une source d’alimentation comme ça est beaucoup plus durable qu’une pile de 9V, par exemple.

Etape 7 : Assemblage final et des tests
-
On télécharge le [programme](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/code/CuriousCar.ino) sur la carte Node Mcu.

On fait tous les branchements décrits précédemment.

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/ResultInside.JPG" alt="Branchements" width="600">

On attache la caméra et le powerbank.

Et c'est prêt !

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Result.JPG" alt="Résultat final" width="600">

Pour se connecter au serveur créé par la carte Wi-Fi, il faut lire son adresse IP sur l'appareil auquel la carte s'est connectée. Ou on peut le récupérer dans le Serial Monitor lors du téléchargement du programme.

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/GetCardIP.png" alt="Serial Monitor" width="600">

Ensuite, il faut connecter son ordinateur ou smartphone au même réseau Wi-Fi. Et finalement, il faut taper l'adresse IP récupéré précédemment dans la barre d'adresse du navigateur Internet.

En se connectant sur le serveur, on voit la page suivante :

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/ServerPage.png" alt="Page du serveur" width="600">

En appuyant sur un bouton ou en appuyant la touche qui correspond au nom du bouton on peut effectuer l'action écrité à côté du bouton.

En ce qui concerne la caméra, on peut voir l'image dans son application.
