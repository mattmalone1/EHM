#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"


int main(int argc, char* argv[])
{
	char item = 'C';
	char* string_at;
	MY_STRING hMy_string1 = NULL;
	MY_STRING hMy_string2 = NULL;
	FILE* fp;

	hMy_string1 = my_string_init_default();
	hMy_string2 = my_string_init_default();
	
	fp = fopen("test.txt", "r");

	printf("extraction function:\n");

	my_string_extraction(hMy_string1, fp);

	my_string_insertion(hMy_string1, stdout);

	printf("\npush Back function:\n");

	my_string_push_back(hMy_string1, item);

	my_string_insertion(hMy_string1, stdout);

	printf("\npop back function:\n");
	
	my_string_pop_back(hMy_string1);
			
	my_string_insertion(hMy_string1, stdout);

	printf("\nmy string at- character pointed to:\n");

	string_at = my_string_at(hMy_string1, 4);

	printf("\n%c\n", string_at);

	string_at = my_string_at(hMy_string1, 12);

	printf("\nIntensional: %s\n", string_at);

	printf("\nMy string c string: ");

	string_at = my_string_c_str(hMy_string1);

	printf("%s\n", string_at);

	my_string_extraction(hMy_string2, fp);

	printf("Concatinate function:\n");

	my_string_concat(hMy_string1, hMy_string2);

	my_string_insertion(hMy_string1, stdout);

	printf("\nMy string empty? Boolean value=%d\n", my_string_empty(hMy_string1));

	my_string_destroy(&hMy_string1);
	my_string_destroy(&hMy_string2);
	fclose(fp);
	return 0;
}