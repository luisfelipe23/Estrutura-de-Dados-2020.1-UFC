typedef struct repositorio Rep;

Rep* criarRepositorio (int n);

int validarCodigo (Rep* rep, int cod);

int adicionar (Rep* rep, Compra* compra);

int tamanho (Rep* rep);

int estaVazio (Rep* rep);

int estaCheio (Rep* rep);

int pesquisar(Rep* rep, int codigo);

int tratar(Rep* rep, int codigo);

void printRepositorio (Rep* rep);

void esvaziar (Rep* rep);
