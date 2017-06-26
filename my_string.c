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
// String is not NULL terminated so his doesn't work.
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
	int i;
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

		for (i = 0; i < pStr->capacity; i++) {
			pStr->data[i] = c_string[i];
		}
	}
	return pStr;
}

// Precondition: hMy_string is the handle of a valid My_string object.
// Postcondition: Returns a copy of the integer value of the object's capacity.

int my_string_get_capacity(MY_STRING hMy_string)
{
	My_String* pStr = (My_String*)hMy_string;

	if (pStr == NULL)
		return 0;
	else
		return pStr->capacity;
}

// Precondition: hMy_string is the handle of a valid My_string object.
// Postcondition: Returns a copy of the integer value of the object's size.

int my_string_get_size(MY_STRING hMy_string)
{
	My_String* pStr = (My_String*)hMy_string;

	if (pStr == NULL)
		return 0;
	else
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
	My_String* pLeft = (My_String*)hLeft_string;
	My_String* pRight = (My_String*)hRight_string;

	int i;
	for (i = 0; i < pLeft->size && i < pRight->size; i++) {
		if (pLeft->data[i] < pRight->data[i]) {
			return -1;
			break;
		}
		else if (pLeft->data[i] > pRight->data[i]) {
			return 1;
			break;
		}
}
	return 0;
}

// Precondition: phMy_string holds the address of a valid handle to a MY_STRING
//  object.
// Postcondition: The memory used fo the MY_STRING object has be reclaimed by
//  the system and the handle referred to by the pointer phMy_string has been
//  set to NULL.

void my_string_destroy(Item* phMy_string)
{
	My_String* pStr = (My_String*)*phMy_string;
	
	free(pStr->data);
	pStr->data = NULL;

	free(pStr);
	pStr = NULL;
	*phMy_string = NULL;
}

/* resize the string capacity to twice the size. This set of code is 
	repetitive so for efficiency sake it is better to make it its
	own function.  */

void my_resize(My_String* pStr)
{
	char* temp;
	int i;

	temp = (char*)malloc(sizeof(char) * 2 * pStr->capacity);
		if (temp == NULL) {
			free(temp);
			return;
		}

		// copy to new array previously in data
		for (i = 0; i < pStr->capacity; i++) {
			temp[i] = pStr->data[i];
		}
		// free old data
		free(pStr->data); 
		pStr->data = NULL;

		// make temp memory equal to data
		pStr->data = temp;
		temp = NULL;
		pStr->capacity *= 2;  // adjust size of capacity
		return;
}

// Precondition: hMy_string is the handle to a valid My_string object.

//Postcondition: hMy_string will be the handle of a string object that contains
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
// This code is adapted from:
// https://github.com/DPC15038/Evil-Hangman/blob/master/my_string.c

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) 
{
	int num_of_conversions, count = 0;
	char c;
	
	My_String* pStr = (My_String*)hMy_string;

	num_of_conversions = fscanf(fp, " %c", &c);

	// check the returned items
	if (num_of_conversions == 1 && num_of_conversions != EOF) 
	{
		// stop conditions
		while (c != ' ' && c != EOF && c != '\n') 
		{
			pStr->data[count] = c;
			pStr->size = count + 1;
			count++;

			// resize when capacity equals size
			if (pStr->capacity <= pStr->size) 
			{
				my_resize(pStr);
				if (pStr->data == NULL) {
					return FAILURE;
				}

			}
			// get next character
			c = fgetc(fp);
		}
		// put the end condition data back into fp
		ungetc(c, fp);
		return SUCCESS;
	}
	return FAILURE;
}

// Precondition: hMy_string is the handle to a valid My_string object.
// Postcondition: Writes the characters contained in the string object indicated
// by the handle hMy_string to the file stream  fp.
// Function will return SUCCESS if it successfully writes the string and
// FAILURE otherwise.
Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	My_String* pStr = (My_String*)hMy_string;
	int i;

	// print the character stored in data
	for(i = 0; i < pStr->size; i++)
	{
		fprintf(fp, "%c", pStr->data[i]);
	}

	return SUCCESS;
}

// Precondition: hMy_string is the handle to a valid My_string object.
// Postcondition: If successful, places the character item at the end of the 
// string and returns SUCCESS. If the string does not have enough room and
// cannot resize to accomidate the new character then the operation fails
// and FAILURE is returned. The resize operation will attempt to amortize
// the cost of a resize by making the string capacity somewhat larger than
// it was before (up to 2 times bigger).

