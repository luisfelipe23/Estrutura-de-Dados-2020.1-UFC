#include "container.h"

struct fila {
	Container** info;
	int n;
	int k;
};
typedef struct fila filaCont;

filaCont* criarArmazem (int tam);

int adicionar (filaCont* armaz, Container* cont);

void swap (Container** cont, int i, int j);

int validarIdentidade (filaCont* armaz, int id);

int transportar (filaCont* armaz);

int contar (filaCont* armaz);

int pesquisarIdentidade (filaCont* armaz, int id);

int estaVazio (filaCont* armaz);

int estaCheio (filaCont* armaz);

void esvaziar (filaCont* armaz);

void imprimirArmazem (filaCont* armaz);
