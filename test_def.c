#include <stdio.h>

#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hString=NULL;

	hString=my_string_init_default();

	if(hString == NULL)
	{
		my_string_destroy((Item*)&hString);
		strncpy(buffer, "test_init_default_returns_nonNULL\n"
			"my_string_init_default returns NULL", length);
		return FAILURE;
	}
	else
	{
		my_string_destroy((Item*)&hString);
		strncpy(buffer,"\ttest_init_default_returns_nonNULL", length);
		return SUCCESS;
	}
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
	MY_STRING hString=NULL;
	Status status;

	hString=my_string_init_default();

	if(my_string_get_size(hString)!=0)
	{
		status = FAILURE;
		printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
			"Did not receive 0 from get_size after init_default\n", length);
	}
	else
	{
		status=SUCCESS;
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
	}
	
	my_string_destroy((Item*)&hString);
	return status;
}

Status test_mmalone_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
	MY_STRING hString=NULL;
	Status status;

	hString=my_string_init_default();

	if(my_string_get_capacity(hString)!=7)
	{
		status = FAILURE;
		printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_mmalone_get_capacity_on_init_default_returns_7\n"
			"Did not receive 7 from get_capacity after init_default\n", length);
	}
	else
	{
		status=SUCCESS;
		strncpy(buffer, "test_get_capacity_on_init_default_returns_0\n", length);
	}
	
	my_string_destroy((Item*)&hString);
	return status;
}

Status test_mmalone_my_string_empty_after_init_default(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;
	
	hMyString = my_string_init_default();
	
	if (my_string_empty(hMyString) == 0) {
		status = FAILURE;
		printf("Expected a returned value of 1 meaning empty, but got"
		" %d\n", my_string_empty(hMyString));
		strncpy(buffer, "tests_my_string_empty_after_init_default\n"
			"Did not receive 1 from my_string_empty\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_empty_after_init_default\n", length);
	}

	my_string_destroy((Item*)&hMyString);
	return status;
}

Status test_mmalone_init_c_string_get_size(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("word");
	if (my_string_get_size(hString) != 4) {
		status = FAILURE;
		printf("Expected a size of 4 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_init_c_string_correctly_assigns_size\n"
			"Did not get a size of 4 after the init_c_string_function\n", length);
	}
	else 
	{
		status = SUCCESS;
		strncpy(buffer, "test_init_c_string_correctly_assigns_size\n", length);
	}

	my_string_destroy((Item*)&hString);
	return status;
}

Status test_mmalone_string_at_returns_nonNULL(char* buffer, int length) {
	MY_STRING hString = NULL;

	hString = my_string_init_c_string("Stringy");

	if (my_string_at(hString, 15) != NULL) {
		my_string_destroy((Item*)&hString);
		printf("Expected NULL but got %c\n", *my_string_at(hString, 15));
		strncpy(buffer, "test_my_c_str\ntest_my_c_str returns a char* to the string", length);
		return FAILURE;
	}
	else
	{
		my_string_destroy((Item*)&hString);
		strncpy(buffer, "\ntest_init_c_string_returns_nonNULL\n", length);
		return SUCCESS;
}
}

Status test_mmalone_my_string_compare(char* buffer, int length) {
	MY_STRING hLeft = NULL;
	MY_STRING hRight = NULL;

	Status status;
	hLeft = my_string_init_c_string("word");
	hRight = my_string_init_c_string("word");

	if (my_string_compare(hLeft, hRight) != 0) {
		status = FAILURE;
		printf("Expected a size of 0 but got %d\n", my_string_compare(hLeft, hRight));
		strncpy(buffer, "tests_my_string_compare\nDid not receive 0 from"
			" my_string_compare, even though the strings are the same.\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_compare\n", length);
	}
	
	my_string_destroy((Item*)&hLeft);
	my_string_destroy((Item*)&hRight);
	return status;
}

Status test_mmalone_my_string_at(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("word");
	if (*my_string_at(hString, 0) != 'w') {
		status = FAILURE;
		printf("Expected a character 'r' but got %c\n", *my_string_at(hString, 0));
		strncpy(buffer, "tests_my_string_at\n"
			"Did not get a character 'r' after the my_string_at\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_at\n", length);
	}

	my_string_destroy((Item*)&hString);
	return status;
}

Status test_mmalone_my_string_push_back(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("word");
	if (my_string_push_back(hString, 'E') != SUCCESS) {
		status = FAILURE;
		printf("Expected to get 1 Instead got: %d\n", my_string_push_back(hString, 'E'));
		strncpy(buffer, "my_string_push_back\nDid not get a 1 after the my_string_push_back\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "my_string_push_back\n", length);
	}

	my_string_destroy((Item*)&hString);
	return status;
}

Status test_mmalone_init_c_string_get_capacity(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_c_string("word");

	if (my_string_get_capacity(hString) != 5) {
		status = FAILURE;
		printf("Expected a capacity of 5 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_init_c_string_correctly_assigns_size\nDid not get "
			"a capacity of 5 after the "
			"tests_my_string_get_capacity_on_init_c_string\n", length);
	}
	else 
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_get_capacity_on_init_c_string\n", length);
	}
		my_string_destroy((Item*)&hString);
	return status;
}

