#include "ListaD.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista_Dupla* nova_lista() {
	Lista_Dupla *nova_lista = (Lista_Dupla*)malloc(sizeof(Lista_Dupla));
	nova_lista->first = nova_lista->last = NULL;
	nova_lista->tam = 0;
	return nova_lista;
}
Lista_Dupla * insert_end(Lista_Dupla * L, int v,char s[50])
{
	Nodo* novo_elemento = (Nodo*)malloc(sizeof(Nodo));
	novo_elemento->info = v;
	strcpy(novo_elemento->string,s);
	L->tam++;
	if (L->last == NULL)
		L->first = novo_elemento->ant = novo_elemento->prox = novo_elemento;
	else
	{
		novo_elemento->ant = L->last;
		L->last->prox = novo_elemento;
		novo_elemento->prox = L->first;
		L->first->ant = novo_elemento;
	}
	L->last = novo_elemento;
	return L;
}
Nodo* search(Lista_Dupla* L, int v) {
    Nodo* p;
    int i;
	for (p = L->first, i= 0; i < L->tam; p = p->prox)
		if (p->info == v)
			return p;
	return NULL;
}
void Liberando_lista(Lista_Dupla* L) {
	Nodo* r = NULL;
	Nodo* p = L->first;
	int i;
	for (i = 0; i < L->tam; i++) {
		r = p;
		p = p->prox;
		free(r);
	}
	free(L);
}
void print_da_lista(Lista_Dupla* L) {
	Nodo* p;
	int i;
	for (p = L->first,i = 0; i< L->tam;i++, p = p->prox)
		printf("%s %d\n", p->string, p->info);
}
