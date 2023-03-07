# TP de INF224
Auteur : Denis Fouchard


## Build, run
Se placer dans le dossier racine du projet.

**Pour compiler le code C++ et lancer le serveur**
```
cd cpp
make run
```

**Pour compiler et lancer le serveur et le client C++ en même temps**
```
cd cpp
make run-cliserv
```
**Pour compiler la télécommande Java et la lancer**
```
cd swing
make run
```
**Pour compiler le client et le serveur C++ séparément**
```
cd cpp
make server
make client
```
*Après on pourra lancer séparement le client et le serveur C++ avec les commandes*
```
./MediaServer
./client
```



## Fichiers .h et .cpp
Pour les classes qui ne nécessitent pas beaucoup de code j'ai préféré implémenter les méthodes directement dans le fichier header. Les classes qui demandaient un peu plus de code comme **multimedia**, **films**,  **table** (gestion des fichiers et groupes par des **std::map**) sont codées dans des fichier .cpp à part.

## Commandes client
Liste des commandes pour la console client C++.
>- Afficher la liste de tous les groupes : SHOWALLGROUPS
>- Rechercher et afficher un média : SHOWMEDIA [media]
>- Rechercher et afficher un groupe : SHOWGROUP [group]
>- Afficher la liste des médias d'un groupe : LISTGROUP [group]
>- Créer un groupe : CREATEGROUP [group]
>- Supprimer un groupe : DELETEGROUP [group]
>- Supprimer un média : DELETEMEDIA [media]
>- Jouer un média : PLAY


#
## 4ème Etape : Photos et vidéos
> Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?

La méthode **play()** n'a pas d'implémentation dans la classe mère, il s'agit d'une classe abstraite. Elle est déclarée ainsi :
```
virtual void play() = 0;
```
> Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?

Il n'est plus possible d'instancier une classe avec des méthodes abstraites, car elle devient une **classe abstraite**.
___
## 5e Etape: Traitement uniforme (en utilisant le polymorphisme)

>Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?

Il s'agit d'effectuer du **traitement uniforme** des objets hérités d'une même classe de base, ce qui est permis par le **polymorphisme**. 

>Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?

Pour permettre le traitement uniforme en C++ il est nécessaire de déclarer toutes les méthodes **virtual** dans la classe de base pour permettre une liaison dynamique des méthodes.

>Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.

Le tableau doit contenir des pointeurs afin de permettre la liaison dynamique. En Java, la liaison est dynamique par défaut, on stocke directement les objets dans le tableau. 
___
## 7e étape. Destruction et copie des objets
> Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ?

Lors de la destruction d'un objet, si l'on ne modifie pas le destructeur par défaut seuls les variables de classe qui contiennent des types de base sont détruites ainsi que les pointeurs vers les objets mais pas les objets eux même. Il faut modifier les destructeurs des classes qui contiennent des variables qui sont des pointeurs vers d'autres objets, afin que ces objets soient aussi détruits lors de la destruction de l'objet inital. Cela concerne donc à cette étape la classe **Film** qui contient une variable de classe *chapters* qui est un tableau d'entiers.
Il faut ajouter le code 
```
delete[] chapters;
```


> La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?

Si on copie l'objet directement, seuls les pointeurs des variables de classes sont copiés mais pas les objets pointés (*shallow copy*). Il faut redéfinir l'opérateur de copie en implémentant la copie des objets (*deep copy*). 
___
## 8e étape. Créer des groupes
> Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.

La liste doit contenir un seul type d'objets. Pour permettre le polymorphisme nous devons utiliser des ```Multimedia* ```pointeurs. En Java, aucune manipulation n'est nécessaire car les objets sont traités sous forme de référence directement. 
___
## 10e étape. Gestion cohérente des données

>Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?

Nous pouvons restreindre l'accès au constructeurs des objets multimédias à la classe ```Table``` avec le mot clé ```friend```.
___
## 1ere Etape: Fenêtre principale et quelques interacteurs
> Lancez votre programme, cliquez plusieurs fois sur les deux premiers bouton, retaillez la fenêtre. Que constate-t'on ?
La fenêtre de texte est trop petite. Il faut utiliser un ```BorderLayout```. 
