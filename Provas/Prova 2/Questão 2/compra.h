struct compra {
	int codigo;
	float valor;
};
typedef struct compra Compra;

Compra* createCompra (int cod, float val);

int getCodigo (Compra* compra);

float getValor (Compra* compra);
