typedef struct fila Fila;

Fila* create(int n);

int add(Fila* fila, int elemento);

int isEmpty(Fila* fila);

int remover(Fila* fila);

int first(Fila* fila);

int last(Fila* fila);

void printAll (Fila* fila);
