#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void afficherMenu();
void jouerAddition(int *score);
void jouerMultiplication(int *score);
void jouerSoustraction(int *score);
void tablesDeMultiplication(int *score);
void jouerDivision(int *score);
void ajoutScore(int *score, int points);
void sauvegarderScore(const char *nom, int score);
int chargerScore(const char *nom);

void afficherMenu() {
  printf("1 : Addition\n");
  printf("2 : Soustraction\n");
  printf("3 : Multiplication\n");
  printf("4 : Tables des multiplications\n");
  printf("5 : Divisions\n");
  printf("6 : Compte est bon\n");
  printf("0 : Sortir du jeu\n");
}

int main() {
  int choix;
  char nom[50];
  srand(time(NULL));

  printf("Entrez votre nom : ");
  scanf("%s", nom);
  int score = chargerScore(nom);

  do {
    afficherMenu();
    printf("Quel est votre choix ? ");
    scanf("%d", &choix);

    switch (choix) {
    case 1:
      printf("Addition\n");
      jouerAddition(&score);
      break;
    case 2:
      printf("Soustraction\n");
      jouerSoustraction(&score);
      break;
    case 3:
      printf("Multiplication\n");
      jouerMultiplication(&score);
      break;
    case 4:
      printf("Tables des multiplications\n");
      tablesDeMultiplication(&score);
      break;
    case 5:
      printf("Divisions\n");
      jouerDivision(&score);
      break;
    case 6:
      printf("Compte est bon\n");
      jeu_des_operations(&score);
      break;
    case 0:
      printf("Merci de votre visite\n");
      break;
    default:
      printf("Choix invalide\n");
    }
    printf("Votre score actuel est : %d\n", score);
  } while (choix != 0);

  sauvegarderScore(nom, score);
  return 0;
}

void ajoutScore(int *score, int points) { (*score) += points; }

void jouerAddition(int *score) {
  int a = rand() % 101;
  int b = rand() % 101;
  int resultat, reponse;
  int essais = 0;

  printf("%d + %d = ?\n", a, b);
  do {
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    essais++;

    resultat = a + b;
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

void jouerDivision(int *score) {
  int a = rand() % 101;
  int b = rand() % 10 + 1;
  int resultat, reponse;
  int essais = 0;

  printf("%d / %d = ?\n", a, b);
  do {
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    essais++;

    resultat = a / b;
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

void sauvegarderScore(const char *nom, int score) {
  FILE *fichier = fopen("scores.txt", "a");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return;
  }

  time_t maintenant = time(NULL);
  fprintf(fichier, "%s %d %s", nom, score, ctime(&maintenant));
  fclose(fichier);
}

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

