![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'NiceSophia.

# Projet Arduino : Curious Car (en cours de développement)

Curious Car est une petite voiture contrôlable par Wi-Fi à l’aide d’un ordinateur ou un smartphone. Une caméra IP embarquée permet de voir où va la voiture et d'observer ce qui se passe autour. Un mini haut-parleur situé à l’intérieur de la voiture joue des messages audio prédéfinis à la demande. La voiture a aussi les phares qu’on peut allumer ou éteindre. Curious Car fait un bel exemple de robot de téléprésence.

(photo, vidéo des essais)

# Matériel utilisé

* Carte Arduino Atmega328P-XplainedMINI (x1)
* Carte Node Mcu 1.0 (x1)
* Voiture radiocommandée (x1)
* Caméra IP (x1)
* Mini haut-parleur (x1)
* Pilote moteur L293D (x1)
* Capteurs de distance HC-SR04 (x2)
* Module adaptateur carte SD (x1)
* Cartes SD (x2)
* LED blanches (x2)
* Résistances 220 Ohm (x4)
* Mini powerbank 2200 mAh (x1)
* Cable micro USB (x1)
* Carte de test 400 pts (x1)
* Fils Arduino

# Fonctionnement général

La carte Wi-Fi programmable Node Mcu se connecte à un réseau Wi-Fi prédéfini dans le code. Elle crée un serveur sur le port 80 (port standard pour le protocole HTTP). Et quand un client va à son adresse IP, elle lui renvoie une page web interactive. Sur cette page il y a des boutons avec toutes les commandes possibles qu'on peut envoyer à la voiture. En appuyant sur un bouton, la page se renouvelle avec une nouvelle requête GET dont le paramètre correspond à la commande écrite sur le bouton. Cette requête est analysée par la carte Wi-Fi, et une action est réalisée en fonction de la commande reçue.

La carte Wi-Fi s’occupe de l’allumage des phares et gère les capteurs de distance, mais le reste des actions possibles est la responsabilité de la carte Arduino. Pour transmettre les commandes de la carte Wi-Fi à l’Arduino, on utilise la communication RX TX entre les deux.

La carte Arduino contrôle les moteurs de la voiture et permet son déplacement. De plus, elle contrôle le module adaptateur carte micro SD (qui lit la carte micro SD avec les messages audio) et le haut-parleur.

La caméra IP est totalement séparée du système. Elle a sa propre batterie et sa propre adresse IP. On peut accéder l’image à l’aide de l’application fournie avec la caméra.

# Guide complet

Disponible [ici](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/tutorial/fr.md).
