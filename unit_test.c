#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
	Status (*tests[])(char*,int)=
	{
		test_init_default_returns_nonNULL,						//1
		test_get_size_on_init_default_returns_0,				//2
		test_mmalone_get_capacity_on_init_default_returns_7,	//3
		test_mmalone_my_string_empty_after_init_default,		//4
		test_mmalone_init_c_string_get_size,					//5
		test_mmalone_string_at_returns_nonNULL,					//6
		test_mmalone_my_string_compare,							//7
		test_mmalone_my_string_at,								//8
		test_mmalone_my_string_push_back,						//9
		test_mmalone_init_c_string_get_capacity,				//10
		test_mmalone_my_c_str,									//11
		test_mmalone_my_string_concat,							//12
		test_mmalone_my_string_empty_after_init_c_string,		//13
		test_mmalone_init_c_string_returns_nonNULL,				//14
		test_mmalone_my_string_popback_size,					//15
		test_mmalone_my_string_push_back_capacity,				//16
		test_mmalone_pop_back_on_empty,							//17
		test_mmalone_resize_my_string_pushback,					//18
		test_mmalone_pop_back_on_my_string_object,				//19
		test_mmalone_popback_and_pushback_on_init_default,		//20
		test_mmalone_my_string_extraction_from_dictionary,		//21
		test_mmalone_push_back_pushing_char_on_empty_string,	//22
		test_mmalone_my_string_pushback_at_index,				//23
		test_mmalone_my_string_compare_with_larger_left_string,	//24
		test_mmalone_my_string_compare_with_larger_right_string	//25
	};

int number_of_functions=sizeof(tests)/sizeof(tests[0]);
int i;
char buffer[500];
int success_count=0;
int failure_count=0;

printf("number of functions: %d\n", number_of_functions);

for(i=0; i < number_of_functions; i++)
{
	if(tests[i](buffer,500)==FAILURE)
	{
		printf("FAILED: Test %d failed miserably\n", i);
		printf("\t%s\n",buffer);
		failure_count++;
	}else{
			// printf("PASS: Test %d passed\n",i);
			// printf("\t%s\n",buffer);
		success_count++;
	}
}

printf("Total number of tests: %d\n", number_of_functions);
printf("%d/%d Pass, %d/%d Failure\n", success_count,
	number_of_functions, failure_count, number_of_functions);

return 0;
}