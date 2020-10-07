#include <stdio.h>
#include <stdlib.h>

struct fila {
	int limite;
	int cont;
	int* info;
	int* o;
	int* f;
};
typedef struct fila Fila;

Fila* create(int n){
	Fila* novaFila = (Fila*) malloc (sizeof(Fila));
	
	if (novaFila == NULL){
		return NULL;
	}
	else {
		novaFila->limite = n;
		novaFila->cont = 0;
		novaFila->info = (int*) malloc (novaFila->limite * sizeof (int));
		novaFila->f = novaFila->o = NULL;
		return novaFila;
	}
}

int add(Fila* fila, int elemento){
	if (fila != NULL && fila->cont <= fila->limite){
		if (fila->cont == 0){
			fila->info[0] = elemento;
			fila->o = fila->info[0];
			if (fila->f == NULL){
				fila->f = fila->o;
			}
		}
		else {
			fila->info[fila->cont] = elemento;
			if (fila->info[fila->limite-1] != NULL){
				fila->f = fila->info[fila->limite-1];
			}
			else {
				fila->f = fila->info[fila->cont];
			}
		}
		fila->cont++;
		if (fila->cont == fila->limite){
			fila->cont = 0;
		}
		return 1;
	}
	return 0;
}

int remover(Fila* fila){
	if (fila != NULL && fila->cont > 0){
		if (fila->f == fila->o){
			free(fila->info);
			fila->f = fila->o = NULL;
			fila->cont = 0;
		}
		else {
			int* vetAux = (int*) malloc(fila->cont * sizeof(int));
			int i, j = 0;
			for (i = 1; i < fila->limite; i++){
				vetAux[j] = fila->info[i];
				j++;
			}
			if (fila->info[fila->cont] == fila->info[fila->limite-1] || fila->info[fila->cont+1] == NULL){
				fila->cont--;
			}
			else {
				if (fila->info[fila->cont+1] != NULL){
					int pos = 0;
					for (i = 0; i < fila->limite; i++){
						if (fila->info[i] != NULL){
							pos++;
						}
					}
					fila->cont = pos-1;
				}
			}
			fila->o = fila->info[1];
			fila->f = fila->info[fila->cont];
			free(fila->info);
			fila->info = vetAux;
		}
		return 1;
	}
	
}

int first(Fila* fila){
	if (fila != NULL){
		return fila->o;
	}
	return -1;
}

int last(Fila* fila){
	if (fila != NULL){
		return fila->f;
	}
	return -1;
}

int isEmpty(Fila* fila){
	return fila->cont == 0 || fila == NULL;
}

void printAll (Fila* fila){
	if (fila != NULL){
		int i = 0;
		do {
			printf("%d  <  ", fila->info[i]);
			i++;
		} while (fila->info[i-1] != fila->f);
	}
	if (fila->cont < fila->limite){
		printf ("FIM\n\n");
	}
	else {
		printf("INICIO\n\n");
	}
}
