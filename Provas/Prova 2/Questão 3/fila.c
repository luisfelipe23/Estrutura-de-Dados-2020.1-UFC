#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

filaCont* criarArmazem (int tam){	// 1 Complexidade Espacial
	filaCont* novoArm = (filaCont*) malloc (sizeof (filaCont));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	novoArm->n = tam;	// 1 Complexidade Temporal
	novoArm->k = 0;	// 1 Complexidade Temporal
	novoArm->info = (Container**) malloc (tam * sizeof(Container*));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	return novoArm;	/// 1 Complexidade Temporal
}
// Complexidade Temporal = Complexidade Espacial = O(c), c constante

int adicionar (filaCont* armaz, Container* cont){	// 3 Complexidade Espacial
	if (armaz->n > 0 && armaz->k == 0){	// 1 Complexidade Temporal
		armaz->info[0] = cont;	// 1 Complexidade Temporal
		armaz->k++;	// 1 Complexidade Temporal
	}
	else {
		int i, posicao = 0;	// 2 Complexidade Espacial, 2 Complexidade Temporal
		float v = getPeso(cont);	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		for (i = armaz->k-1; i >= 0; i--){	// N Complexidade Temporal
			Container* c = armaz->info[i];	// 1 Complexidade Espacial, 1 Complexidade Temporal
			if (v < getPeso(c)){	// 1 Complexidade Temporal
				posicao = i+1;	// 1 Complexidade Temporal
				break;	// 1 Complexidade Temporal
			}
		}
		if (posicao != armaz->k){	// 1 Complexidade Temporal
			for (i = armaz->k; i > posicao; i--){	// M Complexidade Temporal
				swap (armaz->info, i-1, i);	// 1 Complexidade Espacial, 3 Complexidade Temporal
			}
		}
		armaz->info[posicao] = cont;	// 1 Complexidade Temporal
		armaz->k++;	// 1 Complexidade Temporal
		return 1;	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(5 + N + M) = O(N + M)
// Complexidade Temporal = O(12 + N*4 + M*3) = O(12 + N + M) = O(N + M)

void swap (Container** cont, int i, int j){	// 3 Complexidade Espacial
	Container* aux = cont[i];	// 1 Complexidade Espacial, 1 Complexidade Temporal
	cont[j] = cont[i];	// 1 Complexidade Temporal
	cont[i] = aux;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(4) = O(c), c constante
// Complexidade Temporal = O(3) = O(c), c constante

int validarIdentidade (filaCont* armaz, int id){	// 2 Complexidade Espacial
	if (!estaVazio(armaz)){	// 1 Complexidade Temporal
		int i;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		for (i = 0; i < armaz->k; i++){	// N Complexidade Temporal
			Container* c = armaz->info[i];
			if (id == getId(c)){	// 1 Complexidade Temporal
				return 0;	// 1 Complexidade Temporal
			}
		}
		return 1;	// 1 Complexidade Temporal
	}
	return 1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3) = O(c), c constante
// Complexidade Temporal = O(N)

int transportar (filaCont* armaz){	// 1 Complexidade Espacial
	if (!estaVazio(armaz)){	// 1 Complexidade Temporal
		int i, k = 0;	// 2 Complexidade Espacial, 2 Complexidade Temporal
		Container* c = armaz->info[armaz->k-1];	// 1 Complexidade Espacial, 1 Complexidade Temporal
		Container** contAux = (Container**) malloc (sizeof (Container*));	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		printf ("\n\n====================================================\n\n");	// 1 Complexidade Temporal
		printf ("ID do container: %d\nPeso: R$ %.2f\n\n", getId(c), getPeso(c));	// 1 Complexidade Temporal
		for (i = 1; i < armaz->k; i++){	// N Complexidade Temporal
			contAux[k] = armaz->info[i];	// 1 Complexidade Temporal
			k++;
		}
		armaz->k--;	// 1 Complexidade Temporal
		free(armaz->info);	// 1 Complexidade Temporal
		armaz->info = contAux;	// 1 Complexidade Temporal
		return 1;	// 1 Complexidade Temporal
	}
	printf ("\nOperação inválida!");	// 1 Complexidade Temporal
	return 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(6) = O(c), c constante
// Complexidade Temporal = O(16 + 2*N) = O(N)

int contar (filaCont* armaz){	// 1 Complexidade Espacial
	return armaz->k;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

int pesquisarIdentidade (filaCont* armaz, int id){	// 2 Complexidade Espacial
	if (!estaVazio(armaz)){	// 1 Complexidade Temporal
		int i; 	// 1 Complexidade Espacial, 1 Complexidade Temporal
		for (i = 1; i <= armaz->k; i++){	// N Complexidade Temporal
			Container* c = armaz->info[i-1];	// 1 Complexidade Espacial, 1 Complexidade Temporal
			if (id == getId(c)){	// 1 Complexidade Temporal
				return i;	// 1 Complexidade Temporal
			}
		}
	}
	return -1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3 + N) = O(N)
// Complexidade Temporal = O(3 + 3*N) = O(3 + N) = O(N)

int estaVazio (filaCont* armaz){	// 1 Complexidade Espacial
	return armaz->k <= 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

int estaCheio (filaCont* armaz){	// 1 Complexidade Espacial
	return armaz->k == armaz->n;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

void esvaziar (filaCont* armaz){	// 1 Complexidade Espacial
	armaz->k = 0;	// 1 Complexidade Temporal
	free(armaz->info);	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

void imprimirArmazem (filaCont* armaz){	// 1 Complexidade Espacial
	if (!estaVazio(armaz)){	// 1 Complexidade Temporal
		int i;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		for (i = 0; i < armaz->k; i++){	// N Complexidade Temporal
			printf ("\n\n===================================================================");	// 1 Complexidade Temporal
			Container* c = armaz->info[i];
			printf ("\nCONTAINER Nº %d\nCódigo do container: %d\nPeso: R$ %.2f", i + 1, getId (c), getPeso(c));	// 1 Complexidade Temporal
		}
	}
	else {
		printf ("\n\nRepositório vazio!");	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(2) = O(c), c constante
// Complexidade Temporal = O(N) 
