
#include "04.res.h"

struct my_struct {
	int intVal;
	float floatVal;
	char charVal;
};

struct my_struct* create_new_point() {
	struct my_struct* p = (struct my_struct*) malloc(1 * sizeof(struct my_struct));
	p->intVal = 0;
	p->floatVal = 0.0;
	p->charVal = 'A';
	return p;
}

void set_intVal(struct my_struct* p, int val) {
	(*p).intVal = val;
}

void set_floatVal(struct my_struct* p, float val) {
	(*p).floatVal = val;
}

int get_intVal(struct my_struct* p) {
	return (*p).intVal;
}

float get_floatVal(struct my_struct* p) {
	return (*p).floatVal;
}
