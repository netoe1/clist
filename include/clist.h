// clist.h

#ifndef CLIST_H
#define CLIST_H

#include <stdbool.h>
#include <stddef.h> // for size_t

// Node structure for generic data
typedef struct CNode
{
    void *data;
    struct CNode *next;
} CNode;

// Linked list structure
typedef struct
{
    CNode *head;
    size_t dataSize;
} CList;

// Function declarations

/**
 * Initializes the list with the size of the element type.
 */
void clist_init(CList *list, size_t dataSize);

/**
 * Checks if the list is empty.
 */
bool clist_isEmpty(CList *list);

/**
 * Adds an element to the beginning of the list.
 */
void clist_addFirst(CList *list, void *data);

/**
 * Adds an element to the end of the list.
 */
void clist_addLast(CList *list, void *data);

/**
 * Removes the element at the specified index.
 * Returns true if successful, false if index is invalid.
 */
bool clist_removeAt(CList *list, int index);

/**
 * Returns the index of the first element equal to the given data.
 * Uses the provided comparison function.
 * Returns -1 if not found.
 */
int clist_indexOf(CList *list, void *data, int (*cmp)(void *, void *));

/**
 * Prints all elements using the provided print function.
 */
void clist_print(CList *list, void (*printFunc)(void *));

/**
 * Returns the number of elements in the list.
 */
int clist_count(CList *list);

/**
 * Frees all memory used by the list.
 */
void clist_free(CList *list);
#endif // CLIST_H
