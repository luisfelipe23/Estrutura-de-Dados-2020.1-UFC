#include <stdio.h>
#include <stdlib.h>
#include "compra.h"

Compra* createCompra (int cod, float val){	// 2 Complexidade Espacial
	Compra* novaCompra = (Compra*) malloc (sizeof (Compra));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	novaCompra->codigo = cod;	// 1 Complexidade Temporal
	novaCompra->valor = val;	// 1 Complexidade Temporal
	return novaCompra;	// 1 Complexidade Temporal
}
// Complexidade Espacial = O(3) = O(c), c constante
// Complexidade Temporal = O(4) = O(c), c constante

int getCodigo (Compra* compra){	// 1 Complexidade Espacial
	return compra->codigo;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante

float getValor (Compra* compra){	// 1 Complexidade Espacial
	return compra->valor;	// 1 Complexidade Temporal
}
// Complexidade Espacial = Complexidade Temporal = O(c), c constante
