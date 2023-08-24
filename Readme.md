### Structures de données
La structure `Room` : Cette structure représente une salle. Elle a les champs suivants :
- `number` : Le numéro de la salle.
- `money` : Le montant d'argent dans la salle.
- `doors[2]` : Les portes de la salle. Les valeurs sont les numéros des salles adjacentes. Si la porte mène à l'extérieur (E), la valeur est -1.
- `depth` : La profondeur de la salle dans le bâtiment (initialisée à -1).
- `maxMoney` : Le montant maximal d'argent qui peut être obtenu en commençant de cette salle (initialisée à -1).

La structure `Building` : Cette structure représente le bâtiment. Elle contient un tableau de salles (`rooms`) et le nombre total de salles (`numRooms`).

### Lecture des données
La fonction `readRooms` lit les données d'entrée pour le bâtiment. Elle prend en paramètre un pointeur vers une structure `Building` et remplit ses champs en utilisant les données lues depuis l'entrée standard. Chaque salle est lue avec son numéro, le montant d'argent qu'elle contient, et les numéros des salles adjacentes (ou 'E' pour extérieur) pour les deux portes.

### Calcul de la profondeur maximale
La fonction `calcMaxDepth` calcule la profondeur maximale de chaque salle en utilisant une approche de recherche en profondeur (DFS - Depth-First Search). Les détails de cette fonction sont les suivants :
- On initialise `maxDepth` à 0 pour stocker la profondeur maximale du bâtiment.
- On initialise `depth` à -1 pour toutes les salles du bâtiment, indiquant qu'elles n'ont pas encore été visitées.
- On utilise une pile (`stack`) pour maintenir les salles à visiter. `top` est un indice qui pointe sur le sommet de la pile, initialisé à -1.
- On empile la première salle (souvent la salle numéro 0) sur la pile.
- Tant que la pile n'est pas vide (`top >= 0`), on dépile une salle (`currentRoom`) et on vérifie si elle a déjà été visitée (c'est-à-dire que sa profondeur a été calculée). Si ce n'est pas le cas, on calcule la profondeur maximale de cette salle en examinant les profondeurs de ses salles adjacentes.
- On met à jour `maxDepth` si la profondeur actuelle est plus grande.
- On empile les salles adjacentes non visitées sur la pile.

### Calcul du montant maximal d'argent
La fonction `calcMaxMoney` calcule le montant maximal d'argent qui peut être obtenu en partant de chaque salle en utilisant une approche similaire à `calcMaxDepth`. Les détails de cette fonction sont les suivants :
- On initialise `maxMoney` à -1 pour toutes les salles du bâtiment, indiquant qu'elles n'ont pas encore été visitées pour calculer le montant maximal.
- On utilise une pile (`stack`) pour maintenir les salles à visiter, de la même manière qu'avec `calcMaxDepth`.
- Tant que la pile n'est pas vide, on dépile une salle (`currentRoom`) et on vérifie si le montant maximal a déjà été calculé pour cette salle. Si ce n'est pas le cas, on calcule le montant maximal en examinant les montants maximaux de ses salles adjacentes.
- On met à jour le `maxMoney` de la salle actuelle en ajoutant le montant d'argent qu'elle contient au montant maximal des salles adjacentes.
- On empile les salles adjacentes non visitées sur la pile.

### Fonction principale (`main`)
La fonction `main` est le point d'entrée du programme. Elle effectue les opérations suivantes :
- Initialise une structure `Building` et lit les données du bâtiment en appelant `readRooms`.
- Parcours toutes les salles pour calculer leur profondeur maximale en appelant `calcMaxDepth`.
- Parcours toutes les salles pour calculer le montant maximal d'argent en appelant `calcMaxMoney`.
- Affiche le montant maximal d'argent qui peut être obtenu à partir de la salle numéro 0 (la salle de départ).
- L'approche récursive utilisée pour les fonctions `calcMaxDepth

` et `calcMaxMoney` permet de parcourir le bâtiment de manière efficace et de calculer les résultats optimaux pour chaque salle.