#include <stdio.h>
#define tam 10

typedef struct p {
  int top, layer[tam];
} Pilha;

void push(Pilha *p, int valor);
void pop(Pilha *p);
int top(Pilha p);
void print(Pilha p);

void push(Pilha *p, int valor) {
  if (p->top == tam - 1) printf("Overflow\n");
  else {
    p->top++;
    p->layer[p->top] = valor;
  }
}

void pop(Pilha *p) {
  if (p->top == -1) {
    printf("Underflow\n");
  } else {
    p->layer[p->top] = 0;
    p->top--;
  }
}

int top(Pilha p) {
  return p.layer[p.top];
}

void print(Pilha p) {
  printf("\nPilha:\n");
  while (p.top != -1) {
    printf("%d\n", p.layer[p.top]);
    pop(&p);
  }
}