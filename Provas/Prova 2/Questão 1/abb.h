struct no {
	int info;
	struct no* esq;
	struct no* dir;
};
typedef struct no No;

struct arvore {
	No* raiz;
};
typedef struct arvore Arvore;

Arvore* create ();

int add (Arvore* arvore, int elemento);

int find (Arvore* arvore, int elemento);

void printAllPos (Arvore* arvore);

void printAllPre (Arvore* arvore);

void printAllIn (Arvore* arvore);

void clear (Arvore* arvore);
