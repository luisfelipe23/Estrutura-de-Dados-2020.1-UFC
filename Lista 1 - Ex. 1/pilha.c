#include <stdio.h>
#include <stdlib.h>

struct pilha {
	int tamanho;
	int cont;
	int* info;
};
typedef struct pilha Pilha;

Pilha* create (int n){
	Pilha* novaPilha = (Pilha*) malloc (sizeof (Pilha));
	
	if (novaPilha == NULL){
		return NULL;
	}
	else {
		novaPilha->info = (int*) malloc (n * sizeof (int));
		novaPilha->tamanho = n;
		return novaPilha;
	}
}

int add (Pilha* pilha, int elemento){
	if (pilha != NULL && pilha->cont < pilha->tamanho){
		pilha->info[pilha->cont] = elemento;
		pilha->cont++;
		return 1;
	}
	return 0;
}

int pop (Pilha* pilha){
	if (pilha != NULL){
		pilha->info[pilha->cont-1] = NULL;
		pilha->cont--;
		return 1;
	}
	return 0;
}

int isEmpty (Pilha* pilha){
	return pilha == NULL || pilha->cont == 0;
}

int size (Pilha* pilha){
	if (pilha == NULL || isEmpty (pilha)){
		return 0;
	}
	return pilha->cont;
}

int top (Pilha* pilha){
	if (pilha != NULL && !isEmpty (pilha)){
		return pilha->info[pilha->cont-1];
	}
	return -1;
}

int bottom (Pilha* pilha){
	if (pilha == NULL || isEmpty (pilha)){
		return 0;
	}
	return pilha->info[0];
}

int find (Pilha* pilha, int elemento){
	if (pilha != NULL || !isEmpty (pilha)){
		int i;
		for (i = 0; i < pilha->tamanho; i++){
			if (pilha->info[i] == elemento){
				return i;
			}
		}
		return -1;
	}
	return -1;
}

int isFull (Pilha* pilha){
	if (pilha->cont == pilha->tamanho){
		return 1;
	}
	return 0;
}

void clear (Pilha* pilha){
	if (pilha != NULL && !isEmpty (pilha)){
		while (pilha->cont != 0){
			pilha->info[pilha->cont-1] == NULL;
			pilha->cont--;
		}
		pilha == NULL;
	}
}