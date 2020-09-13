#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

int main() {
	Lista* lista1 = create();
	add(lista1, 6);
	add(lista1, 3);
	add(lista1, 8);
	add(lista1, 1);
	add(lista1, 5);
	imprimirLista(lista1);
	printf("\nO elemento 8 encontra-se na posicao: %d\n\n", find(lista1, 8));
	remover(lista1, 6);
	imprimirLista(lista1);
	remover(lista1, 5);
	imprimirLista(lista1);
	remover(lista1, 8);
	imprimirLista(lista1);
	clear(lista1);
	imprimirLista(lista1);
	return 0;
}
