#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void afficherMenu();
void jouerAddition(int *score);
void jouerMultiplication(int *score);
void jouerSoustraction(int *score);
void tablesDeMultiplication(int *score);
void jouerDivision(int *score);
void jouerCompteEstBon(int *score);
void ajoutScore(int *score, int points);
void sauvegarderScore(const char *nom, int score);
int chargerScore(const char *nom);
int evaluerExpression(const char *expression);

void afficherMenu() {
  printf("1 : Addition\n"); // option pour jouer a l'addition
  printf("2 : Soustraction\n"); // option pour jouer a la soustraction
  printf("3 : Multiplication\n"); // option pour jouer a la multiplication
  printf("4 : Tables des multiplications\n"); // option pour les tables
  printf("5 : Divisions\n"); // option pour jouer a la division
  printf("6 : Compte est bon\n"); // option pour le jeu "le compte est bon"
  printf("0 : Sortir du jeu\n"); // quitter le jeu
}

int main() {
  int choix; // stocke le choix du joueur
  char nom[50]; // stocke le nom du joueur
  srand(time(NULL)); // initialise le generateur de nombres aleatoires

  printf("Entrez votre nom : "); // demander le nom du joueur
  scanf("%s", nom); // lire le nom
  int score = chargerScore(nom); // charger le score du joueur depuis le fichier

  do {
    afficherMenu(); // afficher le menu
    printf("Quel est votre choix ? "); // demander le choix
    scanf("%d", &choix); // lire le choix

    switch (choix) {
    case 1:
      printf("Addition\n");
      jouerAddition(&score); // lancer le jeu d'addition
      break;
    case 2:
      printf("Soustraction\n");
      jouerSoustraction(&score); // lancer le jeu de soustraction
      break;
    case 3:
      printf("Multiplication\n");
      jouerMultiplication(&score); // lancer le jeu de multiplication
      break;
    case 4:
      printf("Tables des multiplications\n");
      tablesDeMultiplication(&score); // lancer les tables de multiplication
      break;
    case 5:
      printf("Divisions\n");
      jouerDivision(&score); // lancer le jeu de division
      break;
    case 6:
      printf("Le Compte est Bon\n");
      jouerCompteEstBon(&score); // lancer le jeu "le compte est bon"
      break;
    case 0:
      printf("Merci de votre visite\n"); // message de fin
      break;
    default:
      printf("Choix invalide\n"); // message pour un choix incorrect
    }
    printf("Votre score actuel est : %d\n", score); // afficher le score actuel
  } while (choix != 0); // continuer tant que le joueur ne choisit pas de quitter

  sauvegarderScore(nom, score); // sauvegarder le score du joueur
  return 0; // fin du programme
}

void ajoutScore(int *score, int points) { (*score) += points; }

