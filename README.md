# Cpp Bootcamp

Ce dépôt regroupe mes exercices du bootcamp C++.

Le projet est organisé en dossiers par module, de `Cpp00` à `Cpp09`, avec un ou plusieurs exercices dans chaque module.

## Structure

- `Cpp00/` : bases du langage C++
- `Cpp01/` : mémoire dynamique, références et pointeurs
- `Cpp02/` : surcharge d'opérateurs et règles de base
- `Cpp03/` : héritage
- `Cpp04/` : polymorphisme et classes abstraites
- `Cpp05/` : exceptions
- `Cpp06/` : casts
- `Cpp07/` : templates
- `Cpp08/` : conteneurs et itérateurs simples
- `Cpp09/` : STL et algorithmes

## Compilation

Pour compiler un exercice, place-toi dans son dossier puis lance :

```bash
make
```

Exemple :

```bash
cd Cpp00/ex00
make
```

## Règles générales

- Compilation en `C++98`
- Flags courants : `-Wall -Wextra -Werror`
- Un exécutable est généré par exercice, selon le `Makefile`

## Nettoyage

La plupart des exercices fournissent les cibles suivantes :

- `make clean` : supprime les fichiers objets
- `make fclean` : supprime les fichiers objets et l'exécutable
- `make re` : reconstruit le projet

## Utilisation

Chaque exercice doit être lancé depuis son propre dossier, sauf indication contraire dans le `Makefile`.

Exemple :

```bash
./megaphone
```

ou, selon l'exercice :

```bash
./PmergeMe
```

## Notes

- Les noms d'exécutables changent selon le module.
- Certains exercices demandent des arguments en ligne de commande.