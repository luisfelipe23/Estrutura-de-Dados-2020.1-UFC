#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
	Arvore* arvore1 = create();
	createRoot (arvore1, 'a');
	inserirFilho (LADO_ESQ, arvore1->raiz, 'b');
	inserirFilho (LADO_ESQ, arvore1->raiz->esq, 'd');
	inserirFilho (LADO_DIR, arvore1->raiz->esq->esq, 'g');
	inserirFilho (LADO_DIR, arvore1->raiz, 'c');
	inserirFilho (LADO_ESQ, arvore1->raiz->dir, 'e');
	inserirFilho (LADO_DIR, arvore1->raiz->dir, 'f');
	inserirFilho (LADO_ESQ, arvore1->raiz->dir->esq, 'h');
	inserirFilho (LADO_DIR, arvore1->raiz->dir->esq, 'i');
	printAllPre (arvore1);
	printf ("\n\n");
	printAllIn (arvore1);
	printf ("\n\n");
	printAllPost(arvore1);
	printf ("\n\nTamanho: %d\nO elemento 'i' esta no nivel: %d\n\n", size(arvore1), find(arvore1, 'i'));
	clear(arvore1);
	printf ("\n\nEsta vazia? %d", isEmpty(arvore1));
	return 0;
}
