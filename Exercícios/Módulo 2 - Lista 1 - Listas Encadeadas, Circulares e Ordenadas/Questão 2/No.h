struct no {
	int info;
	struct no* prox;
	struct no* ant;
};
typedef struct no No;

No* createNo(int valor, No* proximo, No* anterior);

void printNo(No* no);

void freeNo (No* no);
