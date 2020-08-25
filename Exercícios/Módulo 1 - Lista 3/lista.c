#include <stdio.h>
#include <stdlib.h>

struct lista {
	int limite;
	int contador;
	int* dados;
	int* insercoes;
};
typedef struct lista Lista;

Lista* create (int n){
	Lista* novaLista = (Lista*) malloc (sizeof (Lista));
	Lista* novaInsercao = (Lista*) malloc (sizeof (Lista));
	
	if (novaLista == NULL || novaInsercao == NULL){
		return NULL;
	}
	else {
		novaLista->dados = (int*) malloc(n * sizeof(int));
		novaLista->insercoes = (int*) malloc (n * sizeof (int));
		novaLista->limite = n;
		int i;
		// Colocando todas as posições do vetor para iniciarem como vazias.
		for (i = 0; i < n; i++){
			novaLista->insercoes[i] = 0;
		}
		return novaLista;
	}
}

int add (Lista* lista, int elemento){
	if (lista != NULL && lista->contador < lista->limite){
		lista->dados[lista->contador] = elemento;
		lista->insercoes[lista->contador] = 1;
		lista->contador++;
		return 1;
	}
	return 0;
}

int addAtPosition (Lista* lista, int x, int i){
	if (lista != NULL && lista->contador < lista->limite && i >= 0 && i < lista->limite && lista->insercoes[i] != 1){
		lista->dados[i] = x;
		lista->insercoes[i] = 1;
		lista->contador++;
		return 1;
	}
	return 0;
}

int isEmpty (Lista* lista){
	return lista == NULL || lista->contador == 0;
}

int remover (Lista* lista, int elemento){
	if (!isEmpty (lista)){
		int i;
		for (i = 0; i < lista->limite; i++){
			if (lista->dados[i] == elemento){
				int aux = lista->dados[i];
				int* vetAux = (int*) malloc (lista->limite * sizeof(int));
				int* auxIns = (int*) malloc (lista->limite * sizeof(int));
				int j, k = 0;
				for (j = 0; j < lista->limite; j++){
					if (lista->dados[j] != elemento){
						if (lista->insercoes[j] == 1){
							vetAux[k] = lista->dados[j];
							auxIns[k] = 1;
						}
						else {
							vetAux[k] = 0;
						}
						k++;
					}
				}
				lista->contador--;
				free (lista->dados);
				free (lista->insercoes);
				lista->dados = vetAux;
				lista->insercoes = auxIns;
				return 1;
			}
		}
		return 0;
	}
	return 0;
}

int removeAtPosition (Lista* lista, int x, int i){
	if (!isEmpty (lista) && i >= 0 && i < lista->limite && lista->insercoes[i] == 1 && lista->dados[i] == x){
		int* aux = (int*) malloc (lista->limite * sizeof (int));
		int* aux2 = (int*) malloc (lista->limite * sizeof(int));
		int j, k = 0;
		
		for (j = 0; j < lista->limite; j++){
			if (j != i){
				if (lista->insercoes[j] == 1){
					aux[k] = lista->dados[j];
					aux2[k] = 1;
				}
				else {
					aux2[k] = 0;
				}
				k++;
			}
		}
		lista->contador--;
		free(lista->dados);
		free(lista->insercoes);
		lista->dados = aux;
		lista->insercoes = aux2;
		return 1;
	}
	return 0;
}

int size (Lista* lista){
	if (!isEmpty (lista)){
		return lista->contador;
	}
	return 0;
}

int find (Lista* lista, int valor){
	if (!isEmpty(lista)){
		int i;
		for (i = 0; i < lista->contador; i++){
			if (lista->dados[i] == valor){
				return i;
			}
		}
		return -1;
	}
	return -1;
}

int isFull (Lista* lista){
	if (!isEmpty(lista) && lista->contador == lista->limite){
		return 1;
	}
	return 0;
}

void clear (Lista* lista){
	free (lista->dados);
	free (lista->insercoes);
	free(lista);
}

void printAll (Lista* lista){
	if (!isEmpty(lista)){
		int i;
		for (i = 0; i < lista->limite; i++){
			if (lista->insercoes[i] == 0){
				printf ("NULL -> ");
			}
			else {
				printf ("%d -> ", lista->dados[i]);
			}
		}
	}
	printf("FIM\n\n");
	
}
