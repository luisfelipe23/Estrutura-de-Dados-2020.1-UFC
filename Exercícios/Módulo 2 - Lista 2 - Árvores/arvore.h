#define LADO_ESQ 0
#define LADO_DIR 1

struct no {
	char carac;
	struct no* dir;
	struct no* esq;
	int cont;
};
typedef struct no No;

struct arvore {
	No* raiz;
};
typedef struct arvore Arvore;

Arvore* create ();

No* createRoot (Arvore* arvore, char elemento);

No* inserirFilho (int lado, No* no, char elemento);

int size (Arvore* arvore);

int find (Arvore* arvore, char elemento);

int isEmpty(Arvore* arvore);

void printAllPre (Arvore* arvore);

void printAllIn (Arvore* arvore);

void printAllPost (Arvore* arvore);

void clear (Arvore* arvore);
