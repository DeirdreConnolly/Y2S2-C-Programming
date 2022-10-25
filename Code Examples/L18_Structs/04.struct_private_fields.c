
#include <stdio.h>
#include "04.res.h"

void my_function(struct my_struct* p) {
	printf("my_point int val is = %d\n", get_intVal(p));
	printf("my_point float val is = %f\n", get_floatVal(p));

	set_intVal(p, 3);
	set_floatVal(p, 3.0);

	printf("my_point int val is = %d\n", get_intVal(p));
	printf("my_point float val is = %f\n", get_floatVal(p));
}


int main() {
	struct my_struct* my_point = create_new_point();
	my_function(my_point);
	return 0;
}



