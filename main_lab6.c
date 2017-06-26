#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"


int main(int argc, char* argv[])
{
	int i, j;

	// mallocate memory
	MY_STRING array[100] = {NULL};

	array[0] = my_string_init_c_string("COPY ME!");

	// Use this assignment to populate every other element.
	for(i = 2; i < 100; i = i+2)
	{
		my_string_assignment(&array[i], array[0]);
	}
	// This for loop prints the element then releases the memory used.
	for (i = 0, j = 0; i < 100; i+=2, j++) {
		printf("%d ", j);
    	my_string_insertion(array[i], stdout);
    	printf("\n");
    	my_string_destroy(&array[i]);
}

	return 0;
}