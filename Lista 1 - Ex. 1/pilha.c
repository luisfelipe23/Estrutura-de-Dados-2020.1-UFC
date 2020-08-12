#include <stdio.h>
#include <stdlib.h>

struct pilha {
	int tamanho;
	int cont;
	int* info;
};
typedef struct pilha Pilha;

Pilha* create (int n){  // 1 Complexidade Espacial
	Pilha* novaPilha = (Pilha*) malloc (sizeof (Pilha));  // 1 Complexidade espacial, 1 Complexidade temporal
	
	if (novaPilha == NULL){  // 1 Complexidade temporal 
		return NULL;  // 1 Complexidade temporal
	}
	else {  
		novaPilha->info = (int*) malloc (n * sizeof (int));  // 1 Complexidade espacial, 1 Complexidade Temporal
		novaPilha->tamanho = n;   // 1 Complexidade Espacial, 1 Complexidade Temporal
		return novaPilha;  // 1 Complexidade Temporal
	}
}
// Complexidade temporal: O(c), onde c é uma constante
// Complexidade espacial: O(c), com c igual a uma constante

int add (Pilha* pilha, int elemento){  // 2 Complexidade Espacial
	if (pilha != NULL && pilha->cont < pilha->tamanho){  // 1 Complexidade Temporal
		pilha->info[pilha->cont] = elemento;  // 1 Complexidade Temporal
		pilha->cont++; // 1 Complexidade Temporal
		return 1; // 1 Complexidade Temporal
	}
	return 0;  // 1 Complexidade Temporal
}
// Complexidade Temporal: O(c), onde c é uma constante
// Complexidade Espacial: O(c), com c constante

int pop (Pilha* pilha){  // 1 Complexidade Espacial
	if (pilha != NULL){  // 1 Complexidade Temporal
		pilha->info[pilha->cont-1] = NULL;  // 1 Complexidade Temporal
		pilha->cont--;  // 1 Complexidade Temporal
		return 1;  // 1 Complexidade Temporal
	}
	return 0;  // 1 Complexidade Temporal
}
// Tanto a Complexidade Temporal quanto a Complexidade Espacial serão O(c) com c sendo uma constante

int isEmpty (Pilha* pilha){ // 1 Complexidade Espacial
	return pilha == NULL || pilha->cont == 0;  // 1 Complexidade Temporal
}
// Complexidade Temporal e Complexidade Espacial = O(c), com c constante

int size (Pilha* pilha){ // 1 Complexidade Espacial
	if (pilha == NULL || isEmpty (pilha)){  // 1 Complexidade Temporal
		return 0;  // 1 Complexidade Temporal
	}
	return pilha->cont;  // 1 Complexidade Temporal
}
// Complexidade Temporal: O(c), c = constante
// Complexidade Espacial: O(c), c = constante

int top (Pilha* pilha){  // 1 Complexidade Espacial
	if (pilha != NULL && !isEmpty (pilha)){  // 1 Complexidade Temporal
		return pilha->info[pilha->cont-1];  // 1 Complexidade Temporal
	}
	return -1;  // 1 Complexidade Temporal
}
// Complexidade Temporal e Complexidade Espacial = O(c), com c constante

int bottom (Pilha* pilha){  // 1 Complexidade Espacial
	if (pilha == NULL || isEmpty (pilha)){  // 1 Complexidade Temporal
		return 0;  // 1 Complexidade Temporal
	}
	return pilha->info[0];  // 1 Complexidade Temporal
}
// Complexidade temporal = O(c), c = constante igual a 3
// Complexidade espacial = O(c), c = constante igual a 1

int find (Pilha* pilha, int elemento){  // 2 Complexidade Espacial
	if (pilha != NULL || !isEmpty (pilha)){  // 1 Complexidade Temporal
		int i;  // 1 Complexidade Temporal, 1 Complexidade Temporal
		for (i = 0; i < pilha->tamanho; i++){  // N Complexidade Temporal
			if (pilha->info[i] == elemento){  // 1 Complexidade Temporal
				return i;  // 1 Complexidade Temporal
			}
		}
		return -1; // 1 Complexidade Temporal
	}
	return -1;  // 1 Complexidade Temporal
}
// Complexidade Temporal = O(n)
// Complexidade Espacial = O(c), com c constante

int isFull (Pilha* pilha){  // 1 Complexidade Espacial
	if (pilha->cont == pilha->tamanho){  // 1 Complexidade Temporal
		return 1;  // 1 Complexidade Temporal
	}
	return 0;  // 1 Complexidade Temporal
}
// Complexidade Temporal e Complexidade Espacial = O(c), com c constante

void clear (Pilha* pilha){  // 1 Complexidade Espacial
	if (pilha != NULL && !isEmpty (pilha)){  // 1 Complexidade Temporal
		while (pilha->cont != 0){  // N Complexidade Temporal
			pilha->info[pilha->cont] = NULL;  // 1 Complexidade Temporal
			pilha->cont--;  // 1 Complexidade Temporal
		}
		free (pilha);  // 1 Complexidade Temporal
	}
}
// Complexidade Temporal: O(2 + n*2) = O(n)
// Complexidade Espacial O(c), com c = 1, c constante