void jouerAddition(int *score) {
  int a = rand() % 101; // generer un nombre aleatoire entre 0 et 100
  int b = rand() % 101; // generer un autre nombre aleatoire
  int resultat, reponse;
  int essais = 0; // compteur d'essais

  printf("%d + %d = ?\n", a, b); // afficher l'operation
  do {
    printf("Entrez le résultat : "); // demander la reponse
    scanf("%d", &reponse); // lire la reponse
    essais++; // incrementer le compteur d'essais

    resultat = a + b; // calculer le resultat
    if (reponse == resultat) { // verifier si la reponse est correcte
      printf("Bravo!\n");
      if (essais == 1)
        ajoutScore(score, 10); // 10 points si reussi au 1er essai
      else if (essais == 2)
        ajoutScore(score, 5); // 5 points si reussi au 2e essai
      else if (essais == 3)
        ajoutScore(score, 1); // 1 point si reussi au 3e essai
      break;
    } else {
      printf("Mauvaise réponse. Essayez encore.\n"); // reponse incorrecte
    }
  } while (essais < 3); // maximum 3 essais

  if (essais == 3 && reponse != resultat) {
    printf("Mauvaise réponse. La réponse correcte est %d.\n", resultat); // afficher la bonne reponse
  }
}
// Fonction pour jouer au jeu de multiplication
void jouerMultiplication(int *score) {
  int a = rand() % 10 + 1;
  int b = rand() % 10 + 1;
  int resultat, reponse;
  int essais = 0;

  printf("%d * %d = ?\n", a, b);
  do {
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    essais++;

    resultat = a * b;
    if (reponse == resultat) {
      printf("Bravo!\n");
      if (essais == 1)
        ajoutScore(score, 10);
      else if (essais == 2)
        ajoutScore(score, 5);
      else if (essais == 3)
        ajoutScore(score, 1);
      break;
    } else {
      printf("Mauvaise réponse. Essayez encore.\n");
    }
  } while (essais < 3);

  if (essais == 3 && reponse != resultat) {
    printf("Mauvaise réponse. La réponse correcte est %d.\n", resultat);
  }
}
// Fonction pour jouer au jeu de soustraction
void jouerSoustraction(int *score) {
  int a = rand() % 101;
  int b = rand() % 101;
  int resultat, reponse;
  int essais = 0;

  if (a < b) {
    int temp = a;
    a = b;
    b = temp;
  }

  printf("%d - %d = ?\n", a, b);
  do {
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    essais++;

    resultat = a - b;
    if (reponse == resultat) {
      printf("Bravo!\n");
      if (essais == 1)
        ajoutScore(score, 10);
      else if (essais == 2)
        ajoutScore(score, 5);
      else if (essais == 3)
        ajoutScore(score, 1);
      break;
    } else {
      printf("Mauvaise réponse. Essayez encore.\n");
    }
  } while (essais < 3);

  if (essais == 3 && reponse != resultat) {
    printf("Mauvaise réponse. La réponse correcte est %d.\n", resultat);
  }
}

