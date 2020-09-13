#include <stdio.h>
#include <stdlib.h>
#include "No.h"

No* createNo (int valor, No* proximo){	// 2 Complexidade Espacial
	No* novoNo = (No*) malloc (sizeof(No));   // 1 Complexidade Espacial, 1 Complexidade Temporal
	novoNo->info = valor;	// 1 Complexidade Temporal
	novoNo->prox = proximo;	// 1 Complexidade Temporal
	return novoNo;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), com c constante e igual a 3
// Complexidade Temporal = O(c), com c constante e igual a 4

void freeNo(No* no){	// 1 Complexidade Espacial
	free(no);	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(1) = O(c)
// Complexidade Temporal = O(1) = O(c)

void imprimirNo (No* no){	// 1 Complexidade Espacial
	if (no != NULL){	// 1 Complexidade Temporal
		printf ("%d -> ", no->info);	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(1), Complexidade Temporal = O(c), c constante
