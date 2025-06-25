#include <stdio.h>
#include <string.h>
#include "include/clist.h"

void printString(void *data)
{
    printf("%s", (char *)data);
}

int compareString(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
    CList list;
    clist_init(&list, sizeof(char[50]));

    char name1[50] = "Alice";
    char name2[50] = "Bob";
    char name3[50] = "Carol";

    clist_addLast(&list, name1);
    clist_addLast(&list, name2);
    clist_addFirst(&list, name3);

    clist_print(&list, printString); // Output: [Carol -> Alice -> Bob]

    printf("Index of 'Bob': %d\n", clist_indexOf(&list, "Bob", compareString));
    printf("List is empty? %s\n", clist_isEmpty(&list) ? "Yes" : "No");
    printf("Count: %d\n", clist_count(&list));

    clist_removeAt(&list, 1);        // Remove Alice
    clist_print(&list, printString); // Output: [Carol -> Bob]

    clist_free(&list);
    return 0;
}
