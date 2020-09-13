#include "listaOrdenada.h"
#include <stdio.h>
#include <stdlib.h>

Lista* create(int n){	// 1 Complexidade Espacial
	Lista* novaLista = (Lista*) malloc (sizeof (Lista));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	novaLista->tamanho = n;	// 1 Complexidade Temporal
	novaLista->cont = 0;	// 1 Complexidade Temporal
	novaLista->info = (int*) malloc (n * sizeof(int));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	return novaLista;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3)
// Complexidade Temporal = O(c), c constante

int add(Lista* lista, int elemento){	// 2 Complexidade Espacial
	if (lista != NULL && lista->cont < lista->tamanho){	// 1 Complexidade Temporal
		int i, posicao = lista->cont;	// 2 Complexidade Espacial, 2 Complexidade Temporal
		
		for (i = 0; i < lista->cont; i++){	// N Complexidade Temporal
			if (elemento < lista->info[i]){	// 1 Complexidade Temporal
				posicao = i;	// 1 Complexidade Temporal
				break;	// 1 Complexidade Temporal
			}
		}
		if (posicao != lista->cont){	// 1 Complexidade Temporal
			for (i = lista->cont; i > posicao; i--){	// N Complexidade Temporal
				swap(lista->info, i-1, i);	// 1 Complexidade Temporal
			}
		}
		lista->info[posicao] = elemento;	// 1 Complexidade Temporal
		lista->cont++;	// 1 Complexidade Temporal
		return 1;	// 1 Complexidade Temporal
	}
	return 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(2N) = O(N)

int remover (Lista* lista, int valor){	// 2 Complexidade Espacial
	if (lista != NULL && lista->cont > 0){	// 1 Complexidade Temporal
		int* vetAux = (int*) malloc (lista->tamanho * sizeof(int));	// 1 Complexidade Espacial, 1 Complexidade Temporal
		int i, k = 0;	// 2 Complexidade Espacial, 2 Complexidade Temporal
		for (i = 0; i < lista->cont; i++){	// N Complexidade Temporal
			if (lista->info[i] != valor){	// 1 Complexidade Temporal
				vetAux[k] = lista->info[i];	// 1 Complexidade Temporal
				k++;	// 1 Complexidade Temporal
			}
		}
		lista->cont--;	// 1 Complexidade Temporal
		free(lista->info); 	// 1 Complexidade Temporal
		lista->info = vetAux;	// 1 Complexidade Temporal
		return 1;	// 1 Complexidade Temporal
	}
	return 0; 	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(5) = O(c), Complexidade Temporal = O(N)

int size(Lista* lista){	// 1 Complexidade Espacial
	return lista->cont;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c)

int linearSearch(Lista* lista, int valor){	// 2 Complexidade Espacial
	if (!isEmpty(lista)){	// 1 Complexidade Temporal
		int i;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		for (i = 0; i < lista->cont; i++){	// N Complexidade Temporal
			if (lista->info[i] == valor){	// 1 Complexidade Temporal
				return i;	// 1 Complexidade Temporal
			}
		}
		return -1;	// 1 Complexidade Temporal
	}
	return -1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3), Complexidade Temporal = O(N)

int binarySearch(Lista* lista, int valor){	// 2 Complexidade Espacial
	if (!isEmpty(lista)){	// 1 Complexidade Temporal
		int esq = 0;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		int dir = lista->cont;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		while (esq <= dir){ // Log2n Complexidade Temporal 
			int meio = (esq + dir) / 2;	// 1 Complexidade Espacial, 1 Complexidade Temporal
			
			if (lista->info[meio] == valor){	// 1 Complexidade Temporal
				return meio;	// 1 Complexidade Temporal
			}
			else {	
				if (lista->info[meio] > valor){	// 1 Complexidade Temporal
					dir = meio - 1;	// 1 Complexidade Temporal
				}
				else {
					esq = meio + 1;	// 1 Complexidade Temporal
				}
			}
		}
		return -1;	// 1 Complexidade Temporal
	}
	return -1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(Log n)
// Complexidade Temporal = O(log n)

int isFull(Lista* lista){	// 1 Complexidade Espacial
	return lista->cont == lista->tamanho;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

int isEmpty(Lista* lista){	// 1 Complexidade Espacial
	return lista->cont == 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), Complexidade Temporal = O(c)

void clear(Lista* lista){	// 1 Complexidade Espacial
	free(lista->info);	// 1 Complexidade Temporal
	lista->cont = 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(1), Complexidade Temporal = O(2) = O(c), c constante

void swap (int* v, int i, int j){	// 3 Complexidade Espacial
	int aux = v[i];	// 1 Complexidade Espacial, 1 Complexidade Temporal
	v[j] = v[i];	// 1 Complexidade Temporal
	v[i] = aux;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(4), Complexidade Temporal = O(3) = O(c), c = constante

void imprimir(Lista* lista){	// 1 Complexidade Espacial
	if (!isEmpty(lista)){	// 1 Complexidade Temporal
		int i = 0;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		while (i != lista->cont){	// N Complexidade Temporal
			printf("%d  ->  ", lista->info[i]);	// 1 Complexidade Temporal
			i++;	// 1 Complexidade Temporal
		}
	}
	printf("NULL\n\n");	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(3 + 2 * N) = O(3 + N) = O(N)
