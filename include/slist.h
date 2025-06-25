#ifndef SLIST_H
#define SLIST_H

#include <stdbool.h>

typedef struct SNode
{
    char *data;
    struct SNode *next;
} SNode;

typedef struct
{
    SNode *head;
} SList;

void slist_init(SList *list);
bool slist_isEmpty(SList *list);
void slist_addFirst(SList *list, const char *str);
void slist_addLast(SList *list, const char *str);
bool slist_removeAt(SList *list, int index);
int slist_indexOf(SList *list, const char *str);
void slist_print(SList *list);
int slist_count(SList *list);
void slist_free(SList *list);

#endif // SLIST_H
