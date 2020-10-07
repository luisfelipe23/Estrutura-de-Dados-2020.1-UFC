#include "compra.h"

struct repositorio {
	Compra** repCompras;
	int n;
	int k;
};
typedef struct repositorio Rep;

Rep* criarRepositorio (int limite);

int adicionar (Rep* rep, Compra* compra);

int tratar (Rep* rep);

int tamanho (Rep* rep);

int pesquisarValor (Rep* rep, float valor);

int pesquisarCodigo (Rep* rep, int codigo);

int estaVazio (Rep* rep);

int estaCheio (Rep* rep);

void esvazia (Rep* rep);

void printRepositorio (Rep* rep);

int validarCodigo (Rep* rep, int cod);
