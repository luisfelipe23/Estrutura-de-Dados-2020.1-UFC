#include <stdio.h>
#include <stdlib.h>
#include "No.h"

struct lista {
	No* inicio;
	No* fim;
	int tamanho;
};
typedef struct lista Lista;

Lista* create();

int add (Lista* lista, int elemento);

int isEmpty(Lista* lista);

int pop(Lista* lista, int elemento);

int size(Lista* lista);

int find (Lista* lista, int elemento);

void clear(Lista* lista);

void imprimirLista (Lista* lista);
