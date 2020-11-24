/* SYSC 2006 Lab 8
   A module that implements a singly-linked list of integers. 
 */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "singly_linked_list.h"

/*************************************************************
 * Functions presented in lectures.
 *************************************************************/

/* Return a pointer to a new intnode_t (a node in a singly-linked list).

   Parameter value: the integer to be stored in the node.
   Parameter next: a pointer to the node that the new node should point to.
   This pointer should be NULL if the new node is the last node in the 
   linked list.
   Terminate (via assert) if memory for the node cannot be allocated.
 */ 
intnode_t *intnode_construct(int value, intnode_t *next)
{
    intnode_t *p = malloc(sizeof(intnode_t));
    assert (p != NULL);
    p->value = value;
    p->next = next;
    return p;
}
/* Parameter head points to the first node in a linked list, or is NULL
   if the linked list is empty. Insert a node containing the specified 
   integer value at the front of the linked list, and return a pointer to 
   the first node in the modified list.
 */
intnode_t *push(intnode_t *head, int value)
{
    return intnode_construct(value, head);
}

/* Parameter head points to the first node in the list.
   Return the length of a linked list (0 if the linked list is empty). 
 */
int length(intnode_t *head)
{
    int count = 0;
    for (intnode_t * curr = head; curr != NULL; curr = curr->next) {
        count += 1;
    }
    return count;
}

/* Parameter head points to the first node in a linked list.
   Print the linked list, using the format:
       value1 -> value2 -> value3 -> ... -> last_value
 */
void print_list(intnode_t *head)
{
    if (head == NULL) {
        printf("empty list");
        return; 
    }

    intnode_t *curr;

    /* The loop prints a every node in the linked list except the last one,
       using the format "value -> ", where "->" represents the link from each node
       to the following node.

       Notice that the loop condition is:
           curr->next != NULL
       and not:
           curr != NULL

       During the last iteration, the value in the second-last node is
       printed, then curr is updated to point to the last node. The
       condition curr->next != NULL now evaluates to false, so the 
       loop exits, with curr pointing to the last node (which has  
       not yet been printed.) 
     */

    for (curr = head; curr->next != NULL; curr = curr->next) {
        printf("%d -> ", curr->value);
    }

    /* Print the last node. */
    printf("%d", curr->value);
}



/*****************************************************************
 * Solutions to Lab 8
 *****************************************************************/

// Exercise 1
int count(intnode_t *head, int target)
{
	int numTimes = 0;
	while(head!=NULL)
	{
		if (head->value == target)
		{
			numTimes++;
		}
	head= head->next;
	}
	return numTimes;
}





// Exercise 2
int max(intnode_t *head)
{
    int max = head->value;
	while(head!=NULL)
	{
		if (head->value > max)
		{
			max = head->value;
		}
	head = head->next;
	}
	return max;
}





// Exercise 3
int index(intnode_t *head, int target)
{
	int pos = 0;
	while(head!=NULL)
	{
		if (head->value == target)
		{
			return pos;
		}
		else 
		{
			pos++;
		}
	head = head->next;
	}
	return -1;
}





// Exercise 4
void extend(intnode_t *head, intnode_t *other)
{
	assert(head!=NULL);
	while(head->next!=NULL)
	{
		head = head->next;
	}
	head->next = other;
}





// Exercise 5
intnode_t *pop(intnode_t *head, int *popped_value)
{
	assert(head!=NULL);
	*popped_value = head->value;
	intnode_t *new_head = head->next;
	free(head);
	return new_head;
}

