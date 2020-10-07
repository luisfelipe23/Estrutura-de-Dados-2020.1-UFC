#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
#include "abb.h"

int main() {
	setlocale (LC_ALL, "Portuguese");
	Arvore* arvore1 = create ();
	
	add (arvore1, 17);
	add (arvore1, 13);
	add (arvore1, 99);
	add (arvore1, 1);
	add (arvore1, 3);
	add (arvore1, 99);
	add (arvore1, 100);
	add (arvore1, 400);
	printAllPre (arvore1);
	printAllIn (arvore1);
	printAllPos (arvore1);
	find (arvore1, 99);
	find (arvore1, 97);
	clear (arvore1);
	return 0;
}
