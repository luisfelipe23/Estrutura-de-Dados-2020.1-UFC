#include <stdio.h>
#include <stdlib.h>
#include "compras.h"

struct repositorio {
	Compra** repCompras;
	int n;
	int k;
};
typedef struct repositorio Rep;

Rep* criarRepositorio (int n){
	Rep* novoRep = (Rep*) malloc (sizeof (Rep));
	novoRep->n = n;
	novoRep->k = 0;
	novoRep->repCompras = (Compra**) malloc (n * sizeof (Compra*));
	return novoRep;
}

int validarCodigo (Rep* rep, int cod){
	if (rep != NULL){
		if (rep->k > 0){
			int i;
			for (i = 0; i < rep->k; i++){
				Compra* c = rep->repCompras[i];
				if (cod == getCodigo(c)){
					return 0;
				}
			}
		}
		else {
			return 1;
		}
		return 1;
	}
	return 0;
}

int adicionar (Rep* rep, Compra* compra){
	if (rep != NULL && rep->k < rep->n){
		rep->repCompras[rep->k] = compra;
		rep->k++;
		return 1;
	}
	return 0;
}

int tamanho (Rep* rep){
	if (rep != NULL && rep->k > 0){
		return rep->k;
	}
	return 0;
}

int estaCheio (Rep* rep){
	return rep->k == rep->n;
}

int estaVazio (Rep* rep){
	return rep == NULL || rep->k == 0;
}

int pesquisar(Rep* rep, int codigo){
	if (!estaVazio(rep)){
		int i;
		for (i = 0; i < rep->k; i++){
			Compra* c = rep->repCompras[i];
			if (codigo == getCodigo(c)){
				return i;
			}
		}
		return -1;
	}
	return -1;	
}

int tratar(Rep* rep, int codigo){
	if (!estaVazio(rep)){
		int i;
		for (i = 0; i < rep->k; i++){
			Compra* c = rep->repCompras[i];
			if (getCodigo(c) == codigo){
				printf("\n\n====================================================\n\n");
				printf("Código do produto: %d\nValor do produto: R$ %.2f\n\n", getCodigo(c), getValor(c));
				int j, k = 0;
				Compra** repAux = (Compra**) malloc (rep->n * sizeof(Compra*));
				for (j = 0; j < rep->k; j++){
					if (c != rep->repCompras[j]){
						repAux[k] = rep->repCompras[j];
						k++;
					}
				}
				rep->k--;
				free(rep->repCompras);
				rep->repCompras = repAux;
				return 1;
			}
		}
		return NULL;
	}
	return NULL;
}

void printRepositorio (Rep* rep){
	if (!estaVazio(rep)){
		int i;
		for (i = 0; i < rep->k; i++){
			Compra* c = rep->repCompras[i];
			printf ("\n\n===================================================================");
			printf ("\nPRODUTO Nº %d\nCódigo do produto: %d\nValor do produto: R$ %.2f", i+1, getCodigo(c), getValor(c));
		}
	}
	else {
		printf ("\n\nRepositório vazio!");
	}
}

void esvaziar (Rep* rep){
	rep->k = 0;
	free(rep->repCompras);
}
