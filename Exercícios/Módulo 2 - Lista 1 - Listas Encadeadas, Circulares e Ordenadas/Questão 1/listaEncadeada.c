#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

Lista* create(){
	Lista* novaLista = (Lista*) malloc (sizeof (Lista));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	
	if (novaLista != NULL){	// 1 Complexidade Temporal
		novaLista->inicio = novaLista->fim = NULL;	// 2 Complexidade Temporal
		novaLista->tamanho = 0;	// 1 Complexidade Temporal
	}
	return novaLista;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(1), Complexidade Temporal = O(c), c constante

int add (Lista* lista, int elemento){	// 2 Complexidade Espacial
	No* novo = (No*) malloc(sizeof(No));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	
	if (novo != NULL){	// 1 Complexidade Temporal
		novo->info = elemento;	// 1 Complexidade Temporal
		novo->prox = NULL;	// 1 Complexidade Temporal
		
		if (lista->inicio == NULL){	// 1 Complexidade Temporal
			lista->inicio = novo;	// 1 Complexidade Temporal
		}
		else {
			lista->fim->prox = novo;	// 1 Complexidade Temporal
		}
		lista->fim = novo;	// 1 Complexidade Temporal
		lista->tamanho++;	// 1 Complexidade Temporal
		return 1;	// 1 Complexidade Temporal
	}
	return 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3) = O(c), c constante
// Complexidade Temporal = O(11) = O(c), c constante

int pop(Lista* lista, int elemento){	// 2 Complexidade Espacial
	if (!isEmpty(lista)){	// 1 Complexidade Temporal
		No* aux = lista->inicio;	// 1 Complexidade Espacial,1 Complexidade Temporal
		No* ant;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		while (aux != NULL && aux->info != elemento){	// N Complexidade Temporal
			ant = aux;	// 1 Complexidade Temporal
			aux = aux->prox;	// 1 Complexidade Temporal
		}
		
		if (aux != NULL){	// 1 Complexidade Temporal
			if (aux == lista->inicio){	// 1 Complexidade Temporal
				lista->inicio = aux->prox;	// 1 Complexidade Temporal
			}
			else {
				ant->prox = aux->prox;	// 1 Complexidade Temporal
			}
			if (aux == lista->fim){	// 1 Complexidade Temporal
				lista->fim = ant;	// 1 Complexidade Temporal
			}
			lista->tamanho--;	// 1 Complexidade Temporal
			freeNo(aux);	// 1 Complexidade Temporal
			return 1;	// 1 Complexidade Temporal
		}
		return 0;	// 1 Complexidade Temporal
	}
	return 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(4)
// Complexidade Temporal = O(14 + 2*N) = O(14+N) = O(N)

int size(Lista* lista){	// 1 Complexidade Espacial
	return lista->tamanho;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

int find (Lista* lista, int elemento){	// 2 Complexidade Espacial
	if (!isEmpty(lista)){	// 1 Complexidade Temporal
		No* aux;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		int pos = 0;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		for (aux = lista->inicio; aux != NULL; aux = aux->prox){	// N Complexidade Temporal
			if (aux->info == elemento){	// 1 Complexidade Temporal
				return pos;	// 1 Complexidade Temporal
			}
			pos++;	// 1 Complexidade Temporal
		}
		return -1;	// 1 Complexidade Temporal
	}
	return -1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(4), Complexidade Temporal = O(N)

void clear(Lista* lista){	// 1 Complexidade Espacial
	if (!isEmpty(lista)){	// 1 Complexidade Temporal
		No* aux = lista->inicio;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		while (aux != NULL){	// N Complexidade Temporal
			No* aux2 = aux->prox;	// 1 Complexidade Temporal, 1 Complexidade Espacial
			freeNo(aux);	// 1 Complexidade Temporal
			aux = aux2;	// 1 Complexidade Temporal
		}
		lista->tamanho = 0;	// 1 Complexidade Temporal
		lista->inicio = lista->fim = NULL;	// 2 Complexidade Temporal
	}
}
// Complexidade Espacial = O(2 + N) = O(N)
// Complexidade Temporal = O(5 + 3*N) = O(5 + N) = O(N)

int isEmpty(Lista* lista){	// 1 Complexidade Espacial
	return lista->tamanho == 0;	// 1 Complexidade Temporal
}
// Complexidade Temporal = Complexidade Espacial = O(c), c constante

void imprimirLista (Lista* lista){	// 1 Complexidade Espacial
	if (isEmpty(lista)){	// 1 Complexidade Temporal
		printf ("Lista vazia!\n\n");	// 1 Complexidade Temporal
	}
	else {
		No* aux = lista->inicio;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		while (aux != NULL){	// N Complexidade Temporal
			imprimirNo (aux);	// 1 Complexidade Temporal
			aux = aux->prox;	// 1 Complexidade Temporal
		}
		printf("NULL\nTamanho: %d\n\n", size(lista));	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(N)
