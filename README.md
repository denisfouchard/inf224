## TP de INF224
*Denis Fouchard*

Le projet a été codé sur les IDE **Qt-Creator** et **VSCode**.
Il a été maintenu sur un dépot git (lien).

## Fichiers .h et .cpp
Pour les classes qui ne nécessitent pas beaucoup de code j'ai préféré implémenter les méthodes directement dans le fichier header. Les classes qui demandaient un peu plus de code comme **multimedia** et **files** (gestion des fichiers et groupes par des **std::map**) sot codées dans des fichier .cpp à part.

## Tables
J'ai choisi de donner directement comme argument aux méthodes showObjects des objets la console **std::cout** au lieu de laisser le choix à l'utilisateur de la méthode showObjects de la classe Table.

## Commandes client
Nous implémentons les fonctions client suivantes :
- Rechercher et afficher un média : show [media]
- Jouer un média : play [media]
