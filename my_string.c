#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"

struct my_string {
	char* data;
	int size;
	int capacity;
};
typedef struct my_string My_String;
// Precondition: None
// Postcondition: Allocate space for a string object that represents the empty
//  string.  The string will have capacity 7 and size 0 by default. A copy of
//  the address of the opaque object will be returned on success and NULL on
//  failure.

MY_STRING my_string_init_default(void)
{
	My_String* pStr;
	pStr = (My_String*)malloc(sizeof(My_String));

	if (pStr != NULL)
	{
		pStr->size = 0;
		pStr->capacity = 7;
		pStr->data = (char*)(malloc(sizeof(char)*pStr->capacity));
		if(pStr->data == NULL)
		{
			free(pStr);
			pStr = NULL;
		}

	}
	return pStr;
}

/* My version of a sizing function that returns how long a string is
	The folloing code is based on code from The C Programming Language
	by Kernighan and Ritchie	*/
int string_size(const char* string)
{
	const char *temp = string;

	while (*temp != '\0')
		temp++;
	return temp - string;
}


// Precondition: c_string is a valid null terminated c-string.
// Postcondition: Allocate space for a string object that represents a string
// with the same value as the given c-string. The capacity of the string
// object will be set to be one greater than is required to hold the string.
// As an example, the string "the" would set capacity at 4 instead of 3. A
// copy of the address of the opaque object will be returned on success and
// NULL on failure.

MY_STRING my_string_init_c_string(const char* c_string)
{

	My_String* pStr;
	pStr = (My_String*)malloc(sizeof(My_String));

	if (pStr != NULL)
	{
		pStr->size = string_size(c_string);
		pStr->capacity = pStr->size+1;
		pStr->data = (char*)malloc(sizeof(char)*pStr->capacity);
		if(pStr->data == NULL)
		{
			free(pStr);
			pStr = NULL;
		}
	}
	return pStr;
}

// Precondition: hMy_string is the handle of a valid My_string object.
// Postcondition: Returns a copy of the integer value of the object's capacity.

int my_string_get_capacity(MY_STRING hMy_string)
{
	My_String* pStr = (My_String*)hMy_string;
	return pStr->capacity;
}

// Precondition: hMy_string is the handle of a valid My_string object.
// Postcondition: Returns a copy of the integer value of the object's size.

int my_string_get_size(MY_STRING hMy_string)
{
	My_String* pStr = (My_String*)hMy_string;
	return pStr->size;
}

// Precondition: hLeft_string and hRight_string are valid My_string objects.
// Postcondition: returns an integer less than zero if the string represented
// by hLeft_string is lexicographically smaller than hRight_string. If
// one string is a prefix of the other string then the shorter string is
// considered to be the smaller one. (app is less than apple). Returns
// 0 if the strings are the same and returns a number greater than zero
// if the string represented by the hLeft_string is bigger than the hRight_string.

/*	The folloing code is based on code from The C Programming Language
	by Kernighan and Ritchie	*/

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	char* pLeft = (char*)hLeft_string;
	char* pRight = (char*)hRight_string;

	for( ; *pLeft == *pRight; pLeft++, pRight++)
	{
		if (*pLeft == '\0')
		{
			return 0;
		}
	}
		return *pLeft - *pRight;
}

// Precondition: phMy_string holds the address of a valid handle to a MY_STRING
//  object.
// Postcondition: The memory used fo the MY_STRING object has be reclaimed by
//  the system and the handle referred to by the pointer phMy_string has been
//  set to NULL.

void my_string_destroy(MY_STRING* phMy_string)
{
	My_String* pStr = (My_String*)*phMy_string;
	free(pStr->data);
	free(pStr);
	*phMy_string = NULL;
}

// Precondition: hMy_string is the handle to a valid My_string object.

// Postcondition: hMy_string will be the handle of a string object that contains
// the next string from the file stream fp according to the following rules.

// 1) Leading whitespace will be ignored.

// 2) All characters (after the first non-whitespace character is obtained
//   and included) will be added to the string until a stoping condition
//   is met. The capacity of the string will continue to grow as needed
//   until all characters are stored.

// 3) A stopping condition is met if we read a whitespace character after
//   we have read at least one non-whitespace character or if we reach
//   the end of the file.

// Function will return SUCCESS if a non-empty string is read successfully.
// and failure otherwise. Remember that the incoming string may already
// contain some data and this function should replace the data but not
// necessarily resize the array unless needed.

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{

	char c;
	int j, actualChar; 
	int i = 0;

	My_String* pStr = (My_String*)hMy_string;

	// overwrite the characters already present to reset.
	for(j = 0; j < pStr->size+2; j++)
	{
		pStr->data[j] = '\0';
	} 

	// reset the size pointer
	pStr->size = 0;
	j = 0;
	// Do nothing with leading white space
	while((c = fgetc(fp)) != EOF)
	{
		// test for the first alphanumeric character
		if( isalpha(c) )
		{
			actualChar = 1; // determine when we have characters
		}

		// This goes through the characters and the size.
		if( actualChar == 1 )
		{
			pStr->data[i] = c;
			//printf("%s", pStr->data);
			
			// adjust the size of each word
			pStr->size = pStr->size+1;
		
		}
		
		// resize if size equals capacity
		if(pStr->size >= pStr->capacity)
		{
			pStr->data = (char*)realloc(pStr->data, sizeof(char)*2*pStr->capacity);
			if(pStr->data == NULL)
			{
				return FAILURE;
			}
			pStr->capacity = pStr->capacity * 2;
		
		}

		// handle blank space characters
		if( actualChar == 1 &&  (c == ' ') )
		{
			ungetc(c, fp); 	// return the character to fp
			pStr->size = pStr->size-1;	// account for the last character

			return SUCCESS;
		}

	}
	printf("%s", pStr->data);

	return SUCCESS;
}


// Precondition: hMy_string is the handle to a valid My_string object.
// Postcondition: Writes the characters contained in the string object indicated
// by the handle hMy_string to the file stream  fp.
// Function will return SUCCESS if it successfully writes the string and
// FAILURE otherwise.
Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	My_String* pStr = (My_String*)hMy_string;

	printf("%s", pStr->data);
	//fputs(pStr->data, fp);

	return SUCCESS;
}