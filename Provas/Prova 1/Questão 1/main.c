#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
	Fila* fila1 = create(4);
	add(fila1, 3);
	add(fila1, 7);
	add(fila1, 1);
	add(fila1, 4);
	printAll(fila1);
	printf("Primeiro: %d\nUltimo: %d\n\n", first(fila1), last(fila1));
	add(fila1, 2);
	printAll(fila1);
	printf("Primeiro: %d\nUltimo: %d\n\n", first(fila1), last(fila1));
	add(fila1, 6);
	printAll(fila1);
	printf("Primeiro: %d\nUltimo: %d\n\n", first(fila1), last(fila1));
	remover(fila1);
	remover(fila1);
	printAll(fila1);
	printf("Primeiro: %d\nUltimo: %d\n\n", first(fila1), last(fila1));
	add(fila1, 46);
	printAll(fila1);
	printf("Primeiro: %d\nUltimo: %d\n\n", first(fila1), last(fila1));
	add(fila1, 45);
	printAll(fila1);
	printf("Primeiro: %d\nUltimo: %d\n\n", first(fila1), last(fila1));
	add(fila1, 5);
	printAll(fila1);
	printf("Primeiro: %d\nUltimo: %d\n\n", first(fila1), last(fila1));
	remover(fila1);
	printAll(fila1);
	printf("Primeiro: %d\nUltimo: %d\n\n", first(fila1), last(fila1));
}
