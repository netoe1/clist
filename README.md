# clist - Generic Singly Linked List in C

`clist` is a simple and generic singly linked list implementation in C that supports storing any type of data using `void*` pointers. It provides common list operations with customizable data handling through user-defined comparison and print functions.

---

## Features

- Generic data storage using `void*` and data size for safe copying
- Insert elements at the beginning or end of the list
- Remove element by index
- Search for element index with custom comparator
- Print list elements with custom print function
- Check if list is empty
- Count number of elements
- Proper memory management with free

---

## Usage

Include `clist.h` and link `clist.c` in your project.

---

## API Functions

### `void clist_init(CList* list, size_t dataSize)`

Initializes the list structure.

- `list`: pointer to the list to initialize
- `dataSize`: size in bytes of the data type to be stored (e.g., `sizeof(int)` or `sizeof(char[50])`)

---

### `bool clist_isEmpty(CList* list)`

Returns `true` if the list is empty, `false` otherwise.

---

### `void clist_addFirst(CList* list, void* data)`

Adds a copy of `data` to the **beginning** of the list.

---

### `void clist_addLast(CList* list, void* data)`

Adds a copy of `data` to the **end** of the list.

---

### `bool clist_removeAt(CList* list, int index)`

Removes the element at the given `index`.  
Returns `true` if successful, `false` if the index is invalid.

---

### `int clist_indexOf(CList* list, void* data, int (*cmp)(void*, void*))`

Returns the index of the first element that matches `data` according to the comparator function `cmp`.  
Returns `-1` if not found.

- `cmp` is a pointer to a comparison function that returns 0 if elements are equal, similar to `strcmp`.

---

### `void clist_print(CList* list, void (*printFunc)(void*))`

Prints the entire list by calling `printFunc` on each element.

- `printFunc` is a pointer to a function that prints a single element.

---

### `int clist_count(CList* list)`

Returns the number of elements currently in the list.

---

### `void clist_free(CList* list)`

Frees all nodes and their data from the list and resets it to empty.

---

## Example

```c
#include <stdio.h>
#include <string.h>
#include "clist.h"

void printString(void* data) {
    printf("%s", (char*)data);
}

int compareString(void* a, void* b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    CList list;
    clist_init(&list, sizeof(char[50]));

    char name1[50] = "Alice";
    char name2[50] = "Bob";
    char name3[50] = "Carol";

    clist_addLast(&list, name1);
    clist_addLast(&list, name2);
    clist_addFirst(&list, name3);

    clist_print(&list, printString);  // Output: [Carol -> Alice -> Bob]

    printf("Index of 'Bob': %d\n", clist_indexOf(&list, "Bob", compareString));
    printf("List is empty? %s\n", clist_isEmpty(&list) ? "Yes" : "No");
    printf("Count: %d\n", clist_count(&list));

    clist_removeAt(&list, 1); // Remove Alice
    clist_print(&list, printString); // Output: [Carol -> Bob]

    clist_free(&list);
    return 0;
}


# Enjoy, by NEWCORP.ltda
```
