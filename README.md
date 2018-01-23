![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'NiceSophia.

# Projet Arduino : Curious Car (en cours de développement)
Curious Car est une voiture radiocommandée qu'on peut aussi contrôler par Wi-Fi depuis un ordinateur ou un smartphone. Une caméra web sans fil accrochée sur la voiture permet de voir où va la voiture. Les capteurs de distance devant et derrière permettent à la voiture d'éviter des obstacles. Un mini haut-parleur sur la voiture permet de transmettre des messages audio prédéfinis. On peut aussi allumer et éteindre les lumières de la voiture. Curious Car fait un bel exemple de robot de téléprésence.

Matériel nécessaire :

| Elément | Quantité | Image |
|---------|:--------:|-------|
| Voiture radiocommandée | x1 | ![Voiture radiocommandée](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Voiture%20radiocommand%C3%A9e.png "Voiture radiocommandée" | width=100) |
| Carte Arduino | x1 | ![ATmega328P-XMINI](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Carte%20Arduino%20ATmega328P-XMINI.png "ATmega328P-XMINI" | width=100) |
| Carte Node Mcu 1.0 | x1 | ![Carte Node Mcu 1.0](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Carte%20Wi-Fi%20Node%20Mcu%201.0.png "Carte Node Mcu 1.0" | width=100) |
| Cable USB micro | x1 | ![Cable USB micro](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Cable%20USB%20micro.png "Cable USB micro" | width=100) |
| Caméra IP | x1 | ![Caméra IP](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Cam%C3%A9ra%20IP.png "Caméra IP" | width=100) |
| Mini haut-parleur | x1 | ![Mini haut-parleur](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Mini%20haut-parleur.png "Mini haut-parleur" | width=100) |
| Module carte SD | x1 | ![Module carte SD](https://raw.githubusercontent.com/Livelinndy/PeiP2_Arduino_CuriousCar/e55b15b1e6945f2eca95c571b2c98cd1f3761502/images/Module%20carte%20SD.png "Module carte SD" | width=100) |
| Carte SD | x1 | ![Carte SD](https://raw.githubusercontent.com/Livelinndy/PeiP2_Arduino_CuriousCar/e55b15b1e6945f2eca95c571b2c98cd1f3761502/images/Carte%20SD.png "Carte SD" | width=100) |
| Capteurs de distance HC-SR04 | x2 | ![HC-SR04](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Capteurs%20de%20distance%20HC-SR04.png "HC-SR04" | width=100) |
| LED RGB | x2 | ![LED RGB](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/LED%20RGB.png "LED RGB" | width=100) |
| LED rouge | x1 | ![LED rouge](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/LED%20rouge.png "LED rouge" | width=100) |
| LED bleue | x1 | ![LED bleue](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/LED%20bleue.png "LED bleue" | width=100) |
| Résistances 220 Ohm | x8 | ![220 Ohm](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/R%C3%A9sistances%20220%20Ohm.png "220 Ohm" | width=100) |
| Batterie rechargeable 7.2 V | x1 | ![Batterie rechargeable 7.2 V](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Batterie%20rechargeable%207,2%20Volts.png "Batterie rechargeable 7.2 V" | width=100) |

Etape 1 : environnement informatique
-
On installe [Arduino IDE](https://www.arduino.cc/en/main/software) sur l'ordinateur si ce n'est pas encore fait. Cet environnement va nous permettre de programmer les cartes Arduino et Node Mcu 1.0.

Ensuite, il faut installer le driver USB pour pouvoir utiliser votre carte Arduino. Dans ce projet, j'utilise la carte [ATmega328P Xplained MINI](https://www.microchip.com/developmenttools/productdetails.aspx?partno=atmega328p-xmini), donc j'ai installé le driver correspondant qu'on peut trouver sur cette [page](http://users.polytech.unice.fr/~pmasson/Enseignement-arduino.htm).

Pour pouvoir travailler avec [Node Mcu 1.0](http://www.hotmcu.com/nodemcu-lua-wifi-board-based-on-esp8266-cp2102-module-p-265.html), on doit installer le driver [USB to UART](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers).

Etape 2 : connexion entre l'ordinateur et la carte Wi-Fi + ajout des diodes
-
On connecte la carte Node Mcu 1.0 à l'ordinateur. On lance Arduino IDE. On va dans le menu "File > Preferences". Dans "Additional Boards Managers URLs", on ajoute l'url suivante :

![Preferences](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Preferences.png "Preferences")

Dans le menu "Tools > Board > Boards Manager", on choisit le paquétage "esp8266" et on l'installe.

![Boards Manager](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Boards%20Manager.png "Boards Manager")

Après l'installation de ce paquétage, on relance Arduino IDE. Et maintenant dans le menu "Tools > Board" on peut trouver notre carte Node Mcu 1.0 pour travailler avec.

Remarque : dans le menu "Tools > Upload Speed", il faut bien vérifier qu'on a "9600", car c'est la vitesse de téléchargement qui correspond à cette carte, comme c'est marqué sur sa face arrière :

![Node Mcu 1.0](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Node%20Mcu.JPG "Node Mcu 1.0")

(à compléter)

Etape 3 : connexion entre la carte Wi-Fi et l'Arduino + ajout des capteurs de distance
-
(à compléter)

Etape 4 : connexion du circuit moteur à l'Arduino + test
-
A l'intérieur de la voiture, on identifie les I/O qui déclenchent les mouvements de la voiture.

Dans mon cas c'est facile car ces I/O sont marqués sur la carte :

![Circuit moteur](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Circuit%20moteur.JPG)

L - left
R - right
F - forward
B - backward

Dans d'autres cas, il faut chercher le datasheet du module de transmission radio.

(à compléter)

Etape 5 : connexion du haut-parleur et du module carte SD à l'Arduino + test
-
(à compléter)

Etape 6 : optimisation du code
-
(à compléter)

Etape 7 : circuit d'alimentation
-
(à compléter)

Etape 8 : assemblage de la voiture
-
(à compléter)

Etape 9 : caméra
-
(à compléter)

Etape 10 : PROFIT!!!
-
(à compléter)
