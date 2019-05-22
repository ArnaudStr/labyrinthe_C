Programme codé en C qui crée aléatoirement dans le terminal un labyrinthe de taille fixée. 
Tout le sujet et la description complète du programme est dispobible dans le fichier projet.pdf.
Utilisation de la librairie X11.

Commande pour générer un labyrinthe :

./genlab [-v] [-d] [-l <largeur>] [-h <hauteur>] <fichier>

-v : visualise le labyrinthe pendant sa génération.
-d : visualise le labyrinthe et les cases constructibles pendant la génération (implique -v).
-l <largeur> et -h <hauteur> : largeur et hauteur du labyrinthe, en nombre de cases.
Taille de la fenêtre pas plus de 1000 x 800 pixels), valeurs par défaut : largeur = 300, hauteur = 200.
<fichier> : nom de fichier dans lequel le labyrinthe sera sauvegardé.

Commande pour trouver un chemin vers la sortie du labyrinthe :

./cheminlab [-v] <fichier>

-v : visualise le parcours du labyrinthe pendant la recherche.
<fichier> : nom du fichier labyrinthe à lire.