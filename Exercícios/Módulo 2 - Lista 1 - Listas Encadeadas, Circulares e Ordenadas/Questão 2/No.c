#include <stdio.h>
#include <stdlib.h>
#include "No.h"

No* createNo(int valor, No* proximo, No* anterior){	// 3 Complexidade Espacial
	No* novoNo = (No*) malloc (sizeof (No));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	
	novoNo->info = valor;	// 1 Complexidade Temporal
	novoNo->prox = proximo;	// 1 Complexidade Temporal
	novoNo->ant = anterior;	// 1 Complexidade Temporal
	
	return novoNo;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(4), Complexidade Temporal = O(c), c constante

void printNo(No* no){	// 1 Complexidade Espacial
	if (no != NULL){	// 1 Complexidade Temporal
		printf ("Valor: %d  ->  Proximo: %d  ->  Anterior: %d\n", no->info, no->prox->info, no->ant->info);	// 1 Complexidade Temporal
	}
	else {
		printf("NULL\n\n");	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(1), Complexidade Temporal = O(c), com c = constante

void freeNo (No* no){	// 1 Complexidade Espacial
	free(no);	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante
