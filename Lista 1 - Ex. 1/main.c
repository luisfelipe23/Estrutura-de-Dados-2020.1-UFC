#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main (){
	Pilha* pilha1 = create (4);
	add (pilha1, 4);
	add (pilha1, 9);
	add (pilha1, 6);
	add (pilha1, 5);

	printf ("Base: %d \nTopo: %d \nTamanho: %d \nEsta cheia? %d", bottom (pilha1), top (pilha1), size (pilha1), isFull (pilha1));
	pop (pilha1);
	printf ("\n\nBase: %d \nTopo: %d \nTamanho: %d \nEsta cheia? %d", bottom (pilha1), top (pilha1), size (pilha1), isFull (pilha1));
	printf ("\nO elemento 6 esta na posicao: %d", find (pilha1, 6));
	clear (pilha1);
	printf ("\n\nBase: %d \nTopo: %d \nTamanho: %d \nEsta cheia? %d", bottom (pilha1), top (pilha1), size (pilha1), isFull (pilha1));
}