// clist.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/clist.h"

#pragma region Initialization

void clist_init(CList *list, size_t dataSize)
{
    list->head = NULL;
    list->dataSize = dataSize;
}

bool clist_isEmpty(CList *list)
{
    return list->head == NULL;
}

#pragma endregion

#pragma region Insertion

void clist_addFirst(CList *list, void *data)
{
    CNode *newNode = (CNode *)malloc(sizeof(CNode));
    if (!newNode)
        return;

    newNode->data = malloc(list->dataSize);
    if (!newNode->data)
    {
        free(newNode);
        return;
    }

    memcpy(newNode->data, data, list->dataSize);
    newNode->next = list->head;
    list->head = newNode;
}

void clist_addLast(CList *list, void *data)
{
    CNode *newNode = (CNode *)malloc(sizeof(CNode));
    if (!newNode)
        return;

    newNode->data = malloc(list->dataSize);
    if (!newNode->data)
    {
        free(newNode);
        return;
    }

    memcpy(newNode->data, data, list->dataSize);
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        CNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

#pragma endregion

#pragma region Removal

bool clist_removeAt(CList *list, int index)
{
    if (index < 0 || list->head == NULL)
        return false;

    CNode *current = list->head;

    if (index == 0)
    {
        list->head = current->next;
        free(current->data);
        free(current);
        return true;
    }

    for (int i = 0; i < index - 1; i++)
    {
        if (current == NULL || current->next == NULL)
            return false;
        current = current->next;
    }

    CNode *toDelete = current->next;
    if (toDelete == NULL)
        return false;

    current->next = toDelete->next;
    free(toDelete->data);
    free(toDelete);
    return true;
}

#pragma endregion

#pragma region Search

int clist_indexOf(CList *list, void *data, int (*cmp)(void *, void *))
{
    CNode *current = list->head;
    int index = 0;

    while (current != NULL)
    {
        if (cmp(current->data, data) == 0)
        {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1; // Not found
}

#pragma endregion

#pragma region Utilities

void clist_print(CList *list, void (*printFunc)(void *))
{
    CNode *current = list->head;
    printf("[");
    while (current != NULL)
    {
        printFunc(current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("]\n");
}

int clist_count(CList *list)
{
    int count = 0;
    CNode *current = list->head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void clist_free(CList *list)
{
    CNode *current = list->head;
    while (current != NULL)
    {
        CNode *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
}
#pragma endregion
