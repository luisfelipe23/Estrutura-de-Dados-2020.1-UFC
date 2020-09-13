#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"

int main() {
	Lista* lista1 = create(6);
	add(lista1, 2);
	add(lista1, 9);
	add(lista1, 7);
	add(lista1, 3);
	add(lista1, 1);
	add(lista1, 6);
	printf("Tamanho: %d\n", size(lista1));
	printf("O elemento 7 esta na posicao: %d\n", linearSearch(lista1, 7));
	imprimir(lista1);
	remover(lista1, 3);
	printf("Tamanho: %d\n", size(lista1));
	printf("O elemento 7 esta na posicao: %d\n", linearSearch(lista1, 7));
	imprimir(lista1);
	remover(lista1, 1);
	printf("Tamanho: %d\n", size(lista1));
	printf("O elemento 6 esta na posicao: %d\n", binarySearch(lista1, 6));
	imprimir(lista1);
	remover(lista1, 9);
	printf("Tamanho: %d\n", size(lista1));
	printf("O elemento 9 esta na posicao: %d\n", binarySearch(lista1, 9));
	imprimir(lista1);
	return 0;
}