Status my_string_push_back(MY_STRING hMy_string, char item)
{
	My_String* pStr = (My_String*)hMy_string;

	if (pStr->capacity <= (pStr->size+1)) 
	{
		my_resize(pStr);
		if (pStr->data == NULL) {
			return FAILURE;
		}
	}

	pStr->size = pStr->size+1;

	pStr->data[pStr->size-1] = item;

	return SUCCESS;
}

// Precondition: hMy_string is the handle to a valid My_string object.
// Postcondition: Removes the last character of a string in constant time.
// Guarenteed to not cause a resize operation of the internal data. Returns
// SUCCESS on success and FAILURE if the string is empty.

Status my_string_pop_back(MY_STRING hMy_string)
{
	My_String* pStr = (My_String*)hMy_string;

	if(pStr->size == 0)
	{
		return FAILURE;
	}
	pStr->size = pStr->size-1;
	return SUCCESS;
}

// Precondition: hMy_string is the handle to a valid My_string object.
// Postcondition: Returns the address of the character located at the given
// index if the index is in bounds but otherwise returns NULL. This address
// is not usable as a c-string since the data is not NULL terminated and is
// intended to just provide access to the element at that index.

char* my_string_at(MY_STRING hMy_string, int index)
{
	My_String* pStr = (My_String*)hMy_string;

	if(index > pStr->size-1 || index < 0)
		return NULL;
	else
		return &pStr->data[index];
}

// Precondition: hMy_string is the handle to a valid My_string object.
// Postcondition: Returns the address of the first element of the string object
// for use as a c-string. The resulting c-string is guarenteed to be NULL
// terminated and the memory is still maintained by the string object through
// the NULL is not actually counted as part of the string (in size).

char* my_string_c_str(MY_STRING hMy_string)
{
	My_String* pStr = (My_String*)hMy_string;

	if(pStr->size+1 >= pStr->capacity)
	{
		my_resize(pStr);
			if (pStr->data == NULL) {
				return FAILURE;
			}

	}
	if(pStr->size == 0)
		return NULL;

	pStr->data[pStr->size] = '\0';

	return pStr->data;
}

// Precondition: hResult and hAppend are handles to valid My_string objects.
// Postcondition: hResult is the handle of a string that containsthe original
// hResult object followed by the hAppend object concatinated together. This
// function should guarentee no change to the hAppend object and return
// SUCCESS if they operaion is successful and FAILURE if the hResult object
// is unable to accomidate the characters in the hAppend string perhaps
// because of a failed resize operation. On FAILURE, no change to either
// string should be made.

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	char* temp;
	int i, j;
	// cast the void pointers into something usable.
	My_String* pStr1 = (My_String*)hResult;
	My_String* pStr2 = (My_String*)hAppend;

	// Allocate new memory
	temp = (char*)malloc(sizeof(char)*((pStr1->size)+(pStr2->size)));
	if (temp == NULL) {
		free(temp);
		return FAILURE;
	}
	pStr1->capacity = ((pStr1->size)+(pStr2->size));
	
	// copy data from the two strings into temp
	for(i = 0; i < pStr1->size; i++)
	{
		temp[i] = pStr1->data[i];
	}
	for(j = 0; j < pStr2->size; j++, i++)
	{
		temp[i] = pStr2->data[j];
	}

	// Set the cleanup data
	free(pStr1->data);
	pStr1->data = temp;
	pStr1->size = i;

	//printf("\n%d", pStr1->size);

	return SUCCESS;

}

// Precondition: hMy_string is the handle to a valid My_string object.
// Postcondition: Returns an enumerated type with value TRUE if the string
// is empty and FALSE otherwise.

Boolean my_string_empty(MY_STRING hMy_string)
{
	My_String* pStr = (My_String*)hMy_string;

	if(pStr == NULL || pStr->size == 0)
		return TRUE;
	else
		return FALSE;
}

void my_string_assignment(Item* pLeft, Item Right)
{
	My_String* pMy_Left = (My_String*)*pLeft;
	My_String* pMy_Right = (My_String*)Right;
	int i;
	const char* temp;

	temp = my_string_c_str((MY_STRING)Right);
	if (pMy_Left == NULL) {
		pMy_Left = my_string_init_c_string(temp);
	}
	else {
		pMy_Left->size = 0;
		for (i = 0; i < pMy_Right->size + 1; i++) {
			my_string_push_back(pMy_Left, pMy_Right->data[i]);
		}
	}
	*pLeft = pMy_Left;
}
