#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main() {
	Lista* lista1 = create();
	add(lista1, 6);
	add(lista1, 1);
	add(lista1, 7);
	add(lista1, 2);
	add(lista1, 5);
	imprimirLista(lista1);
	printf ("Elemento 2 esta na posicao: %d\n\n", find(lista1, 2));
	pop(lista1, 6);
	imprimirLista(lista1);
	pop(lista1, 5);
	imprimirLista(lista1);
	pop(lista1, 7);
	imprimirLista(lista1);
	lista1 = clear(lista1);
	imprimirLista(lista1);
	return 0;
}

