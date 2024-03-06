# Minishell

ETAPES: 

1. Structurer les données (t_data struct, t_cmd struct etc.)
2. Parsing : ranger les inputs dans des listes chaînées afin de pouvoir les trier et interpreter
3. Execution de commandes basiques sans arguments ni redirection ou pipe ( "cd" "exit" "export"). 
4. Signal handling : loop infinie dans le main, interrompue par différents signaux (SIGINT etc.) - 1 variable globale pour ça 
5. Comprendre et implémenter la fonction "history" 
6. Comprendre et implémenter redirections et pipes

FONCTIONNEMENT: 

- Toujours commencer petit, tester et ensuite ajouter des fonctionalités 
- Une branche git pour chaque nouvelle fonctionnalité. On la teste, on la valide et on push sur le master. 
- bien structurer le minishell.h 

FONCTIONS: 

# readline:
 Lit une ligne de texte depuis l'entrée standard, permettant à l'utilisateur de modifier cette ligne avec des touches de contrôle.
# rl_clear_history:
 Efface l'historique des commandes stockées par readline.
# rl_on_new_line:
 Prépare readline à commencer une nouvelle ligne.
# rl_replace_line:
 Remplace le contenu de la ligne courante dans readline.
# rl_redisplay:
 Redessine la ligne courante dans l'interface readline.
# add_history:
 Ajoute une ligne à l'historique des commandes de readline.
# access:
 Vérifie les droits d'accès à un fichier.
# fork:
 Crée un nouveau processus enfant qui est une copie du processus parent.
# wait:
 Attend la fin d'exécution d'un processus enfant.
# waitpid:
 Attend un processus enfant spécifique ou n'importe lequel.
# wait3,
 wait4: Variants de waitpid avec plus d'options et de récupération d'informations.
# signal:
 Permet de gérer les signaux reçus par un processus.
# sigaction:
 Fournit un contrôle plus précis sur le comportement lors de la réception de signaux.
# sigemptyset,
 sigaddset: Initialisent et ajoutent des signaux à un ensemble de signaux.
# kill:
 Envoie un signal à un processus spécifié.
# exit:
 Termine l'exécution du programme courant.
# getcwd:
 Obtient le chemin du répertoire courant.
# chdir:
 Change le répertoire courant.
# stat,
 lstat, fstat: Récupèrent les informations sur un fichier.
# unlink:
 Supprime un lien vers un fichier, le supprimant s'il s'agit du dernier lien.
# execve:
 Remplace le programme courant par un nouveau programme.
# dup,
 dup2: Dupliquent un descripteur de fichier.
# pipe:
 Crée un tube (pipe) pour la communication entre processus.
# opendir:
 Ouvre un flux de répertoire.
# readdir:
 Lit une entrée dans un répertoire.
# closedir:
 Ferme un flux de répertoire ouvert.
# strerror:
 Retourne un message décrivant une erreur.
# perror:
 Affiche un message décrivant la dernière erreur rencontrée.
# isatty:
 Vérifie si un descripteur de fichier est un terminal.
# ttyname:
 Retourne le nom du terminal associé à un descripteur de fichier.
# ttyslot:
 Trouve le numéro d'emplacement du terminal.
# ioctl:
 Manipule les paramètres du périphérique sous-jacent pour un descripteur de fichier.
# getenv:
 Récupère la valeur d'une variable d'environnement.
# tcsetattr, tcgetattr: 
Configurent les attributs du terminal.
# tgetent,tgetflag, tgetnum, tgetstr, tgoto, tputs: 
Fonctions de gestion de terminal dans la bibliothèque termcap pour le contrôle des capacités du terminal.


