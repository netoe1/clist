#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/slist.h"

void slist_init(SList *list)
{
    list->head = NULL;
}

bool slist_isEmpty(SList *list)
{
    return list->head == NULL;
}

void slist_addFirst(SList *list, const char *str)
{
    SNode *newNode = malloc(sizeof(SNode));
    if (!newNode)
        return;

    // Allocate string dynamically, exact length + 1 for '\0'
    newNode->data = malloc(strlen(str) + 1);
    if (!newNode->data)
    {
        free(newNode);
        return;
    }
    strcpy(newNode->data, str);

    newNode->next = list->head;
    list->head = newNode;
}

void slist_addLast(SList *list, const char *str)
{
    SNode *newNode = malloc(sizeof(SNode));
    if (!newNode)
        return;

    newNode->data = malloc(strlen(str) + 1);
    if (!newNode->data)
    {
        free(newNode);
        return;
    }
    strcpy(newNode->data, str);
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        SNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool slist_removeAt(SList *list, int index)
{
    if (index < 0 || list->head == NULL)
        return false;

    SNode *current = list->head;

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

    SNode *toDelete = current->next;
    if (toDelete == NULL)
        return false;

    current->next = toDelete->next;
    free(toDelete->data);
    free(toDelete);
    return true;
}

int slist_indexOf(SList *list, const char *str)
{
    SNode *current = list->head;
    int index = 0;

    while (current != NULL)
    {
        if (strcmp(current->data, str) == 0)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void slist_print(SList *list)
{
    SNode *current = list->head;
    printf("[");
    while (current != NULL)
    {
        printf("\"%s\"", current->data);
        if (current->next != NULL)
            printf(" -> ");
        current = current->next;
    }
    printf("]\n");
}

int slist_count(SList *list)
{
    int count = 0;
    SNode *current = list->head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void slist_free(SList *list)
{
    SNode *current = list->head;
    while (current != NULL)
    {
        SNode *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
}
