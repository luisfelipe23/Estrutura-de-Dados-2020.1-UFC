#include <stdio.h>
#include <stdlib.h>
#define LADO_ESQ 0
#define LADO_DIR 1
#include "arvore.h"

Arvore* create (){
	Arvore* novaArvore = (Arvore*) malloc (sizeof (Arvore));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	if (novaArvore != NULL){	// 1 Complexidade Temporal
		novaArvore->raiz = NULL;	// 1 Complexidade Temporal
	}
	return novaArvore;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(1) = O(c), Complexidade Temporal = O(3) = O(c), c constante

No* createRoot (Arvore* arvore, char elemento){	// 2 Complexidade Espacial
	arvore->raiz = (No*) malloc (sizeof (No));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	if (arvore->raiz != NULL){	// 1 Complexidade Temporal
		arvore->raiz->dir = NULL;	// 1 Complexidade Temporal
		arvore->raiz->esq = NULL;	// 1 Complexidade Temporal
		arvore->raiz->carac = elemento;	// 1 Complexidade Temporal
		arvore->raiz->cont = 1;	// 1 Complexidade Temporal
	}
	return arvore->raiz;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3) = O(c), Complexidade Temporal = O(7) = O(c), c constante

No* inserirFilho (int lado, No* no, char elemento){	// 3 Complexidade Espacial
	No* novo = (No*) malloc (sizeof (No));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	
	if (novo != NULL){	// 1 Complexidade Temporal
		novo->dir = NULL;	// 1 Complexidade Temporal
		novo->esq = NULL;	// 1 Complexidade Temporal
		novo->carac = elemento;	// 1 Complexidade Temporal
		
		if (lado == LADO_ESQ){	// 1 Complexidade Temporal
			no->esq = novo;	// 1 Complexidade Temporal
		}
		else {
			no->dir = novo;	// 1 Complexidade Temporal
		}
		no->cont++;	// 1 Complexidade Temporal
	}
	return novo;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(4) = O(c), Complexidade Temporal = O(10) = O(c), c constante

void sizeAux (No* raiz, int *cont){	// 2 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Temporal
		(*cont)++;	// 1 Complexidade Temporal
		sizeAux(raiz->esq, cont);	// N Complexidade Temporal
		sizeAux(raiz->dir, cont);	// M Complexidade Temporal
	}
	return;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(n+m)

int size (Arvore* arvore){// 1 Complexidade Espacial
	int cont = 0;	// 1 Complexidade Temporal
	sizeAux(arvore->raiz, &cont);	// N+M Complexidade Temporal
	return cont;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), c constante, Complexidade Temporal = O(n+m)

void findAux (No* raiz, int *d, char elemento, int *achou){	// 4 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Temporal
		(*d)++;	// 1 Complexidade Temporal
		if (raiz->carac == elemento){	// 1 Complexidade Temporal
			*achou = 1;	// 1 Complexidade Temporal
			return;	// 1 Complexidade Temporal
		}
		findAux(raiz->esq, d, elemento, achou);	// N Complexidade Temporal
		if (!*achou){	// 1 Complexidade Temporal
			findAux(raiz->dir, d, elemento, achou);	// M Complexidade Temporal
			if (!*achou){	// 1 Complexidade Temporal
				(*d)--;	// 1 Complexidade Temporal
			}
		}
	}
	return;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(4), Complexidade Temporal = O(N+M)

int find (Arvore* arvore, char elemento){	// 2 Complexidade Espacial
	int d = 0;	// 1 Complexidade Espacial, 1 Complexidade Temporal
	int achou = 0;	// 1 Complexidade Espacial, 1 Complexidade Temporal
	findAux (arvore->raiz, &d, elemento, &achou);	// N+M Complexidade Temporal
	
	if (achou){	// 1 Complexidade Temporal
		return d - 1;	// 1 Complexidade Temporal
	}
	else {
		return -1;	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(4) = O(c), c constante
// Complexidade Temporal = O(N+M)

int isEmpty(Arvore* arvore){	// 1 Complexidade Espacial
	return arvore->raiz->cont < 1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(N+M)

void printAllPre_Aux (No* raiz){	// 1 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Espacial
		printf ("%c -> ", raiz->carac);	// 1 Complexidade Espacial
		printAllPre_Aux(raiz->esq);	// N Complexidade Espacial
		printAllPre_Aux(raiz->dir);	// M Complexidade Espacial
	}
}
// Complexidade Espacial = O(c)
// Complexidade Temporal = O(N+M)

void printAllPre (Arvore* arvore){	// 1 Complexidade Espacial
	printAllPre_Aux (arvore->raiz);	// N + M Complexidade Espacial
}
// Complexidade Espacial = O(c), Complexidade Temporal = O(N+M)

void printAllIn_Aux (No* raiz){	// 1 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Temporal
		printAllIn_Aux (raiz->esq);	// N Complexidade Temporal
		printf("%c -> ", raiz->carac);	// 1 Complexidade Temporal
		printAllIn_Aux (raiz->dir);	// M Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), Complexidade Temporal = O(N+M)

void printAllIn (Arvore* arvore){	// 1 Complexidade Espacial
	printAllIn_Aux (arvore->raiz);	// N+M Complexidade Temporal
}
// Complexidade Espacial = O(c), Complexidade Temporal = O(N+M)

void printAllPost_Aux (No* raiz){	// 1 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Temporal
		printAllPost_Aux (raiz->esq);	// N Complexidade Temporal
		printAllPost_Aux (raiz->dir);	// M Complexidade Temporal
		printf ("%c -> ", raiz->carac);	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(N+M)

void printAllPost (Arvore* arvore){	// 1 Complexidade Espacial
	printAllPost_Aux (arvore->raiz);	// N+M Complexidade Temporal
}
// Complexidade Espacial = O(c), Complexidade Temporal = O(N+M)

void clear_aux (No* raiz){	// 1 Complexidade Espacial
	if (raiz != NULL){	// 1 Complexidade Temporal
		clear_aux (raiz->esq);	// N Complexidade Temporal
		clear_aux (raiz->dir);	// M Complexidade Temporal
		free(raiz);	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), Complexidade Temporal = O(N+M)

void clear (Arvore* arvore){	// 1 Complexidade Espacial
	clear_aux (arvore->raiz);	// N+M Complexidade Temporal
	arvore->raiz->cont = 0;	// 1 Complexidade Temporal
	printf ("Arvore esvaziada!");	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(N+M)
