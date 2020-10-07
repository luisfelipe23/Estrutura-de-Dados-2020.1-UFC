#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

Arvore* create (){
	Arvore* novaArvore = (Arvore*) malloc (sizeof(Arvore));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	if (novaArvore != NULL){	// 1 Complexidade Temporal
		novaArvore->raiz = NULL;	// 1 Complexidade Temporal
	}
	return novaArvore;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(1) = O(c), c constante
// Complexidade Temporal = O(3) = O(c), c constante

int add (Arvore* arvore, int elemento){	// 2 Complexidade Espacial
	No* novo = (No*) malloc (sizeof (No));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	if (novo != NULL){	// Criando um novo nó | 1 Complexidade Temporal
		novo->esq = NULL;	// 1 Complexidade Temporal
		novo->dir = NULL;	// 1 Complexidade Temporal
		novo->info = elemento;	// 1 Complexidade Temporal
	}
	// Se a árvore estiver vazia, o novo elemento será a raiz
	if (arvore->raiz == NULL){	// 1 Complexidade Temporal
		arvore->raiz = novo;	// 1 Complexidade Temporal
	}
	else {
		No* atual = arvore->raiz;	// Variável auxiliar para percorrer a árvore | 1 Complexidade Espacial, 1 Complexidade Temporal

		if (elemento < arvore->raiz->info){	// 1 Complexidade Temporal
			if (arvore->raiz->esq == NULL){	// Caso não exista um elemento à esquerda da raiz | 1 Complexidade Temporal
				arvore->raiz->esq = novo;	// 1 Complexidade Temporal
				return 1;	// 1 Complexidade Temporal
			}
			else {
				atual = atual->esq;	// 1 Complexidade Temporal
			}
		}
		else {
			if (elemento > arvore->raiz->info){	// 1 Complexidade Temporal
				if (arvore->raiz->dir == NULL){	// Caso não exista um elemento à direita da raiz | 1 Complexidade Temporal
					arvore->raiz->dir = novo;	// 1 Complexidade Temporal
					return 1;	// 1 Complexidade Temporal
				}
				else {
					atual = atual->dir;	// 1 Complexidade Temporal
				}
			}
			else {
				return 0;	// 1 Complexidade Temporal
			}
		}
		// Irá buscar o último elemento da árvore
		while (atual->esq != NULL || atual->dir != NULL){	// N Complexidade Temporal
			if (atual->esq != NULL){	// 1 Complexidade Temporal
				atual = atual->esq;	// 1 Complexidade Temporal
			}
			else {
				atual = atual->dir;	// 1 Complexidade Temporal
			}
		}
		// Se o valor atual da árvore for maior que o elemento informado, o novo nó será inserido à esquerda
		if (elemento < atual->info){	// 1 Complexidade Temporal
			atual->esq = novo;	// 1 Complexidade Temporal
			return 1;	// 1 Complexidade Temporal
		}
		// Se o valor atual da árvore for menor que o elemento informado, o novo nó será inserido à direita
		else if (elemento > atual->info){	// 1 Complexidade Temporal
			atual->dir = novo;	// 1 Complexidade Temporal
			return 1;	// 1 Complexidade Temporal
		}
		else {	// Novo elemento tem o mesmo valor do seu antecessor
			return 0;	// 1 Complexidade Temporal
		}
	}
}
// Complexidade Espacial = O(4) = O(c)
// Complexidade Temporal = O(26 + 3*N) = O(26 + N) = O(N)

int find (Arvore* arvore, int elemento){	// 2 Complexidade Espacial
	if (arvore != NULL){	// 1 Complexidade Temporal
		if (arvore->raiz->info == elemento){	// Se o elemento informado está na raiz | 1 Complexidade Temporal
			printf ("Elemento %d encontrado!\n\n", elemento);	// 1 Complexidade Temporal
			return elemento;	// 1 Complexidade Temporal
		}
		else {
			No* atual;	// Variável auxiliar que irá percorrer a árvore | 1 Complexidade Temporal, 1 Complexidade Espacial
			
			// Se o elemento informado for menor que a raiz, o elemento será buscado à esquerda
			if (elemento < arvore->raiz->info){	// 1 Complexidade Temporal
				atual = arvore->raiz->esq;	// 1 Complexidade Temporal
			}
			// Se o elemento informado for maior que a raiz, o elemento será buscado à direita
			else {
				atual = arvore->raiz->dir;	// 1 Complexidade Temporal
			}
			// Procurará o último elemento da árvore
			while (atual->dir != NULL || atual->esq != NULL){	// N Complexidade Temporal
				if (atual->info == elemento){	// 1 Complexidade Temporal
					printf ("Elemento %d encontrado!\n\n", elemento);	// 1 Complexidade Temporal
					return elemento;	// 1 Complexidade Temporal
				}
				else {
					if (atual->esq != NULL){	// 1 Complexidade Temporal
						atual = atual->esq;	// 1 Complexidade Temporal
					}
					else {
						atual = atual->dir;	// 1 Complexidade Temporal
					}
				}
			}
			printf ("Elemento não encontrado!\n\n", elemento);	// 1 Complexidade Temporal
			return NULL;	// 1 Complexidade Temporal
		}
	}
	printf ("Árvore vazia!\n\n", elemento);	// 1 Complexidade Temporal
	return NULL;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3) = O(c), c constante
// Complexidade Temporal = O(12 + 6*N) = O(12 + N) = O(N)

void printAllPos_Aux (No* raiz){	// 1 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Temporal
		printAllPos_Aux (raiz->esq);	// N Complexidade Temporal
		printAllPos_Aux (raiz->dir);	// M Complexidade Temporal
		printf ("%d  ->  ", raiz->info);	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(2 + N + M) = O(N + M)

void printAllPos (Arvore* arvore){	// 1 Complexidade Espacial
	printAllPos_Aux (arvore->raiz);	// N + M Complexidade Temporal
	printf ("NULL\n\n");	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c)
// Complexidade Temporal = O(N+M)

void printAllPre_Aux (No* raiz){	// 1 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Espacial
		printf ("%d  ->  ", raiz->info);	// 1 Complexidade Temporal
		printAllPre_Aux (raiz->esq);	// N Complexidade Temporal
		printAllPre_Aux (raiz->dir);	// M Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(2 + N + M) = O(N+M)

void printAllPre (Arvore* arvore){	// 1 Complexidade Espacial
	printAllPre_Aux (arvore->raiz);	// N + M Complexidade Temporal
	printf ("NULL\n\n");	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(N+M)

void printAllIn_Aux (No* raiz){	// 1 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Temporal
		printAllIn_Aux (raiz->esq);	// N Complexidade Temporal
		printf ("%d  ->  ", raiz->info);	// 1 Complexidade Temporal
		printAllIn_Aux (raiz->dir);	// M Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(N+M)

void printAllIn (Arvore* arvore){	// 1 Complexidade Espacial
	printAllIn_Aux (arvore->raiz);	// N + M Complexidade Temporal
	printf ("NULL\n\n");	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c)
// Complexidade Temporal = O(N+M)

void clearAux (No* raiz){	// 1 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Temporal
		clearAux (raiz->esq);	// N Complexidade Temporal
		clearAux (raiz->dir);	// M Complexidade Temporal
		free (raiz);	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(N+M)

void clear (Arvore* arvore){	// 1 Complexidade Espacial
	clearAux (arvore->raiz);	// N + M Complexidade Temporal
	printf ("Árvore esvaziada!\n\n");	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c)
// Complexidade Temporal = O(N+M)
