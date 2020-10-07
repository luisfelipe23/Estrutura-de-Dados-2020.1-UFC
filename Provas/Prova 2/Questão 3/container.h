struct container {
	int id;
	float peso;
};
typedef struct container Container;

Container* createContainer (int id, float peso);

int getId(Container* c);

float getPeso (Container* c);
