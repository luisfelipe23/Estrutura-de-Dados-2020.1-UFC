struct lista {
	int tamanho;
	int cont;
	int* info;
};
typedef struct lista Lista;

Lista* create(int n);

int add(Lista* lista, int elemento);

int remover (Lista* lista, int valor);

int size(Lista* lista);

int linearSearch(Lista* lista, int valor);

int binarySearch(Lista* lista, int valor);

int isFull(Lista* lista);

int isEmpty(Lista* lista);

void clear(Lista* lista);

void swap (int* v, int i, int j);

void imprimir(Lista* lista);
