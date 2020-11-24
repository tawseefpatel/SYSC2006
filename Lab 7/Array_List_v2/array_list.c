/* SYSC 2006 Lab 6 & 7
 *
 * array_list.c 
 *
 * Prototype of a dynamically allocated, fixed-capacity list that supports a 
 * subset of the operations provided by Python's list class.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array_list.h"

intlist_t *intlist_construct(int capacity)
{
	intlist_t *list = malloc(sizeof(intlist_t));
	list->capacity = capacity;
	list->size = 0;
	list->elems = malloc(sizeof(int) * capacity);

	/* set all values in array to 0
	   for (int i=0; i<capacity; ++i)
	   {
	   list->elems[i] = 0;
	   } 
	*/
	assert(list->elems != NULL);
	assert(capacity > 0);
	return list;
}





void intlist_destroy(intlist_t *list)
{
	assert(list != NULL);
	free(list->elems);
	free(list);
}





void intlist_print(const intlist_t *list)
{
	assert(list != NULL);
	printf("[");
	for (int i = 0; i < list->size; ++i)
	{
		if (i + 1 == list->size)
		{
			printf("%d", list->elems[i]);
		}
		else
		{
			printf("%d ", list->elems[i]);
		}
	}
	printf("]");
}





//lab 7 ex 5
_Bool intlist_append(intlist_t *list, int element)
{
	assert(list != NULL);
	if (list->size == list->capacity)
	{
		list->capacity *= 2;
	}
	if (list->size < list->capacity)
	{
		list->elems[list->size] = element;
		list->size++;
		return true;
	}
	else
	{
		return false;
	}
}





int intlist_capacity(const intlist_t *list)
{
	assert(list != NULL);
	return list->capacity;
}





int intlist_size(const intlist_t *list)
{
	assert(list != NULL);
	return list->size;
}





int intlist_get(const intlist_t *list, int index)
{
	assert(list != NULL);
	int val = list->elems[index];
	return val;
}





int intlist_set(intlist_t *list, int index, int element)
{
	assert(list != NULL);
	assert(index < list->size);
	int old_index_val = list->elems[index];
	list->elems[index] = element;
	return old_index_val;
}





void intlist_removeall(intlist_t *list)
{
	assert(list != NULL);
	list->size = 0;
}





//Lab 7
//Exercise 1
int intlist_index(const intlist_t *list, int target)
{
	assert(list != NULL);
	for (int i = 0; i < list->size; i++)
	{
		if (list->elems[i] == target)
		{
			return i;
		}
	}
	return -1;
}





int intlist_count(const intlist_t *list, int target)
{
	assert(list != NULL);
	int count = 0;
	for (int i = 0; i < list->size; ++i)
	{
		if (list->elems[i] == target)
		{
			++count;
		}
	}
	return count;
}





_Bool intlist_contains(const intlist_t *list, int target)
{
	assert(list != NULL);
	for (int i = 0; i < list->size; ++i)
	{
		if (list->elems[i] == target)
		{
			return true;
		}
	}
	return false;
}





void increase_capacity(intlist_t *list, int new_capacity)
{
	assert(list != NULL);
	assert(new_capacity > list->capacity);
	list->capacity = new_capacity;

	int *elems2 = malloc(sizeof(int) * list->capacity);
	assert(elems2 != NULL);
	for (int i = 0; i < list->size; ++i)
	{
		elems2[i] = list->elems[i];
	}
	free(list->elems);
	list->elems = elems2;
}





void intlist_delete(intlist_t *list, int index)
{
	assert(list != NULL);
	assert(index < list->size);

	while (index < list->size - 1)
	{
		list->elems[index] = list->elems[index + 1];
		++index;
	}
	--list->size;
}
