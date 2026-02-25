Jacobsthal


/*Ford-Johnson */ (merge-insert sort)

algo par paire


lower_bound : trouve le premier élément ≥ valeur



1, 3, 5, 11, 21, 43,



2.1. Situation après split et premier low

On avait :
45 8 65 20 366 98 1 74 21 47 12 88 9

Après toutes les étapes “paires triées par highs” et split, ton fichier donne :

​

    highs : 45 47 65 74 88 366

    lows : 8 21 20 1 12 98

    reste : 9

Puis on fait :

    on prend le premier low 8

    on le met devant les highs → ça te crée la première liste triée principale :

text
séquence principale (triée) : [8 45 47 65 74 88 366]
pending                      : [21 20 1 12 98 9]

À partir de là, toutes les insertions de pending se font dans cette liste triée.
3) Exemple concret : insertion dans la liste de grands
3.1. Ordre d’insertion (indices de pending)

On a :
pending = [21, 20, 1, 12, 98, 9]
indices : [0 1 2 3 4 5]

​

L’ordre Jacobsthal construit :
[0, 2, 1, 4, 3, 5]

​

Donc on insère, dans cet ordre :

    pending = 21

    pending = 1

​

pending = 20

​

pending = 98

​

pending = 12

​

pending = 9

    ​

Toujours dans la liste triée courante.
3.2. Où on insère 21 exactement ?

Liste triée actuelle :
[8 45 47 65 74 88 366]

​

On veut insérer 21 au bon endroit, de façon à ce que la liste reste triée.

Intuitivement, tu vois que ça doit donner :
[8 21 45 47 65 74 88 366].

L’algorithme fait ça avec une binary search (eux l’écrivent avec begin/end/mid, mais la conclusion est “insérer avant 45”).

​
En version “normale” (sans chercher à optimiser) :

    tu cherches la première valeur ≥ 21 dans la liste,

    tu insères avant cette valeur.



/******/

pour creer des paires :


UNE seule paire : std::pair<int, int> 

std::pair<int, int> p;
p.first = 8;    // premier élément
p.second = 45;  // deuxième élément


ex :
std::pair<int, int> paire1 = std::make_pair(8, 45);
std::cout << paire1.first;   // 8
std::cout << paire1.second;  // 45


LISTE de PLUSIEURS PAIRES : vector<pair<int,int>>

ex :
std::vector<std::pair<int,int>> pairs;

pairs.push_back(std::make_pair(8, 45));
pairs.push_back(std::make_pair(20, 65));
pairs.push_back(std::make_pair(98, 366));

// Maintenant pairs contient :
// pairs[0] = {8, 45}
// pairs[1] = {20, 65}
// pairs[2] = {98, 366}

std::cout << pairs[0].first;   // 8
std::cout << pairs[0].second;  // 45
std::cout << pairs[1].first;   // 20