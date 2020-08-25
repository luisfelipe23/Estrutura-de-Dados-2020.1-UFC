#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
	Lista* lista1 = create(8);
	add (lista1, 6);
	add (lista1, 4);
	add (lista1, 1);
	add (lista1, 2);
	add (lista1, 65);
	add (lista1, 3);
	addAtPosition(lista1, 34, 7);
	addAtPosition(lista1, 58, 6);
	printAll (lista1);
	printf ("Tamanho: %d\nPosicao do numero 34: %d\nEsta cheio? %d\n\n", size(lista1), find(lista1, 34), isFull(lista1));
	remover(lista1, 6);
	printAll (lista1);
	printf ("Tamanho: %d\nPosicao do numero 34: %d\nEsta cheio? %d\n\n", size(lista1), find(lista1, 34), isFull(lista1));
	removeAtPosition(lista1, 2, 2);
	printAll (lista1);
	printf ("Tamanho: %d\nPosicao do numero 34: %d\nEsta vazia? %d\n\n", size(lista1), find(lista1, 34), isEmpty(lista1));
	addAtPosition(lista1, 51, 7);
	printAll (lista1);
	printf ("Tamanho: %d\nPosicao do numero 34: %d\n\n", size(lista1), find(lista1, 34));
	clear(lista1);
	printAll (lista1);
	printf ("Tamanho: %d\nPosicao do numero 34: %d\nEsta vazia? %d", size(lista1), find(lista1, 34), isEmpty(lista1));
	return 0;
}
