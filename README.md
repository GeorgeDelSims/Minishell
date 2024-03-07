# Minishell

ETAPES: 

- Signal handling : loop infinie dans le main, interrompue par différents signaux (SIGINT etc.) - 1 variable globale pour ça 
- Structurer les données (t_data struct, t_cmd struct etc.)
- Parsing : ranger les inputs dans des listes chaînées afin de pouvoir les trier et interpreter
- Execution de commandes basiques sans arguments ni redirection ou pipe ( "cd" "exit" "export"). 
- Comprendre et implémenter la fonction "history" 
- Comprendre et implémenter redirections et pipes

FONCTIONNEMENT: 

- Toujours commencer petit, tester et ensuite ajouter des fonctionalités 
- Une branche git pour chaque nouvelle fonctionnalité. On la teste, on la valide et on push sur le master. 
- bien structurer le minishell.h 

GITHUB MARCHE A SUIVRE : 

1. Chacun clone le Repo sur sa machine avec git clone
2. Chacun va créer sa propre branche avec la commande “git checkout -b <my_branch>”
3. Chacun fait ses modifs en local puis les commit a sa propre branche avec git add + git commit
4. Push sur le depot distant de notre branche avec “Git push origin <my_branch>”
5. Creer une “pull request” -> aller sur le repo sur GitHub et cliquer sur “pull requests” -> “New pull request” -> <my_branch>
6. Revoir les changements et fusionner la pull request
7. Pull les changements vers la branche principale locale (le main sur nos machines individuelles). -> “git checkout main” -> “git pull origin main”


FONCTIONS: 

## char* readline(const char *prompt)
Lit une ligne de texte depuis l'entrée standard, permettant à l'utilisateur de modifier cette ligne avec des touches de contrôle.

## void rl_clear_history(void)
Efface l'historique des commandes stockées par readline.

## int rl_on_new_line(void)
Prépare readline à commencer une nouvelle ligne.

## void rl_replace_line(const char *text, int clear_undo)
Remplace le contenu de la ligne courante dans readline.

## void rl_redisplay(void)
Redessine la ligne courante dans l'interface readline.

## void add_history(const char *line)
Ajoute une ligne à l'historique des commandes de readline.

## int printf(const char *format, ...)
Affiche une chaîne formatée à l'écran.

## void* malloc(size_t size)
Alloue dynamiquement de la mémoire dans le tas et retourne un pointeur vers celle-ci.

## void free(void *ptr)
Libère la mémoire allouée précédemment par malloc.

## ssize_t write(int fd, const void *buf, size_t count)
Écrit `count` octets de `buf` dans le fichier décrit par `fd`.

## int access(const char *pathname, int mode)
Vérifie les droits d'accès pour le fichier spécifié par `pathname`.

## int open(const char *pathname, int flags, mode_t mode)
Ouvre un fichier spécifié et retourne un descripteur de fichier.

## ssize_t read(int fd, void *buf, size_t count)
Lit `count` octets du fichier décrit par `fd` dans `buf`.

## int close(int fd)
Ferme un descripteur de fichier ouvert.

## pid_t fork(void)
Crée un nouveau processus enfant qui est une copie du processus parent.

## pid_t wait(int *status)
Attend la fin d'exécution d'un processus enfant.

## pid_t waitpid(pid_t pid, int *status, int options)
Attend un processus enfant spécifique ou n'importe lequel.

## int wait3(int *status, int options, struct rusage *rusage)
## int wait4(pid_t pid, int *status, int options, struct rusage *rusage)
Variants de waitpid avec plus d'options et de récupération d'informations.

## sighandler_t signal(int signum, sighandler_t handler)
Permet de gérer les signaux reçus par un processus.

## int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
Fournit un contrôle plus précis sur le comportement lors de la réception de signaux.

## int sigemptyset(sigset_t *set), int sigaddset(sigset_t *set, int signum)
Initialisent et ajoutent des signaux à un ensemble de signaux.

## int kill(pid_t pid, int sig)
Envoie un signal `sig` à un processus spécifié `pid`.

## void exit(int status)
Termine l'exécution du programme courant avec un statut.

## char* getcwd(char *buf, size_t size)
Obtient le chemin du répertoire courant.

## int chdir(const char *path)
Change le répertoire courant.

## int stat(const char *pathname, struct stat *statbuf), int lstat(const char *pathname, struct stat *statbuf), int fstat(int fd, struct stat *statbuf)
Récupèrent les informations sur un fichier.

## int unlink(const char *pathname)
Supprime un lien vers un fichier.

## int execve(const char *pathname, char *const argv[], char *const envp[])
Remplace le programme courant par un nouveau programme.

## int dup(int oldfd), int dup2(int oldfd, int newfd)
Dupliquent un descripteur de fichier.

## int pipe(int pipefd[2])
Crée un tube (pipe) pour la communication entre processus.

## DIR* opendir(const char *name)
Ouvre un flux de répertoire.

## struct dirent* readdir(DIR *dirp)
Lit une entrée dans un répertoire.

## int closedir(DIR *dirp)
Ferme un flux de répertoire ouvert.

## char* strerror(int errnum)
Retourne un message décrivant une erreur.

## void perror(const char *s)
Affiche un message décrivant la dernière erreur rencontrée.

## int isatty(int fd)
Vérifie si un descripteur de fichier est un terminal.

## char* ttyname(int fd)
Retourne le nom du terminal associé à un descripteur de fichier.

## int ttyslot(void)
Trouve le numéro d'emplacement du