Status test_mmalone_my_c_str(char* buffer, int length) {
	MY_STRING hString = NULL;
	char* myString;
	
	hString = my_string_init_c_string("word");
	myString = my_string_c_str(hString);
	
	if (myString[2] != 'r') {
		my_string_destroy((Item*)&hString);
		printf("Expected a returned value of 'r' meaning we popped back a character"
			" and decreased size, but got %c\n", myString[2]);

		strncpy(buffer, "test_my_c_str\ntest_my_c_str returns a char* to the string", length);
		return FAILURE;
	}
	else
	{
		my_string_destroy((Item*)&hString);
		strncpy(buffer, "\ntest_init_c_string_returns_nonNULL\n", length);
		return SUCCESS;
	}
}

Status test_mmalone_my_string_concat(char* buffer, int length) {
	MY_STRING hRight = NULL;
	MY_STRING hAppend = NULL;
	Status status;

	hRight = my_string_init_c_string("John");
	hAppend = my_string_init_c_string("Smith");

	if (my_string_concat(hRight, hAppend) != SUCCESS) {
		status = FAILURE;
		printf("Expected a returned value 1 but got %d\n", my_string_concat(hRight, hAppend));
		strncpy(buffer, "my_string_concat\n"
			"Did not receive 1 from my_string_concat\n", length);
	}
	else 
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_concat\n", length);
	}
	
	my_string_destroy((Item*)&hRight);
	my_string_destroy((Item*)&hAppend);
	return status;
}

Status test_mmalone_my_string_empty_after_init_c_string(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;
	
	hMyString = my_string_init_c_string("word");
	
	if (my_string_empty(hMyString) == 1) {
		status = FAILURE;
		printf("Expected a returned value of 0 but got %d\n", my_string_empty(hMyString));
		strncpy(buffer, "my_string_empty\n"
			"Did not receive 0 from my_string_empty\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_empty_after_init_c_string\n", length);
	}

	my_string_destroy((Item*)&hMyString);
	return status;
}


Status test_mmalone_init_c_string_returns_nonNULL(char* buffer, int length) {
  MY_STRING hString = NULL;
  Status status;
  
  hString = my_string_init_c_string("word");
  
  if(hString == NULL) {
    strncpy(buffer, "test_dbaumann_init_c_string_returns_nonNULL\n"
        "my_string_init_c_string returns NULL", length);
    status = FAILURE;
  }
  else
  {
    strncpy(buffer, "test_init_c_string_returns_nonNULL\n", length);
    status = SUCCESS;
  }
  
  my_string_destroy((Item*)&hString);
  return status;
}

Status test_mmalone_my_string_popback_size(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;

	hMyString = my_string_init_c_string("word");
	
	my_string_pop_back(hMyString);
	if (my_string_get_size(hMyString) != 3) {
		status = FAILURE;
		printf("Expected a returned value of 3 meaning we popped back a character"
			" and decreased size, but got %d\n", my_string_get_size(hMyString));
		strncpy(buffer, "my_string_empty\n"
			"Did not receive 4 from my_string_get_size\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_popback_and_my_string_get_size\n", length);
	}

	my_string_destroy((Item*)&hMyString);
	return status;
}

Status test_mmalone_my_string_push_back_capacity(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;
	
	hMyString = my_string_init_c_string("word");
	
	my_string_push_back(hMyString, 'E');
	if (my_string_get_capacity(hMyString) != 10) {
		status = FAILURE;
		printf("Expected a returned value of 10 meaning we successfully resized"
			" our string but got %d\n", my_string_get_capacity(hMyString));
		strncpy(buffer, "my_string_empty\n"
			"Did not receive 10 from my_string_get_capacity\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_popback_capacity\n", length);
	}

	my_string_destroy((Item*)&hMyString);
	return status;
}


Status test_mmalone_pop_back_on_empty(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;

	hMyString = my_string_init_default();

	if (my_string_pop_back(hMyString) == 1) {
		status = FAILURE;
		printf("Expected a returned value of 1 meaning we couldn't popback "
			"because its empty, but we got %d\n", my_string_empty(hMyString));
		strncpy(buffer, "tests_pop_back_on_empty\n"
			"Did not receive 1 from my_string_pop_back\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_pop_back_on_empty\n", length);
	}
	
	my_string_destroy((Item*)&hMyString);
	return status;
}

Status test_mmalone_resize_my_string_pushback(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;
	int i;

	hMyString = my_string_init_c_string("word");
	
	for (i = 0; i<100; i++) {
		my_string_push_back(hMyString, 'E');
	}

	if (my_string_get_capacity(hMyString) != 160) {
		status = FAILURE;
		printf("Expected to get a capacity of 6144 meaning we successfully "
			"resized our string but got %d\n", my_string_get_capacity(hMyString));
		strncpy(buffer, "tests_resize_feature_within_my_string_pushback\n"
			"Did not receive 12 from my_string_get_capacity\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_resize_feature_within_my_string_pushback\n", length);
	}
	
	my_string_destroy((Item*)&hMyString);
	return status;
}

