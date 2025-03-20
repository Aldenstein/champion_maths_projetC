#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficherMenu();
void jouerAddition(int *score);
void jouerMultiplication(int *score);
void jouerSoustraction(int *score);
void tablesDeMultiplication(int *score);
void jouerDivision(int *score);
void ajoutScore(int *score);

void afficherMenu() {
  printf("1 : Addition\n");
  printf("2 : Soustraction\n");
  printf("3 : Multiplication\n");
  printf("4 : Tables des multiplications\n");
  printf("5 : Divisions\n");
  printf("0 : Sortir du jeu\n");
}

int main() {
  int choix;
  char nom[50];
  srand(time(NULL));

  printf("Entrez votre nom : ");
  scanf("%s", nom);
  int score = 0;

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
    case 0:
      printf("Merci de votre visite\n");
      break;
    default:
      printf("Choix invalide\n");
    }
    printf("Votre score actuel est : %d\n", score);
  } while (choix != 0);

  return 0;
}

void ajoutScore(int *score) {
    (*score)++;
}

void jouerAddition(int *score) {
  int a = rand() % 101;
  int b = rand() % 101;
  int resultat, reponse;

  printf("%d + %d = ?\n", a, b);
  printf("Entrez le résultat : ");
  scanf("%d", &reponse);

  resultat = a + b;
  if (reponse == resultat) {
    printf("Bravo!\n");
    ajoutScore(score);
  } else {
    printf("Mauvaise réponse. La réponse correcte est %d.\n", resultat);
  }
}

void jouerMultiplication(int *score) {
  int a = rand() % 10 + 1;
  int b = rand() % 10 + 1;
  int resultat, reponse;

  printf("%d * %d = ?\n", a, b);
  printf("Entrez le résultat : ");
  scanf("%d", &reponse);

  resultat = a * b;
  if (reponse == resultat) {
    printf("Bravo!\n");
    ajoutScore(score);
  } else {
    printf("Mauvaise réponse. La réponse correcte est %d.\n", resultat);
  }
}

void jouerSoustraction(int *score) {
  int a = rand() % 101;
  int b = rand() % 101;
  int resultat, reponse;

  if (a < b) {
    int temp = a;
    a = b;
    b = temp;
  }

  printf("%d - %d = ?\n", a, b);
  printf("Entrez le résultat : ");
  scanf("%d", &reponse);

  resultat = a - b;
  if (reponse == resultat) {
    printf("Bravo!\n");
    ajoutScore(score);
  } else {
    printf("Mauvaise réponse. La réponse correcte est %d.\n", resultat);
  }
}

void tablesDeMultiplication(int *score) {
  int table, reponse;
  printf("Choisissez une table (1 à 10) : ");
  scanf("%d", &table);

  for (int i = 1; i <= 10; i++) {
    printf("%d * %d = ?\n", table, i);
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);

    if (reponse == table * i) {
      printf("Bravo!\n");
      ajoutScore(score);
    } else {
      printf("Mauvaise réponse. La réponse correcte est %d.\n", table * i);
    }
  }
}

void jouerDivision(int *score) {
  int a = rand() % 101;
  int b = rand() % 10 + 1;
  int resultat, reponse;

  printf("%d / %d = ?\n", a, b);
  printf("Entrez le résultat : ");
  scanf("%d", &reponse);

  resultat = a / b;
  if (reponse == resultat) {
    printf("Bravo!\n");
    ajoutScore(score);
  } else {
    printf("Mauvaise réponse. La réponse correcte est %d.\n", resultat);
  }
}
