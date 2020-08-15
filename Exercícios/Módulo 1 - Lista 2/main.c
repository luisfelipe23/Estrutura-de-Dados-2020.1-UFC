#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main (){
	Fila* fila1 = create (5);
	add (fila1, 6);
	add (fila1, 4);
	add (fila1, 9);
	add (fila1, 2);
	add (fila1, 1);
	printf ("Primeiro: %d\n", first (fila1));
	printf ("Ultimo: %d\n", last (fila1));
	printf ("Tamanho: %d\n", size(fila1));
	printf ("Esta cheia? %d\n", isFull (fila1));
	printf ("Posicao do numero 4: %d\n", find (fila1, 4));
	printAll (fila1);
	pop (fila1);
	printf ("\n\nPrimeiro: %d\n", first (fila1));
	printf ("Ultimo: %d\n", last (fila1));
	printf ("Tamanho: %d\n", size(fila1));
	printf ("Esta cheio? %d\n", isFull (fila1));
	printf ("Posicao do numero 4: %d\n", find (fila1, 4));
	printAll (fila1);
	pop (fila1);
	printf ("\n\nPrimeiro: %d\n", first (fila1));
	printf ("Ultimo: %d\n", last (fila1));
	printf ("Tamanho: %d\n", size(fila1));
	printf ("Esta cheio? %d\n", isFull (fila1));
	printf ("Posicao do numero 4: %d\n", find (fila1, 4));
	printAll (fila1);
}
