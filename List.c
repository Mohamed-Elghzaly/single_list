#include "List.h"


List_Status ListCreate(List *plist){
    List_Status status = LIST_NOK;
    if(NULL == plist){
        status = LIST_NULL;
    }
    else{
        plist->Head = NULL;
        plist->Size = 0;
        status = LIST_OK;
    }
    return status;
}


List_Status ListInsertAtBeginning(List *plist, uint32 Value){
    ListNode *pnode = (ListNode *)malloc(sizeof(ListNode));
    List_Status status = LIST_NOK;
    if((NULL == plist) || (NULL == pnode)){
        status = LIST_NULL;
    }
    else{
            pnode->Data = Value;
            pnode->Next = plist->Head;
            plist->Head = pnode;
            (plist->Size)++;
            status = LIST_OK;
    }
    return status;
}


List_Status ListInsertEnd(List *plist, uint32 Value){
    ListNode *pnode = (ListNode *)malloc(sizeof(ListNode));
    ListNode *TempNode = plist->Head;
    uint32 TempSize = plist->Size;
    List_Status status = LIST_NOK;

    if((NULL == plist) || (NULL == pnode)){
        status = LIST_NULL;
    }
    else{
        while(TempSize-1 > 0){
            TempNode = TempNode->Next;
            TempSize--;
        }
        pnode->Data = Value;
        TempNode->Next = pnode;
        pnode->Next = NULL;
        (plist->Size)++;
        status = LIST_OK;
    }
    return status;
}


List_Status ListInsertAfter(List *plist, uint32 Value, uint32 pos){
    ListNode *pnode = (ListNode *)malloc(sizeof(ListNode));
    ListNode *TempNode = plist->Head;
    List_Status status = LIST_NOK;

    if((NULL == plist) || (NULL == pnode)){
        status = LIST_NULL;
    }
    else{
        if(pos-1 > plist->Size){
            status = LIST_INVALID;
        }
        else{
            if(pos == 1){
                pnode->Data = Value;
                pnode->Next = plist->Head;
                plist->Head = pnode;
                (plist->Size)++;
            }
            else{
                while(pos-2 > 0){
                    TempNode = TempNode->Next;
                    pos--;
                }
                pnode->Data = Value;
                pnode->Next = TempNode->Next;
                TempNode->Next = pnode;
                (plist->Size)++;
                }
                status = LIST_OK;
            }
    }
    return status;
}


uint32 ListDeleteAtBeginning(List *plist, List_Status *status){
    uint32 TempData = 0;
    ListNode *TempNode = NULL;
    if((NULL == plist) || (NULL == status)){
        *status = LIST_NULL;
    }
    else{
        TempNode = plist->Head;
        TempData = TempNode->Data;
        plist->Head = plist->Head->Next;
        free(TempNode);
        (plist->Size)--;
        *status = LIST_OK;
    }
    return TempData;
}


uint32 ListDelete(List *plist, uint32 pos, List_Status *status){
    uint32 TempData = 0;
    ListNode *TempNode = plist->Head;
    ListNode *DeletedNode = NULL;

    if((NULL == plist) || (NULL == status)){
        *status = LIST_NULL;
    }
    else{
        if(pos-1 >plist->Size){
            *status = LIST_INVALID;
        }
        else{
            if(pos == 1){
                TempData = ListDeleteAtBeginning(plist, status);
            }
            else{
                while(pos-1 > 1){
                    TempNode = TempNode->Next;
                    pos--;
                }
                DeletedNode = TempNode->Next;
                TempData = DeletedNode->Data;
                TempNode->Next = TempNode->Next->Next;
                (plist->Size)--;
                free(DeletedNode);
            }
            *status = LIST_OK;
        }
    }
    return TempData;
}


List_Status ListTraverse(List *plist, void(*pf)(uint32)){
    ListNode *TempNode;
    List_Status status = LIST_NOK;

    if((NULL == plist) || (NULL == pf)){
        status = LIST_NULL;
    }
    else{
        for(TempNode = plist->Head; TempNode; TempNode = TempNode->Next){
            (*pf)(TempNode->Data);
        }
        status = LIST_OK;
    }
    return status;
}


uint32 ListLength(List *plist, List_Status *status){
    if((NULL == plist) || (NULL == status)){
        *status = LIST_NULL;
    }
    else{
        *status = LIST_OK;
    }
    return (plist->Size);
}


List_Status ListDestroy(List *plist){
    ListNode *TempNode = NULL;
    List_Status status = LIST_NOK;
    if(NULL == plist){
        status = LIST_NULL;
    }
    else{
        for(TempNode = plist->Head->Next; TempNode; TempNode = TempNode->Next){
            free(plist->Head);
            plist->Head = TempNode;
        }
        free(plist);
        status = LIST_OK;
    }
    return status;
}








