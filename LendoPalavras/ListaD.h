#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int info;
	char string[50];
	struct nodo *ant;
	struct nodo *prox;
} Nodo;

typedef struct lista_dupla {
	Nodo *first;
	Nodo *last;
	int tam;
} Lista_Dupla;
Lista_Dupla* nova_lista();
Lista_Dupla * insert_end(Lista_Dupla * L, int v,char s[50]);
Nodo* search(Lista_Dupla* L, int v);
void Liberando_lista(Lista_Dupla* L);
void print_da_lista(Lista_Dupla* L);
