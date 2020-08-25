#include <stdio.h>
#include <stdlib.h>

struct fila {
	int tamanho;
	int cont;
	int* info;
};
typedef struct fila Fila;

Fila* create (int n){  // 1 Complexidade Espacial
	Fila* novaFila = (Fila*) malloc (sizeof (Fila));   // 1 Complexidade Espacial, 1 Complexidade Temporal
	
	if (novaFila == NULL){  // 1 Complexidade Temporal
		return NULL;	// 1 Complexidade Temporal
	}
	else {
		novaFila->info = (int*) malloc (n * sizeof (int));	// 1 Complexidade Espacial, 1 Complexidade Temporal
		novaFila->tamanho = n;  // 1 Complexidade Temporal
		return novaFila;   // 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), com c constante igual a 3
// Complexidade Temporal = O(c), com c constante e igual a 6

int add (Fila* fila, int elemento){ // 2 Complexidade Espacial
	if (fila != NULL && fila->cont < fila->tamanho){  // 1 Complexidade Temporal
		fila->info[fila->cont] = elemento;  // 1 Complexidade Temporal
		fila->cont++;  // 1 Complexidade Temporal
		return 1;  // 1 Complexidade Temporal
	}
	else 
		return 0;  // 1 Complexidade Temporal
}
// Complexidade Espacial = O(c), com c = 2
// Complexidade Temporal = O(c), com c = 5

int isEmpty (Fila* fila){	// 1 Complexidade Espacial
	return fila == NULL || fila->cont == 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(1)
// Complexidade Temporal = O(1)

int pop (Fila* fila){  // 1 Complexidade Espacial
	if (fila != NULL && fila->cont > 0){  // 1 Complexidade Temporal
		int elemento = fila->info[fila->cont-1];	// 1 Complexidade Espacial, 1 Complexidade Temporal
		int i, k = 0;	// 2 Complexidade Temporal, 2 Complexidade Temporal
		int* vetorAux = (int*) malloc (fila->tamanho * sizeof(int));	// 1 Complexidade Espacial, 1 Complexidade Temporal
		for (i = 1; i < fila->tamanho; i++){  // N complexidade Temporal
			vetorAux[k] = fila->info[i];	// 1 Complexidade Temporal
			k++;	// 1 Complexidade Temporal
		}
		fila->cont--;	// 1 Complexidade Temporal
		free (fila->info);	// 1 Complexidade Temporal
		fila->info = vetorAux;	// 1 Complexidade Temporal
		return 1;	// 1 Complexidade Temporal
	}
	else 
		return 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(5) = O(c), c constante
// Complexidade Temporal = O(n+10) = O(n)

int size (Fila* fila){	// 1 Complexidade Espacial
	if (fila == NULL){	// 1 Complexidade Temporal
		return 0;	// 1 Complexidade Temporal
	}
	else {
		return fila->cont;  // 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(1) = O(c), com c constante
// Complexidade Temporal = O(4) = O(c), com c constante

int first (Fila* fila){	// 1 Complexidade Espacial
	if (isEmpty (fila)){  // 1 Complexidade Temporal
		return -1;	// 1 Complexidade Temporal
	}
	else {
		return fila->info[0];	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(c), c constante
// Complexidade Temporal = O(c), c constante

int last (Fila* fila){	// 1 Complexidade Espacial
	if (isEmpty (fila)){
		return -1;	// 1 Complexidade Temporal
	}
	else {
		return fila->info[fila->cont-1]; // 1 Complexidade Temporal
	}
}
// Complexidade Espacial e Complexidade Temporal = O(c), c constante

int find (Fila* fila, int n){	// 2 Complexidade Espacial
	if (!isEmpty (fila)){	// 1 Complexidade Temporal
		int i;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		for (i = 0; i < fila->tamanho; i++){	// N complexidade Temporal
			if (fila->info[i] == n){	// 1 Complexidade Temporal
				return i;	// 1 Complexidade Temporal
			}
		}
	}
	return -1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3)
// Complexidade Temporal = O(3+N) = O(N)

int isFull (Fila* fila){	// 1 Complexidade Espacial
	return fila->cont == fila->tamanho;	// 1 Complexidade Temporal
}
// Complexidade Espacial e Complexidade Temporal = O(c), c constante

void clear (Fila* fila){	// 1 Complexidade Espacial
	free (fila->info);	// 1 Complexidade Temporal
	free (fila);	// 1 Complexidade Temporal
}
// Complexidade Temporal = Complexidade Espacial = O(c), c constante

void printAll (Fila* fila){	// 1 Complexidade Espacial
	if (!isEmpty (fila)){	// 1 Complexidade Temporal
		int i = 0;	// 1 Complexidade Temporal, 1 Complexidade Espacial
		while (i != fila->cont){	// N Complexidade Temporal
			printf ("%d  <  ", fila->info[i]);	// 1 Complexidade Temporal
			i++;	// 1 Complexidade Temporal
		}
	}
	printf ("NULL");	// 1 Complexidade Temporal
}
// Complexidade Espacial: O(2)
// Complexidade Temporal: O(3+2*N) = O(N)