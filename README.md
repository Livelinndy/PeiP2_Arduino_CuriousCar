![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'NiceSophia.

# Projet Arduino : Curious Car (en cours de développement)
Curious Car est une voiture radiocommandée qu'on peut aussi contrôler par Wi-Fi depuis un ordinateur ou un smartphone. Une caméra web sans fil accrochée à la voiture transmet l'image Curious Car fait un exemple de robot de téléprésence.

Matériel nécessaire :

- Voiture radiocommandée (x1)
- Carte Arduino (x1)
- Carte [Node Mcu 1.0](http://www.hotmcu.com/nodemcu-lua-wifi-board-based-on-esp8266-cp2102-module-p-265.html) (x1)
- Cables USB micro (x2)
- [Caméra IP](https://fr.aliexpress.com/item/Mini-Camera-480P-Wifi-DV-DVR-Wireless-IP-Cam-Brand-New-Mini-Video-Camcorder-Recorder-Infrared/32824095038.html?src=google&albslr=229618241&isdl=y&aff_short_key=UneMJZVf&source=%7Bifdyn:dyn%7D%7Bifpla:pla%7D%7Bifdbm:DBM&albch=DID%7D&src=google&albch=shopping&acnt=494-037-6276&isdl=y&albcp=653151748&albag=36672819047&slnk=&trgt=68416666751&plac=&crea=fr32824095038&netw=g&device=c&mtctp=&gclid=EAIaIQobChMI2YLS2vPR2AIVjJEbCh2CAwuiEAkYFCABEgKM1_D_BwE) (x1)
- [Mini haut-parleur](https://www.ebay.fr/i/282434707508?chn=ps&dispItem=1) (x1)
- Module carte SD (x1)
- Capteurs de distance HC-SR04 (x2)
- Diodes RGB (x2)
- Diode rouge (x1)
- Diode bleue (x1)
- Résistances 220 Ohm pour les diodes (x8)
- Batterie rechargeable 7.2V
- Régulateur 5V 7805 (x1)
- Condensateur de 10 μF (x1)
- Condensateur de 0.1 μF (x1)

Etape 1 : préparer l'environnement informatique
-
On installe [Arduino IDE](https://www.arduino.cc/en/main/software) sur l'ordinateur si ce n'est pas encore fait. Cet environnement va nous permettre de programmer les cartes Arduino et Node Mcu 1.0.

Ensuite, il faut installer le driver USB pour pouvoir utiliser votre carte Arduino. Dans ce projet, j'utilise la carte [ATmega328P Xplained MINI](https://www.microchip.com/developmenttools/productdetails.aspx?partno=atmega328p-xmini), donc j'ai installé le driver correspondant qu'on peut trouver sur cette [page](http://users.polytech.unice.fr/~pmasson/Enseignement-arduino.htm).

Pour pouvoir travailler avec [Node Mcu 1.0](http://www.hotmcu.com/nodemcu-lua-wifi-board-based-on-esp8266-cp2102-module-p-265.html), on doit installer le driver [USB to UART](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers).

Etape 2 : établir la connexion entre l'ordinateur et la carte Wi-Fi + tester avec diodes
-
On connecte la carte Node Mcu 1.0 à l'ordinateur. On lance Arduino IDE. On va dans le menu "File > Preferences". Dans "Additional Boards Managers URLs", on ajoute l'url suivante :

![Preferences](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Preferences.png)

Dans le menu "Tools > Board > Boards Manager", on choisit le paquétage "esp8266" et on l'installe.

![Boards Manager](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Boards%20Manager.png)

Après l'installation de ce paquétage, on relance Arduino IDE. Et maintenant dans le menu "Tools > Board" on peut trouver notre carte Node Mcu 1.0 pour travailler avec.

Remarque : dans le menu "Tools > Upload Speed", il faut bien vérifier qu'on a "9600", car c'est la vitesse de téléchargement qui correspond à cette carte.

![Node Mcu](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Node%20Mcu.JPG)

(à compléter)

Etape 3 : établir la connexion entre la carte Wi-Fi et l'Arduino + tester avec capteurs de distance
-
(à compléter)

Etape 4 : connecter le circuit moteur à l'Arduino + tester
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

Etape 5 : connecter le haut-parleur et le module carte SD à l'Arduino + tester
-
(à compléter)

Etape 6 : optimiser le code
-
(à compléter)

Etape 7 : faire le circuit d'alimentation et le connecter à l'Arduino et à la carte Wi-Fi
-
(à compléter)

Etape 8 : assembler la voiture
-
(à compléter)

Etape 9 : accrocher la caméra à la voiture
-
(à compléter)

Etape 10 : PROFIT!!!
-
(à compléter)
