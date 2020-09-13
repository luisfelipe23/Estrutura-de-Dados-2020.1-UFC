#include "No.h"
#include <stdio.h>
#include <stdlib.h>

struct lista {
	No* inicio;
	No* fim;
	int tamanho;
};
typedef struct lista Lista;

Lista* create();

int add(Lista* lista, int valor);

int remover(Lista* lista, int elemento);

int size (Lista* lista);

int find (Lista* lista, int valor);

int isEmpty(Lista* lista);

void clear(Lista* lista);

void imprimirLista(Lista* lista);
