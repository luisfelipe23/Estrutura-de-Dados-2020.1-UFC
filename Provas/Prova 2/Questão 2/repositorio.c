#include <stdlib.h>
#include <stdio.h>
#include "repositorio.h"

Rep* criarRepositorio (int limite){	// 1 Complexidade Espacial
	Rep* novoRep = (Rep*) malloc (sizeof(Rep));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	novoRep->n = limite;	// 1 Complexidade Temporal
	novoRep->k = 0;	// 1 Complexidade Temporal
	novoRep->repCompras = (Compra**) malloc (limite * sizeof (Compra*));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	return novoRep;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3) = O(c), c constante
// Complexidade Temporal = O(5) = O(c), c constante

int adicionar (Rep* rep, Compra* compra){	// 3 Complexidade Espacial
	if (rep->n > 0 && rep->k == 0){	// 1 Complexidade Temporal
		rep->repCompras[0] = compra;	// 1 Complexidade Temporal
		rep->k++;	// 1 Complexidade Temporal
	}
	else {
		int i, posicao = rep->k;	// 2 Complexidade Espacial, 2 Complexidade Temporal
		float v = getValor(compra);	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		for (i = 0; i < rep->k; i++){	// N Complexidade Temporal
			Compra* c = rep->repCompras[i];	// 1 Complexidade Espacial, 1 Complexidade Temporal
			if (v < getValor(c)){	// 1 Complexidade Temporal
				posicao = i;	// 1 Complexidade Temporal
				break;	// 1 Complexidade Temporal
			}
		}
		if (posicao != rep->k){	// 1 Complexidade Temporal
			for (i = rep->k; i > posicao; i--){	// M Complexidade Temporal
				swap (rep->repCompras, i-1, i);	// 1 Complexidade Espacial, 3 Complexidade Temporal
			}
		}
		rep->repCompras[posicao] = compra;	// 1 Complexidade Temporal
		rep->k++;	// 1 Complexidade Temporal
		return 1;	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(5 + N + M) = O(N + M)
// Complexidade Temporal = O(12 + N*4 + M*3) = O(12 + N + M) = O(N + M)

void swap (Compra** compra, int i, int j){	// 3 Complexidade Espacial
	Compra* aux = compra[i];	// 1 Complexidade Espacial, 1 Complexidade Temporal
	compra[j] = compra[i];	// 1 Complexidade Temporal
	compra[i] = aux;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(4) = O(c), c constante
// Complexidade Temporal = O(3) = O(c), c constante

int validarCodigo (Rep* rep, int cod){	// 2 Complexidade Espacial
	if (!estaVazio(rep)){	// 1 Complexidade Temporal
		int i;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		for (i = 0; i < rep->k; i++){	// N Complexidade Temporal
			Compra* c = rep->repCompras[i];
			if (cod == getCodigo(c)){	// 1 Complexidade Temporal
				return 0;	// 1 Complexidade Temporal
			}
		}
		return 1;	// 1 Complexidade Temporal
	}
	return 1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3) = O(c), c constante
// Complexidade Temporal = O(N)

int tratar (Rep* rep){	// 2 Complexidade Espacial
	if (!estaVazio(rep)){	// 1 Complexidade Temporal
		int i, k = 0;	// 2 Complexidade Espacial, 2 Complexidade Temporal
		Compra* c = rep->repCompras[rep->k-1];	// 1 Complexidade Espacial, 1 Complexidade Temporal
		Compra** repAux = (Compra**) malloc (sizeof (Compra*));	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		printf ("\n\n====================================================\n\n");	// 1 Complexidade Temporal
		printf ("Código do produto: %d\nValor do produto: R$ %.2f\n\n", getCodigo(c), getValor(c));	// 1 Complexidade Temporal
		for (i = 0; i < rep->k - 1; i++){	// N Complexidade Temporal
			repAux[k] = rep->repCompras[i];	// 1 Complexidade Temporal
			k++;
		}
		rep->k--;	// 1 Complexidade Temporal
		free(rep->repCompras);	// 1 Complexidade Temporal
		rep->repCompras = repAux;	// 1 Complexidade Temporal
		return 1;	// 1 Complexidade Temporal
	}
	printf ("\nOperação inválida!");	// 1 Complexidade Temporal
	return 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(7) = O(c), c constante
// Complexidade Temporal = O(16 + 2*N) = O(N)

int tamanho (Rep* rep){	// 1 Complexidade Espacial
	return rep->k;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

int pesquisarValor (Rep* rep, float valor){	// 2 Complexidade Espacial
	if (!estaVazio(rep)){	// 1 Complexidade Temporal
		int esq = 0;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		int dir = rep->k;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		
		while (esq <= dir){	// Logn Complexidade Temporal
			int meio = (esq + dir) / 2;	// 1 Complexidade Temporal, 1 Complexidade Espacial
			
			Compra* c = rep->repCompras[meio];	// 1 Complexidade Espacial, 1 Complexidade Temporal
			if (getValor(c) == valor){	// 1 Complexidade Temporal
				return meio + 1;	// 1 Complexidade Temporal
			}
			else {
				if (getValor(c) > valor){	// 1 Complexidade Temporal
					dir = meio - 1;	// 1 Complexidade Temporal
				}
				else {
					esq = meio + 1;	// 1 Complexidade Temporal
				}
			}
		}
	}
	return -1;	// 1 Compexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(Log n)

int pesquisarCodigo (Rep* rep, int codigo){	// 2 Complexidade Espacial
	if (!estaVazio(rep)){	// 1 Complexidade Temporal
		int i; 	// 1 Complexidade Espacial, 1 Complexidade Temporal
		for (i = 1; i <= rep->k; i++){	// N Complexidade Temporal
			Compra* c = rep->repCompras[i-1];	// 1 Complexidade Espacial, 1 Complexidade Temporal
			if (codigo == c->codigo){	// 1 Complexidade Temporal
				return i;	// 1 Complexidade Temporal
			}
		}
	}
	return -1;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3 + N) = O(N)
// Complexidade Temporal = O(3 + 3*N) = O(3 + N) = O(N)

int estaVazio (Rep* rep){	// 1 Complexidade Espacial
	return rep->k <= 0;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

int estaCheio (Rep* rep){	// 1 Complexidade Espacial
	return rep->k == rep->n;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

void esvazia (Rep* rep){	// 1 Complexidade Espacial
	rep->k = 0;	// 1 Complexidade Temporal
	free(rep->repCompras);	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

void printRepositorio (Rep* rep){	// 1 Complexidade Espacial
	if (!estaVazio(rep)){	// 1 Complexidade Temporal
		int i;	// 1 Complexidade Espacial, 1 Complexidade Temporal
		for (i = 0; i < rep->k; i++){	// N Complexidade Temporal
			printf ("\n\n===================================================================");	// 1 Complexidade Temporal
			Compra* c = rep->repCompras[i];
			printf ("\nPRODUTO Nº %d\nCódigo do produto: %d\nValor do produto: R$ %.2f", i + 1, getCodigo(c), getValor(c));	// 1 Complexidade Temporal
		}
	}
	else {
		printf ("\n\nRepositório vazio!");	// 1 Complexidade Temporal
	}
}
// Complexidade Espacial = O(2) = O(c), c constante
// Complexidade Temporal = O(N) 
