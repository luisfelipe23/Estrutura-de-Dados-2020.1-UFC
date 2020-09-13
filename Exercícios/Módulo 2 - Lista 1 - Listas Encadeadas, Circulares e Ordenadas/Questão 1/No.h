struct no {
	int info;
	struct no* prox;
};
typedef struct no No;

No* createNo (int valor, No* proximo);

void freeNo(No* n);

void imprimirNo (No* no);
