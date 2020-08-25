typedef struct lista Lista;

Lista* create (int n);

int add (Lista* lista, int elemento);

int addAtPosition (Lista* lista, int x, int i);

int isEmpty (Lista* lista);

int remover (Lista* lista, int elemento);

int removeAtPosition (Lista* lista, int x, int i);

int size (Lista* lista);

int find (Lista* lista, int valor);

int isFull (Lista* lista);

void clear (Lista* lista);

void printAll (Lista* lista);
