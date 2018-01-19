Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'NiceSophia.

![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

# PeiP2_Arduino_CuriousCar
Véhicule avec caméra controlé à longue distance (projet en cours de développement)

Liste de matériel :

- Voiture radiocommandée (x1)
- Carte Arduino (x1)
- Carte [NodeMcu 1.0](http://www.hotmcu.com/nodemcu-lua-wifi-board-based-on-esp8266-cp2102-module-p-265.html) avec module Wi-Fi ESP-12E (x1)
- [Caméra IP](https://fr.aliexpress.com/item/Mini-Camera-480P-Wifi-DV-DVR-Wireless-IP-Cam-Brand-New-Mini-Video-Camcorder-Recorder-Infrared/32824095038.html?src=google&albslr=229618241&isdl=y&aff_short_key=UneMJZVf&source=%7Bifdyn:dyn%7D%7Bifpla:pla%7D%7Bifdbm:DBM&albch=DID%7D&src=google&albch=shopping&acnt=494-037-6276&isdl=y&albcp=653151748&albag=36672819047&slnk=&trgt=68416666751&plac=&crea=fr32824095038&netw=g&device=c&mtctp=&gclid=EAIaIQobChMI2YLS2vPR2AIVjJEbCh2CAwuiEAkYFCABEgKM1_D_BwE) (x1)
- Mini haut-parleur (x1)
- Mésureurs de distance HC-SR04 (x2)
- Diodes RGB (x2)
- Diode rouge (x1)
- Diode bleue (x1)
- Résistances 220 Ohm pour les diodes (x8)
- à compléter.

Etape 1 : installer le soft
-
On installe [Arduino IDE](https://www.arduino.cc/en/main/software) si ce n'est pas encore fait. Cet environnement va nous permettre de programmer les cartes Arduino et Node Mcu 1.0.

Ensuite, il faut installer le driver USB correspondant pour pouvoir utiliser votre carte Arduino. J'utilise la carte [ATmega328P Xplained MINI](https://www.microchip.com/developmenttools/productdetails.aspx?partno=atmega328p-xmini), donc j'ai installé [ce driver](users.polytech.unice.fr/~pmasson/Enseignement/driver-atmel-bundle-7.0.712.exe).

Pour pouvoir travailler avec Node Mcu 1.0, on doit installer le driver de CP2102
