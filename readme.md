
# push_swap

## Description
push_swap est un projet de l’école 42 dont l’objectif est de trier une pile d’entiers en utilisant un ensemble restreint d’opérations, tout en produisant le nombre minimal d’instructions possible.

Le programme reçoit une liste d’entiers en arguments, les place dans une pile A et doit les trier par ordre croissant en utilisant une pile auxiliaire B.

## Règles du projet

- Deux piles : A et B
- A contient initialement tous les nombres
- B est vide au départ
- Les opérations autorisées sont strictement définies
- Le programme doit afficher uniquement la liste des opérations effectuées
- Aucun affichage superflu n’est autorisé sur la sortie standard


### Opérations autorisées  

#### Swaps

- **sa** : swap des deux premiers éléments de A
- **sb** : swap des deux premiers éléments de B
- **ss** : sa et sb en même temps

#### Push

- **pa** : push le premier élément de B vers A
- **pb** : push le premier élément de A vers B

#### Rotations

- **ra** : rotation vers le haut de A
- **rb** : rotation vers le haut de B
- **rr** : ra et rb en même temps

#### Reverse rotations

- **rra** : rotation vers le bas de A
- **rrb** : rotation vers le bas de B
- **rrr** : rra et rrb en même temps

  

## Architecture du projet

Le projet est structuré de manière modulaire afin de séparer clairement :

- la gestion des piles
- les opérations bas niveau
- les algorithmes de tri
- la gestion des flags et du benchmarking

  

### Structures principales
```C
typedef  struct s_list
{
int 			value;
int				index;
struct s_list	*next;
struct s_list	*prev;
} t_stack;
```

##### Chaque élément contient :

- sa valeur réelle
- un index correspondant à sa position dans l’ordre trié (compression de valeurs)
- des pointeurs next et prev pour faciliter les rotations


```C
typedef  struct s_params
{
int 	simple;
int 	medium;
int		complex;
int 	adaptive;
int 	bench;
t_bench data;
} t_params;
```

##### Cette structure centralise :

- la stratégie de tri choisie
- le mode adaptatif
- les statistiques d’exécution (benchmark)

##### Pourquoi les #define SA SB RA ... ne sont PAS des variables globales

Dans le header :

```C
# define  SA  0
# define  SB  1
# define  SS  2
# define  PA  3
# define  PB  4
# define  RA  5
# define  RB  6
# define  RR  7
# define  RRA 8
# define  RRB 9
# define  RRR 10
```

Ces constantes ne sont pas des variables globales.

  

Elles servent uniquement à :

- définir des indices symboliques
- accéder proprement au tableau ops[11]


Exemple :

```C
flags->data.ops[RA]++;
flags->data.total++;
```

##### Avantages :
- aucun stockage mémoire
- pas de risque de modification accidentelle
- code plus lisible et maintenable
- évite les magic numbers

## Algorithmes implémentés

  

### 1. Simple — Insertion Sort (--simple)

Utilisé pour de petites entrées ou des piles presque triées

#### Principe :

- Pousser progressivement les éléments dans B
- Maintenir B triée en ordre décroissant
- Reconstruire A en ordre croissant

  

#### Complexité :

- Temps : O(n²)
	- Très efficace pour ≤ 50 éléments

### 2. Medium — Chunk-based Sort (--medium)

Adapté aux tailles moyennes (100–500)

#### Principe :

- Découper la pile en chunks
- Pousser les éléments par plages d’index
- Organiser B intelligemment
- Reconstruire A en ramenant les max successifs


#### Complexité :

- Temps : O(n√n)
	- Bon compromis entre simplicité et performance

### 3. Complex — Butterfly Sort (--complex)

Conçu pour les grandes piles (100 à 500 éléments).

#### Principe :

- Utiliser une fenêtre glissante sur les index pour transférer A vers B.
- Optimiser le placement dans B (forme de "sablier") pour faciliter le retour.
- Reconstruire A en récupérant successivement le maximum de B.

#### Complexité :

- Temps : O(n log n)
	- Optimisé pour 500 éléments (~5000 coups).
  

### 4. Adaptive (--adaptive, par défaut)

Le programme choisit automatiquement l’algorithme selon le désordre initial :

- < 20% : 			Insertion sort
- ≥ 20% && < 50% : 	Chunk-based sort
- ≥ 50% : 			Butterfly sort

  

Le désordre est calculé comme le pourcentage de paires mal ordonnées.

  

## Benchmarking (--bench)

Affiche sur stderr :
- taux de désordre initial
- stratégie utilisée
- complexité théorique
- nombre total d’opérations
- détail par type d’instruction

  

#### Exemple :

```code
[bench] disorder: 42.37%
[bench] strategy: Medium (Chunks Sort) / O(n√n)
[bench] total_ops: 742
[bench] sa: 0 sb: 0 ss: 0 pa: 250 pb: 250
[bench] ra: 120 rb: 80 rr: 0 rra: 20 rrb: 22 rrr: 0
```


## Compilation

Le projet est compilé à l’aide d’un Makefile fourni.
```bash
	make
```

#### Instructions

Le programme prend une liste d’entiers en arguments et affiche sur la sortie standard la suite d’opérations permettant de trier la pile.

```bash
./push_swap  3  2  1
```

Il est possible de forcer une stratégie de tri spécifique à l’aide des flags :
```bash
./push_swap  --simple  5  1  4  2  3
./push_swap  --medium  5  1  4  2  3
./push_swap  --complex  5  1  4  2  3
```

Le mode adaptatif et le benchmarking peuvent être combinés :
```bash
./push_swap  --bench  --adaptive  "4 67 3 87 23"
```


## Conclusion


Ce projet met l’accent sur :

- la compréhension des structures de données
- l’optimisation algorithmique
- la propreté du code
- une architecture évolutive et testable

Chaque stratégie est isolée, mesurable et interchangeable, ce qui permet une évolution progressive du projet.

## Contributions

Ce projet a été réalisé en collaboration par nbilyj et nbarbosa.

Le travail a été réparti de manière équilibrée autour des grands axes du projet :

- nbilyj :
	- Mise en place de l’architecture globale du projet
	- Implémentation des structures de données et de la gestion des piles
	- Implémentation des opérations bas niveau (swap, push, rotate)
	- Relecture, tests et amélioration de la lisibilité du code

- nbarbosa :
	- Gestion des flags, du mode adaptatif et du benchmarking
	- Développement des algorithmes de tri
	- Outils de mesure, statistiques et affichage conditionnel
	- Optimisation des performances et gestion des cas limites

Les décisions algorithmiques et architecturales ont été prises conjointement, avec des phases régulières de revue de code et de tests afin de garantir la cohérence, la robustesse et la conformité au sujet.

//TODO : voir bas de page 12