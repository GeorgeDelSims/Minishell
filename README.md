# Minishell

ETAPES: 

1. Structurer les données (t_data struct, t_cmd struct etc.)
2. Parsing : ranger les inputs dans des listes chaînées afin de pouvoir les trier et interpreter
3. Execution de commandes basiques (sans arguments ni redirection ou pipe). 
4. Signal handling : loop infinie dans le main, interrompue par différents signaux (SIGINT etc.) - 1 variable globale pour ça 
5. Comprendre et implémenter la fonction "history" 
6. Comprendre et implémenter redirections et pipes

FONCTIONNEMENT: 

- Toujours commencer petit, tester et ensuite ajouter des fonctionalités 
- Une branche git pour chaque nouvelle fonctionnalité. On la teste, on la valide et on push sur le master. 
- bien structurer le minishell.h 