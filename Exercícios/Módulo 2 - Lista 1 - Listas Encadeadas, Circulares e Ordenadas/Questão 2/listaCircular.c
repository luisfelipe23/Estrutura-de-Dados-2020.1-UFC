#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

Lista* create(){	
	Lista* novaLista = (Lista*) malloc (sizeof (Lista));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	
	if (novaLista != NULL){	// 1 Complexidade Temporal
		novaLista->inicio = novaLista->fim = NULL;	// 2 Complexidade Temporal
		novaLista->tamanho = 0;	// 1 Complexidade Temporal
	}
	return novaLista;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(1), Complexidade Temporal = O(6) = O(c), c constante

int add(Lista* lista, int valor){	// 2 Complexidade Espacial
	No* novo = (No*) malloc (sizeof (No));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	
	if (novo != NULL){	// 1 Complexidade Temporal
		novo->info = valor;	// 1 Complexidade Temporal
		
		if (lista->inicio == NULL){	// 1 Complexidade Temporal
			novo->prox = novo;	// 1 Complexidade Temporal
			novo->ant = novo;	// 1 Complexidade Temporal
			lista->inicio = lista->fim = novo;	// 2 Complexidade Temporal
		}
		else {
			novo->prox = lista->inicio;	// 1 Complexidade Temporal
			novo->ant = lista->fim;	// 1 Complexidade Temporal
			lista->fim->prox = novo;	// 1 Complexidade Temporal
			lista->inicio->ant = novo;	// 1 Complexidade Temporal
		}
		lista->fim = novo;	// 1 Complexidade Temporal
		lista->tamanho++;	// 1 Complexidade Temporal
		return 1;	// 1 Complexidade Temporal
	}
	return 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3)
// Complexidade Temporal = O(16) = O(c), c constante

int remover(Lista* lista, int elemento){	// 2 Complexidade Espacial
	if (!isEmpty(lista)){	// 1 Complexidade Temporal
		No* aux = lista->inicio;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		No* anterior;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		while (aux->prox != lista->inicio && aux->info != elemento){	// N Complexidade Temporal
			anterior = aux;	// 1 Complexidade Temporal
			aux = aux->prox;	// 1 Complexidade Temporal
		}
		if (aux->info == elemento){	// 1 Complexidade Temporal
			if (aux->prox == lista->inicio){	// O elemento a ser removido é o último. // 1 Complexidade Temporal
				anterior->prox = lista->inicio;	// 1 Complexidade Temporal
				lista->inicio->ant = anterior;	// 1 Complexidade Temporal
				lista->fim = anterior;	// 1 Complexidade Temporal
			}
			else {
				if (aux == lista->inicio){	// O elemento a ser removido é o primeiro.	// 1 Complexidade Temporal
					aux->prox->ant = lista->fim;	// 1 Complexidade Temporal
					lista->fim->prox = aux->prox;	// 1 Complexidade Temporal
					lista->inicio = aux->prox;	// 1 Complexidade Temporal
				}
				else {	// Elemento está no meio da lista
					anterior->prox = aux->prox;	// 1 Complexidade Temporal
					aux->prox->ant = anterior;	// 1 Complexidade Temporal
				}
			}
			freeNo(aux);	// 1 Complexidade Temporal
			lista->tamanho--;	// 1 Complexidade Temporal
		}
		return 0;	// 1 Complexidade Temporal
	}
	return 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(4), Complexidade Temporal = O(N)

int size (Lista* lista){	// 1 Complexidade Temporal
	return lista->tamanho;	// 1 Complexidade Espacial
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

int find (Lista* lista, int valor){	// 2 Complexidade Espacial
	if (!isEmpty(lista)){	// 1 Complexidade Temporal
		if (lista->inicio->info == valor){	// Caso o elemento seja o primeiro.	// 1 Complexidade Temporal
			return 0;	// 1 Complexidade Temporal
		}
		else {
			No* aux;	// 1 Complexidade Espacial, 1 Complexidade Temporal
			int pos = 1; // 1 Complexidade Espacial, 1 Complexidade Temporal
			
			for (aux = lista->inicio->prox; aux != lista->inicio; aux = aux->prox){	// N Complexidade Temporal
				if (aux->info == valor){	// 1 Complexidade Temporal
					return pos;	// 1 Complexidade Temporal
				}
				else {
					pos++;	// 1 Complexidade Temporal
				}
			}
			return -1;	// 1 Complexidade Temporal
		}
	}
	return -1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), c constante, Complexidade Temporal = O(N)

int isEmpty(Lista* lista){	// 1 Complexidade Espacial
	return lista->tamanho <= 0;	// 1 Complexidade Temporal
}
// Complexidade Temporal = Complexidade Espacial = O(c), com c sendo uma constante

void clear(Lista* lista){	// 1 Complexidade Espacial
	if (!isEmpty(lista)){	// 1 Complexidade Temporal
		No* aux = lista->inicio;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		do{	// N Complexidade Temporal
			No* aux2 = aux->prox;	// 1 Complexidade Espacial, 1 Complexidade Temporal
			freeNo(aux);	// 1 Complexidade Temporal
			aux = aux2;	// 1 Complexidade Temporal
		} while (aux != lista->inicio);
		lista->inicio = lista->fim = NULL;	// 1 Complexidade Temporal
		lista->tamanho = 0;	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(2 + N) = O(N)
// Complexidade Temporal = O(4 + 3 * N) = O(4 + N) = O(N)

void imprimirLista(Lista* lista){	// 1 Complexidade Espacial
	if (isEmpty(lista)){	// 1 Complexidade Temporal
		printf ("Lista vazia!\n\n");	// 1 Complexidade Temporal
	}
	else {
		No* aux = lista->inicio;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		do {	// N Complexidade Temporal
			printNo(aux);	// 1 Complexidade Temporal
			aux = aux->prox;	// 1 Complexidade Temporal
		} while (aux != lista->inicio);
		printf ("INICIO\nTamanho da lista: %d\n\n", size(lista));	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(2)
// Complexidade Temporal = O(N)