void tablesDeMultiplication(int *score) {
  int table, reponse;
  printf("Choisissez une table (1 à 10) : ");
  scanf("%d", &table);

  for (int i = 1; i <= 10; i++) {
    int essais = 0;
    printf("%d * %d = ?\n", table, i);
    do {
      printf("Entrez le résultat : ");
      scanf("%d", &reponse);
      essais++;

      if (reponse == table * i) {
        printf("Bravo!\n");
        if (essais == 1)
          ajoutScore(score, 10);
        else if (essais == 2)
          ajoutScore(score, 5);
        else if (essais == 3)
          ajoutScore(score, 1);
        break;
      } else {
        printf("Mauvaise réponse. Essayez encore.\n");
      }
    } while (essais < 3);

    if (essais == 3 && reponse != table * i) {
      printf("Mauvaise réponse. La réponse correcte est %d.\n", table * i);
    }
  }
}
// Fonction pour jouer au jeu de division
// Le joueur doit entrer la réponse avec une décimale
void jouerDivision(int *score) {
  int a = rand() % 101;
  int b = rand() % 10 + 1;
  float resultat, reponse;
  int essais = 0;

  printf("%d / %d = ? (réponse avec une décimale)\n", a, b);
  do {
    printf("Entrez le résultat : ");
    scanf("%f", &reponse); // Lire un float
    essais++;

    resultat = (float)a / b; // Calculer le résultat en float
    if (fabs(reponse - resultat) < 0.1) { // Vérifier si la réponse est proche du résultat (tolérance de 0.1)
      printf("Bravo!\n");
      if (essais == 1)
        ajoutScore(score, 10);
      else if (essais == 2)
        ajoutScore(score, 5);
      else if (essais == 3)
        ajoutScore(score, 1);
      break;
    } else {
      printf("Mauvaise réponse. Essayez encore.\n");
    }
  } while (essais < 3);

  if (essais == 3 && fabs(reponse - resultat) >= 0.1) {
    printf("Mauvaise réponse. La réponse correcte est %.1f.\n", resultat);
  }
}
// Fonction pour évaluer une expression mathématique simple
// Renvoie le résultat de l'évaluation ou -1 en cas d'erreur
int evaluerExpression(const char *expression) {
  int resultat = 0, nombre = 0;
  char operateur = '+';
  const char *p = expression;

  while (*p) {
    if (isdigit(*p)) {
      nombre = 0;
      while (isdigit(*p)) {
        nombre = nombre * 10 + (*p - '0');
        p++;
      }
      if (operateur == '+') {
        resultat += nombre;
      } else if (operateur == '-') {
        resultat -= nombre;
      } else if (operateur == '*') {
        resultat *= nombre;
      } else if (operateur == '/') {
        if (nombre != 0) {
          resultat /= nombre;
        } else {
          printf("Erreur : Division par zéro.\n");
          return -1;
        }
      }
    } else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
      operateur = *p;
      p++;
    } else {
      p++;
    }
  }

  return resultat;
}
// Fonction pour jouer au jeu "Le Compte est Bon"
void jouerCompteEstBon(int *score) {
  int cible = rand() % 900 + 100;
  int nombres[6];
  char operations[100];
  int resultat = 0;

  for (int i = 0; i < 6; i++) {
    nombres[i] = rand() % 10 + 1;
  }

  printf("Le nombre cible est : %d\n", cible);
  printf("Utilisez ces nombres pour atteindre le nombre cible : ");
  for (int i = 0; i < 6; i++) {
    printf("%d ", nombres[i]);
  }
  printf("\n");

  printf("Entrez votre solution (par exemple : 25 + 50 - 10) : ");
  scanf(" %[^\n]", operations);

  resultat = evaluerExpression(operations);

  if (resultat == -1) {
    printf("Erreur dans le calcul. Aucun point attribué.\n");
    return;
  }

  int difference = abs(cible - resultat);

  if (difference == 0) {
    printf("Bravo, vous avez trouvé le bon résultat !\n");
    ajoutScore(score, 20);
  } else if (difference <= 10) {
    printf("Très proche ! Vous gagnez 15 points.\n");
    ajoutScore(score, 15);
  } else if (difference <= 20) {
    printf("Pas mal ! Vous gagnez 10 points.\n");
    ajoutScore(score, 10);
  } else if (difference <= 50) {
    printf("Vous êtes loin, mais vous gagnez 5 points.\n");
    ajoutScore(score, 5);
  } else {
    printf("Dommage, vous ne gagnez aucun point. La réponse correcte était %d.\n", cible);
  }
}
// Fonction pour sauvegarder le score d'un joueur dans un fichier
void sauvegarderScore(const char *nom, int score) {
  FILE *fichier = fopen("scores.txt", "r");
  if (fichier == NULL) {
    fichier = fopen("scores.txt", "w");
    if (fichier == NULL) {
      printf("Erreur lors de l'ouverture du fichier.\n");
      return;
    }
  }

  char lignes[100][100];
  int nbLignes = 0;
  char nomFichier[50];
  int scoreFichier;
  bool joueurExistant = false;
// Vérifier si le joueur existe déjà
  // Lire le fichier ligne par ligne
  // et stocker les lignes dans un tableau
  while (fgets(lignes[nbLignes], sizeof(lignes[nbLignes]), fichier)) {
    sscanf(lignes[nbLignes], "%s %d", nomFichier, &scoreFichier);
    if (strcmp(nomFichier, nom) == 0) {
      joueurExistant = true;
      time_t maintenant = time(NULL);
      snprintf(lignes[nbLignes], sizeof(lignes[nbLignes]), "%s %d %s", nom, score, ctime(&maintenant));
    }
    nbLignes++;
  }
  fclose(fichier);
// Fermer le fichier après la lecture
// Réouvrir le fichier en mode écriture
  if (!joueurExistant) {
    time_t maintenant = time(NULL);
    snprintf(lignes[nbLignes], sizeof(lignes[nbLignes]), "%s %d %s", nom, score, ctime(&maintenant));
    nbLignes++;
  }

  fichier = fopen("scores.txt", "w");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return;
  }

  for (int i = 0; i < nbLignes; i++) {
    fputs(lignes[i], fichier);
  }
  fclose(fichier);
}
// Fonction pour charger le score d'un joueur depuis le fichier
// Renvoie le score du joueur ou 0 si le joueur n'existe pas
// Le nom du joueur est passé en paramètre
int chargerScore(const char *nom) {
  FILE *fichier = fopen("scores.txt", "r");
  if (fichier == NULL) {
    return 0;
  }

  char nomFichier[50];
  int score;
  while (fscanf(fichier, "%s %d", nomFichier, &score) == 2) {
    if (strcmp(nomFichier, nom) == 0) {
      fclose(fichier);
      return score;
    }
  }
  fclose(fichier);
  return 0;
}