Status test_mmalone_pop_back_on_my_string_object(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;
	int i;

	hMyString = my_string_init_c_string("word");
	
	for (i = 0; i < 4; i++) {
		my_string_pop_back(hMyString);
	}

	if (my_string_pop_back(hMyString) != 0) {
		status = FAILURE;
		printf("Expected a returned value of 0 meaning we couldn't popback "
			"because its empty, but we got %d\n", my_string_pop_back(hMyString));
		strncpy(buffer, "tests_loop_of_pop_back_on_my_string_object\n"
			"Did not receive 0 from my_string_pop_back\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_loop_of_pop_back_on_my_string_object\n", length);
	}
	my_string_destroy((Item*)&hMyString);
	return status;
}

Status test_mmalone_popback_and_pushback_on_init_default(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;
	
	hMyString = my_string_init_default();
	
	my_string_pop_back(hMyString);
	my_string_pop_back(hMyString);
	
	if (my_string_empty(hMyString) == 0) {
		status = FAILURE;
		printf("Expected a returned value of 0 meaning not empty, but got "
			"%d\n", my_string_empty(hMyString));
		strncpy(buffer, "my_string_empty\n"
			"Did not receive 0 from my_string_empty\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_empty_after_init_c_string\n", length);
	}

	my_string_destroy((Item*)&hMyString);
	return status;
}

Status test_mmalone_my_string_extraction_from_dictionary(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;
	
	hMyString = my_string_init_default();
	
	FILE* fp = fopen("dictionary.txt", "r");
	if (my_string_extraction(hMyString, fp) != 1) {
		status = FAILURE;
		printf("Expected a returned value of 1 meaning it successfully extracted"
			" a string, but got %d\n", my_string_extraction(hMyString, fp));
		strncpy(buffer, "test_my_string_extraction_from_dictionary\n"
			"Did not receive 0 from my_string_extraction\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_extraction_from_dictionary\n", length);
	}
	
	my_string_destroy((Item*)&hMyString);
	fclose(fp);
	return status;

}

Status test_mmalone_push_back_pushing_char_on_empty_string(char* buffer, int length) {
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if (!my_string_push_back(hString, 'A')) {
    status = FAILURE;
    strncpy(buffer, "test_mmalone_push_back_pushing_char_on_empty_string\n"
      "push_back returned failure\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_mmalone_push_back_pushing_char_on_empty_string\n",
      length);
  }
  my_string_destroy((Item*)&hString);
  return status;
}

Status test_mmalone_my_string_pushback_at_index(char* buffer, int length) {
	MY_STRING hMyString = NULL;
	Status status;
	
	hMyString = my_string_init_c_string("word");
	
	my_string_push_back(hMyString, 'E');
	if (*my_string_at(hMyString, 4) != 'E') {
		status = FAILURE;
		printf("Expected a returned value of 'U' meaning we popped back a character"
			" and decreased size, but got %c\n", *my_string_at(hMyString, 4));
		strncpy(buffer, "my_string_at\n"
			"Did not receive 4 test_my_string_pushback_at_index\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_pushback_at_index\n", length);
	}
	
	my_string_destroy((Item*)&hMyString);
	return status;
}

Status test_mmalone_my_string_compare_with_larger_left_string(char* buffer, int length) {
	MY_STRING hLeft = NULL;
	MY_STRING hRight = NULL;

	Status status;
	hLeft = my_string_init_c_string("wordEEEEEEEEEE");
	hRight = my_string_init_c_string("word");

	if (my_string_compare(hLeft, hRight) > 0) {
		status = FAILURE;
		printf("Expected a size of 1 but got %d\n", my_string_compare(hLeft, hRight));
		strncpy(buffer, "tests_my_string_compare\nDid not receive 1 from "
			"my_string_compare, even though the left string is larger.\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_compare\n", length);
	}
	
	my_string_destroy((Item*)&hLeft);
	my_string_destroy((Item*)&hRight);
	return status;
}

Status test_mmalone_my_string_compare_with_larger_right_string(char* buffer, int length) {
	MY_STRING hLeft = NULL;
	MY_STRING hRight = NULL;

	Status status;
	hLeft = my_string_init_c_string("word");
	hRight = my_string_init_c_string("wordEEEEEEEEEE");

	if (my_string_compare(hLeft, hRight) < 0) {
		status = FAILURE;
		printf("Expected a size of -1 but got %d\n", my_string_compare(hLeft, hRight));
		strncpy(buffer, "tests_my_string_compare\nDid not receive -1 from "
			"my_string_compare, even though the right string is larger.\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "tests_my_string_compare\n", length);
	}
	
	my_string_destroy((Item*)&hLeft);
	my_string_destroy((Item*)&hRight);
	return status;
}