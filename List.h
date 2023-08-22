#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

typedef struct node{
    struct node *Next;
    uint32 Data;
}ListNode;

typedef struct List{
    ListNode *Head;
    uint32 Size;
}List;

typedef enum{
    LIST_OK = 0,
    LIST_NOK,
    LIST_INVALID,
    LIST_EMPTY,
    LIST_NULL,
}List_Status;


List_Status ListCreate(List *plist);
List_Status ListDestroy(List *plist);

List_Status ListInsertAtBeginning(List *plist, uint32 Value);
List_Status ListInsertEnd(List *plist, uint32 Value);
List_Status ListInsertIn(List *plist, uint32 Value, uint32 pos);

uint32 ListDeleteAtBeginning(List *plist, List_Status *status);
uint32 ListDelete(List *plist, uint32 pos, List_Status *status);

uint32 ListLength(List *plist, List_Status *status);

List_Status ListTraverse(List *plist, void(*pf)(uint32));


#endif // LIST_H
