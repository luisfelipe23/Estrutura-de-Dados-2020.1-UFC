#include <stdio.h>
#include <stdlib.h>

struct compra {
	int codigo;
	float valor;
};
typedef struct compra Compra;

Compra* createCompra (int cod, float val){
	Compra* novaCompra = (Compra*) malloc (sizeof (Compra));
	novaCompra->codigo = cod;
	novaCompra->valor = val;
	return novaCompra;
}

int getCodigo (Compra* compra){
	return compra->codigo;
}

float getValor (Compra* compra){
	return compra->valor;
}

