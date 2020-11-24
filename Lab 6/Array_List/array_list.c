/* SYSC 2006 Lab 6
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
    list->elems = malloc(sizeof(int)*capacity);
    
      for (int i=0; i<capacity; ++i)
        {
          list->elems[i] = 0;
        }
	assert(list->elems != NULL);
	assert(capacity>0);
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
    assert(list!=NULL);
    printf("[");
    for(int i=0; i<list->size;++i){ 
        printf("%d ", list->elems[i]);
    }
    printf("]");
}





_Bool intlist_append(intlist_t *list, int element)
{
	assert(list != NULL);
	if (list->size < list->capacity)
	{
		list->elems[list->size] = element;
		list->size++;
    return true;
	}
		else {
			return false;
		}
}





int intlist_capacity(const intlist_t *list)
{
	assert(list != NULL);
	int max_int = 0;
	for (int i=0; i<list->capacity; ++i){
		max_int++;
	}
	return max_int;
}





int intlist_size(const intlist_t *list)
{
	int count = 0;
	for (int i=0; i<list->size; ++i){
		++count;
	}
	return count;
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
