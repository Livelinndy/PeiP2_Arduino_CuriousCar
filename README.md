![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'NiceSophia.

# Projet Arduino : Curious Car (en cours de développement)

Curious Car est une petite voiture contrôlable par Wi-Fi à l’aide d’un ordinateur ou un smartphone. Une caméra IP embarquée permet de voir où va la voiture et d'observer ce qui se passe autour. Un mini haut-parleur situé à l’intérieur de la voiture joue des messages audio prédéfinis à la demande. La voiture a aussi les phares qu’on peut allumer ou éteindre. Curious Car fait un bel exemple de robot de téléprésence.

(photo, vidéo des essais)

Matériel utilisé
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
      <br>Pilote moteur L293D (x1)<br><em>Assure le mouvement des moteurs</em>
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
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/USBmicro.png" alt="USB micro" height="150">
      <br>Cable USB micro (x1)<br><em>Pour télécharger les programmes sur l'Arduino et la carte Wi-Fi</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Powerbank.png" alt="Powerbank" height="150">
      <br>Mini powerbank 2200 mAh (x1)<br><em>Pour alimenter le système</em>
    </td>
    <td width="300">
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/220OhmResistor.png" alt="220 Ohm" height="150">
      <br>Résistances 220 Ohm (x4)<br><em>Pour les diodes et pour le pont diviseur de tension</em>
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
      <img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Wires.png" alt="Wires" height="150">
      <br>Fils<br><em>Pour réaliser le câblage</em>
    </td>
  </tr>
</table>

Et, bien sûr, un ordinateur pour programmer les cartes Arduino et Node Mcu.

Fonctionnement général
-
La carte Node Mcu (carte Wi-Fi programmable) se connecte à un réseau Wi-Fi prédéfini dans le code. Elle crée un serveur sur le port 80 (port standard pour le protocole HTTP). Et quand un client va à son adresse IP, elle lui renvoie une page web interactive. Sur cette page il y a des boutons avec toutes les commandes possibles. En appuyant sur un bouton, la page se renouvelle avec une nouvelle requête GET dont le paramètre correspond à la commande écrite sur le bouton. Cette requête est analysée par la carte Wi-Fi, et une action est réalisée en fonction de la commande reçue.

La carte Wi-Fi s’occupe de l’allumage des phares, mais le reste des actions possibles est la responsabilité de la carte Arduino. Pour transmettre les commandes de la carte Wi-Fi à l’Arduino, on utilise la communication RX TX entre les deux.

La carte Arduino contrôle les moteurs de la voiture et permet son déplacement. De plus, elle contrôle le module adaptateur carte micro SD (qui lit la carte micro SD avec les messages audio) et le haut-parleur.

La caméra IP est totalement séparée du système. Elle a sa propre batterie et sa propre adresse IP. On peut accéder l’image à l’aide de l’application fourni avec la caméra.

Guide complet
-
Disponible (ici).
