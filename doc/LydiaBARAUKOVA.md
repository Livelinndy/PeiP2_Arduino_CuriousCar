Cahier de suivi du projet de Lydia Baraukova
===
Séance du 22 décembre 2017
-
Durant cette première séance j'ai constitué un magnifique groupe de 1 personne (moi).

J'ai décidé de faire comme projet une voiture commandée par Internet depuis un ordinateur. Cette voiture aura une caméra web attachée dont l'image et le son seront tranférés vers l'ordinateur de celui qui contrôle la voiture. J'ajouterai aussi 2 capteurs de distance pour éviter que la voiture se heurte contre des objets; et quelques diodes pour rendre la voiture plus jolie. Optionnelement on peut ajouter un haut-parleur pour jouer des messages audio prédéfinis.

J'ai cherché sur Internet les projets similaires, dans cette [vidéo](https://www.youtube.com/watch?v=Ck1rouoTh0o) on peut voir un exemple de réalisation.

Séance du 12 janvier 2018
-
J'ai obtenu quelques composants nécessaires pour le projet, notamment :
* Encore un mésureur de distance HC-SR04
* Les diodes
* Les résistances de 220 Ohm pour les diodes
* Une carte Wi-Fi Node Mcu 1.0

J'ai cherché les autres composants nécessaires dans des magasins en ligne.

Séance du 18 janvier 2018
-
J'ai trouvé sur Internet quelques vidéos avec informations utiles pour le projet :
* [Commencer à travailler avec Node Mcu 1.0](https://www.youtube.com/watch?v=G6CqvhXpBKM)
* [Un projet simple avec Node Mcu 1.0](https://www.youtube.com/watch?v=ZPUg4Uw3A0E)
* [Jouer des messages audio avec Arduino](https://www.youtube.com/watch?v=gi9mqIha8n0)

Pendant toute la séance je travaillais avec la carte Wi-Fi. J'ai installé tous les drivers et les librairies nécessaires et j'ai testé quelques exemples.

Séance du 23 janvier 2018
-
Pendant cette séance j'ai fait une [courte présentation](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/doc/Pr%C3%A9sentation%2023.01.2018.pdf) de mon projet et j'ai regardé les présentations des [autres groupes](http://www.sofiahub.unice.fr/arduino-projet-2017-2018/).

Séance du 7 février 2018
-
J'éssayais de voir comment faire la connexion entre l'Arduino et le circuit à l'intérieur de la voiture. Finalement, j'ai décidé d'enlever ce circuit et de piloter les moteurs directement depuis Arduino. Pour le faire, j'ai besoin d'un microcontrolleur L293D qui peut piloter 2 moteurs en même temps et changer leur sens de rotation à l'aide des ponts en H.

Séance du 16 mars 2018
-
Entretemps j'ai réçu le pilote moteur L293D, la caméra IP et le haut-parleur et testé ces composants.

Pendant cette séance je m'occupais du code et aussi de l'optimisation du câblage à l'intérieur de la voiture.

Séance du 29 mars 2018
-
C'était la séance de présentations des projets à leur mi-parcours, j'écoutais les présentations des [autres groupes](http://www.sofiahub.unice.fr/arduino-projet-2017-2018/).

Séance du 5 avril 2018
-
C'était la deuxième séance de présentations des projets à leur mi-parcours. J'ai [présenté](https://github.com/Livelinndy/PeiP2_Arduino_CuriousCar/blob/master/doc/Pr%C3%A9sentation%20mi-parcours%2005.04.2018.pdf) mon projet et écouté les présentations des autres groupes. Durant le temps qui restait après les présentations, je travaillais avec le code pour améliorer le comportement des moteurs.

Séance du 9 avril 2018
-
J'avais un problème avec la caméra IP, elle montrait l'image si on se connectait directement à la caméra, mais elle ne voulait pas se connecter au réseau wi-fi. Pendant cette séance j'essayais de trouver des solutions à ce problème.

Séance du 2 mai 2018
-
Entretemps j'ai soudé des fils à l'intérieur de la voiture et fini l'optimisation du cablâge.

Pendant cette séance je travaillais avec le code pour qu'il serait possible de contrôler la voiture non seulement avec des boutons sur la page web, mais aussi avec des touches du clavier grâce à un script javascript. Comme javascript est exécuté sur le côté client, Node Mcu ne fait que transférer le code javascript avec le reste de la réponse du serveur.

Séance du 9 mai 2018
-
Il y avait un problème majeur pour rendre la voiture autonome : si on mettait l'alimentation de la carte Atmega328P Xplained Mini sur le port Vin (en connectant la masse à GND bien sûr), rien ne se passait. C'était le problème de toutes les cartes de ce type que j'ai vues (j'en ai testées au moins 5). La solution était d'utiliser un mini-powerbank qu'on peut connecter à l'Arduino avec un cable micro usb.
