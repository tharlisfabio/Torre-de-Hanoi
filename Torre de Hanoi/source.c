#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include "pilha.h"
#define tam 10
#define file "log.txt"

Pilha tower1, tower2, tower3;
int quantDiscos = 3;

void menu();
void startGame();
void configureGame();
void rules();
void printTowers(int movesUsed, int minMoves);
void moveDisk(int towerFrom, int towerTo);
void endGame(int movesUsed);
void setTower(Pilha t);

int main() {
  setlocale(LC_ALL, "");
  printf("<<== = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = = = = ==>>\n");
  printf("  || |----------|  |----------|  |----------|  |----------|  |----------| ||\n");
  printf("  || |___    ___|  |          |  |    __    |  |    __    |  |    ______| ||\n");
  printf("  ||     |  |      |   |--|   |  |   |__|   |  |   |__|   |  |   |______  ||\n");
  printf("  ||     |  |      |   |  |   |  |   __   __|  |   __   __|  |          | ||\n");
  printf("  ||     |  |      |   |--|   |  |   | \\  \\    |   | \\  \\    |   |------  ||\n");
  printf("  ||     |  |      |          |  |   |  \\  \\   |   |  \\  \\   |   |------| ||\n");
  printf("  ||     |__|      |__________|  |___|   \\__|  |___|   \\__|  |__________| ||\n");
  printf("  ||                                                                      ||\n");
  printf("  ||                      |-------\\     |----------|                      ||\n");
  printf("  ||                      |    __  \\    |    ______|                      ||\n");
  printf("  ||                      |   |  \\  \\   |   |______                       ||\n");
  printf("  ||                      |   |  /   |  |          |                      ||\n");
  printf("  ||                      |   |_/   /   |   |------                       ||\n");
  printf("  ||                      |        /    |   |------|                      ||\n");
  printf("  ||                      |_______/     |__________|                      ||\n");
  printf("  ||                                                                      ||\n");
  printf("  ||   |---|  |---|  |----------|  |-----\\   |---|  |----------|  |--|    ||\n");
  printf("  ||   |   |  |   |  |    __    |  |      \\  |   |  |          |  |  |    ||\n");
  printf("  ||   |   |--|   |  |   |__|   |  |   |\\  \\ |   |  |   |--|   |  |  |    ||\n");
  printf("  ||   |          |  |          |  |   | \\  \\|   |  |   |  |   |  |  |    ||\n");
  printf("  ||   |   |--|   |  |   ____   |  |   |  \\      |  |   |--|   |  |  |    ||\n");
  printf("  ||   |   |  |   |  |  |    |  |  |   |   \\     |  |          |  |  |    ||\n");
  printf("  ||   |___|  |___|  |__|    |__|  |___|    \\____|  |__________|  |__|    ||\n");
  printf("  ||                                                                      ||\n");
  printf("<<== = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = = = = ==>>\n");
  printf("Pressione enter para iniciar!\n");
  system("read -p '' var || pause");
  menu();
}

void menu() {
  int option = 0;
  while (option <= 0 || option > 4) {
    system("cls || clear");
    printf("<<== = = = = = = = = = = ==>>\n");
    printf("  || 1- Iniciar jogo     ||\n");
    printf("  || 2- Configurações    ||\n");
    printf("  || 3- Como jogar       ||\n");
    printf("  || 4- Sair             ||\n");
    printf("<<== = = = = = = = = = = ==>>\n");
    printf("Opção: ");
    scanf("%d", &option);
  }
  switch (option) {
    case 1:
    tower1.top = -1;
    tower2.top = -1;
    tower3.top = -1;
    startGame();
    break;
    case 2:
    configureGame();
    break;
    case 3:
    rules();
    break;
    case 4:
    exit(0);
    break;
    default:
    printf("Opção inválida!\n");
    break;
  }
}

void setTower(Pilha t) {
  for (int i = 0; i < quantDiscos; i++) {
    pop(&t);
  }
}

void startGame() {
  int result = 1, minMoves, win = 0;
  for(int i = 0; i < quantDiscos; i++) {
      result *= 2;
  }
  minMoves = result - 1;
  
  for (int i = quantDiscos; i > 0; i--) {
    push(&tower1, i);
  }
  int towerFrom, towerTo, countMoves = 0;
  while (win == 0) {
    system("cls || clear");
    printTowers(countMoves, minMoves);
    printf("\nInforme as torres que deseja fazer a jogada: (ex: 1 3 - torre 1 para a torre 3)\nR: ");
    scanf("%d %d", &towerFrom, &towerTo);
    countMoves++;
    moveDisk(towerFrom, towerTo);
    if (tower1.top == -1 && tower2.top == -1) {
      win = 1;
      endGame(countMoves);
    }
  }
}
//ENTENDI
void moveDisk(int towerFrom, int towerTo) {
  if (towerTo == 1) {
    if (towerFrom == 1) {
      printf("Jogada incoerente!");
    } else if (towerFrom == 2) {
      push(&tower1, top(tower2));
      pop(&tower2);
    } else if (towerFrom == 3) {
      push(&tower1, top(tower3));
      pop(&tower3);
    } else {
      printf("Torre inválida!");
    }
  } else if (towerTo == 2) {
    if (towerFrom == 1) {
      push(&tower2, top(tower1));
      pop(&tower1);
    } else if (towerFrom == 2) {
      printf("Jogada incoerente!");
    } else if (towerFrom == 3) {
      push(&tower2, top(tower3));
      pop(&tower3);
    } else {
      printf("Torre inválida!");
    }
  } else if (towerTo == 3) {
    if (towerFrom == 1) {
      push(&tower3, top(tower1));
      pop(&tower1);
    } else if (towerFrom == 2) {
      push(&tower3, top(tower2));
      pop(&tower2);
    } else if (towerFrom == 3) {
      printf("Jogada incoerente!");
    } else {
      printf("Torre inválida!");
    }
  } else {
    printf("Torre inválida!");
  }
}
//ENTENDI
void configureGame() {
  int aux = quantDiscos;
  system("cls || clear");
  printf("<<== = = = = = = = = = = = = = = ==>>\n");
  printf("  Quantidade atual de discos: %d\n", quantDiscos);
  printf("<<== = = = = = = = = = = = = = = ==>>\n");
  printf("Informe a quantidade de discos que deseja: (digite 0 para voltar)\nR: ");
  scanf("%d", &quantDiscos);
  if (quantDiscos == 0) quantDiscos = aux;
  menu();
}
//ENTENDI
void rules() {
  system("cls || clear");
}
//ENTENDI
void printTowers(int movesUsed, int minMoves) {
  for (int i = quantDiscos - 1; i >= 0; i--) {
    printf("   %d   %d   %d\n", tower1.layer[i], tower2.layer[i], tower3.layer[i]);
  }
  printf("===============\n");
  printf("\n %d/%d\n", movesUsed, minMoves);
}
//ENTENDI
void endGame(int movesUsed) {
  system("cls || clear");
  printf("Parabéns, você completou o jogo!\nJogadas utilizadas: %d\n", movesUsed);
  printf("\nAperte enter para retornar ao menu!\n");
  system("pause || read -p '' var");
  FILE *arquivo;
  arquivo = fopen(file, "w");
  fprintf(arquivo, "%s", "");
  fclose(arquivo);
  arquivo = fopen(file, "w");
  fprintf(arquivo, "Recorde: %d\n", movesUsed);
  fclose(arquivo);
  menu();
}