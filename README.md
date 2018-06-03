![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'NiceSophia.

# Projet Arduino : Curious Car

Curious Car est une petite voiture contrôlable par Wi-Fi à l’aide d’un ordinateur ou un smartphone. Une caméra IP embarquée permet de voir où va la voiture et d'observer ce qui se passe autour. La voiture a aussi les phares qu’on peut allumer ou éteindre. Curious Car fait un bel exemple de robot de téléprésence.

<img src="https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/images/Result.JPG" width="600">

# Matériel utilisé

* Carte Node Mcu 1.0 (x1)
* Voiture radiocommandée (x1)
* Caméra IP (x1)
* Pilote moteur L293D (x1)
* Carte SD (x1)
* LED blanches (x2)
* Résistances 220 Ohm (x2)
* Mini powerbank 2200 mAh (x1)
* Batteries de 1.5V (x4)
* Cable micro USB (x1)
* Carte de test 400 pts (x1)
* Fils Arduino

# Fonctionnement général

Une carte Wi-Fi programmable se connecte à un réseau Wi-Fi prédéfini dans le code. Elle crée un serveur sur le port 80 (port standard pour le protocole HTTP). Et quand un client va à son adresse IP dans un navigateur Internet, elle lui renvoie une page web interactive. Sur cette page il y a des boutons avec toutes les commandes possibles. Les commandes sont : tourner à droite ou à gauche, aller en avant ou en arrière, allumer ou éteindre les phares. En appuyant sur un bouton, la page se renouvelle avec une nouvelle requête GET dont le paramètre correspond à la commande écrite à côté du bouton. Cette requête est analysée par la carte Wi-Fi, et une action est réalisée en fonction de la commande reçue.

La caméra IP est totalement séparée du système. Elle a sa propre batterie et sa propre adresse IP. On peut voir l’image à l’aide de l’application fournie avec la caméra.

# Tutorial

Disponible [ici](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/tutorial/fr.md).
