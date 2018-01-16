#include <stdio.h>
#include <stdlib.h>
#include "ListaD.h"
#include <string.h>

Lista_Dupla* nova_lista() {
	Lista_Dupla *nova_lista = (Lista_Dupla*)malloc(sizeof(Lista_Dupla));
	nova_lista->first = nova_lista->last = NULL;
	nova_lista->tam = 0;
	return nova_lista;
}
Lista_Dupla * insert_end(Lista_Dupla * L, char v[50])
{
	Nodo* novo_elemento = (Nodo*)malloc(sizeof(Nodo));
	strcpy(novo_elemento->info,v);
	L->tam++;
	if (L->last == NULL){
        strcpy(novo_elemento->prox->info,novo_elemento->info);
        strcpy(novo_elemento->ant->info,novo_elemento->prox->info);
        strcpy(L->first->info,novo_elemento->ant->info);
        }
	else
	{
	    strcpy(novo_elemento->ant->info,L->last->info);
	    strcpy(L->last->prox->info,novo_elemento->info);
	    strcpy(novo_elemento->prox->info,L->first->info);
	    strcpy(L->first->ant->info,novo_elemento->info);
	}
	strcpy(L->last->info,novo_elemento->info);
	return L;
}
Nodo* search(Lista_Dupla* L, char v[50]) {
    Nodo* p;
	for (p=L->first;p!=L->first;p=p->prox)
		if (strcmp(p->info,v)==0) return p;
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
	for (p = L->first; p != L->first; p = p->prox)
		printf("%s -> ", p->info);
	printf("%s\n", p->info);
}
