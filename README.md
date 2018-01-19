Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'NiceSophia.

![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

# PeiP2 Arduino : Curious Car
Véhicule avec caméra controlé à longue distance (projet en cours de développement)

Etape 1 : acquisition du matériel
-
Tout d'abord, il faut acquérir le matériel nécessaire :

- Voiture radiocommandée (x1)
- Carte Arduino (x1)
- Carte [Node Mcu 1.0](http://www.hotmcu.com/nodemcu-lua-wifi-board-based-on-esp8266-cp2102-module-p-265.html) avec module Wi-Fi ESP-12E (x1)
- [Caméra IP](https://fr.aliexpress.com/item/Mini-Camera-480P-Wifi-DV-DVR-Wireless-IP-Cam-Brand-New-Mini-Video-Camcorder-Recorder-Infrared/32824095038.html?src=google&albslr=229618241&isdl=y&aff_short_key=UneMJZVf&source=%7Bifdyn:dyn%7D%7Bifpla:pla%7D%7Bifdbm:DBM&albch=DID%7D&src=google&albch=shopping&acnt=494-037-6276&isdl=y&albcp=653151748&albag=36672819047&slnk=&trgt=68416666751&plac=&crea=fr32824095038&netw=g&device=c&mtctp=&gclid=EAIaIQobChMI2YLS2vPR2AIVjJEbCh2CAwuiEAkYFCABEgKM1_D_BwE) (x1)
- [Mini haut-parleur](https://www.ebay.fr/i/282434707508?chn=ps&dispItem=1) (x1)
- Capteurs de distance HC-SR04 (x2)
- Diodes RGB (x2)
- Diode rouge (x1)
- Diode bleue (x1)
- Résistances 220 Ohm pour les diodes (x8)
- à compléter.

Etape 2 : préparation de l'environnement informatique
-
On installe [Arduino IDE](https://www.arduino.cc/en/main/software) sur l'ordinateur si ce n'est pas encore fait. Cet environnement va nous permettre de programmer les cartes Arduino et Node Mcu 1.0.

Ensuite, il faut installer le driver USB pour pouvoir utiliser votre carte Arduino. Dans ce projet, j'utilise la carte [ATmega328P Xplained MINI](https://www.microchip.com/developmenttools/productdetails.aspx?partno=atmega328p-xmini), donc j'ai installé le driver correspondant qu'on peut trouver sur cette [page](http://users.polytech.unice.fr/~pmasson/Enseignement-arduino.htm).

Pour pouvoir travailler avec [Node Mcu 1.0](http://www.hotmcu.com/nodemcu-lua-wifi-board-based-on-esp8266-cp2102-module-p-265.html), on doit installer le driver [USB to UART](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers), comme c'est indiqué sur la face arrière de la carte.

Etape 3 : circuit de commande
-

Etape 4 :
-
On connecte la carte Node Mcu 1.0 à l'ordinateur. On lance Arduino IDE. On va dans le menu **File > Preferences**. Dans **Additional Boards Managers URLs**, on ajoute l'url suivante:

Dans le menu **Tools > Board > Boards Manager**, on va tout en bas, on choisit le paquétage **esp8266** et on l'installe.

Après l'installation on relance Arduino IDE. Et maintenant dans le menu **Tools > Board** on peut trouver notre carte Node Mcu 1.0 pour travailler avec.

Etape 5 :
-

Etape 6 :
-

Etape 7 :
-
