#include "container.h"
#include <stdio.h>
#include <stdlib.h>

Container* createContainer (int id, float peso){	// 2 Complexidade Espacial
	Container* novoC = (Container*) malloc (sizeof (Container));	// 1 Complexidade Espacial, 1 Complexidade Temporal
	if (novoC != NULL){	// 1 Complexidade Temporal
		novoC->id = id;	// 1 Complexidade Temporal
		novoC->peso = peso;	// 1 Complexidade Temporal
	}
	return novoC;	// 1 Complexidade Temporal
}
// Complexidade Temporal = Complexidade Espacial = O(c), c constante

int getId(Container* c){	// 1 Complexidade Espacial
	return c->id;	// 1 Complexidade Temporal
}
// Complexidade Temporal = Complexidade Espacial = O(c), c constante

float getPeso (Container* c){	// 1 Complexidade Espacial
	return c->peso;	// 1 Complexidade Temporal
}
// Complexidade Temporal = Complexidade Espacial = O(c), c constante

