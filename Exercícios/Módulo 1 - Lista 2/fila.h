typedef struct fila Fila;

Fila* create (int n);

int add (Fila* fila, int elemento);

int isEmpty (Fila* fila);

int pop (Fila* fila);

int size (Fila* fila);

int first (Fila* fila);

int last (Fila* fila);

int find (Fila* fila, int n);

int isFull (Fila* fila);

void clear (Fila* fila);

void printAll (Fila* fila);

