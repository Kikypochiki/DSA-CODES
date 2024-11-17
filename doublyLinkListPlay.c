#include <stdio.h >
#include <stdlib.h>
#include <math.h>

typedef struct dnode
{
    struct dnode *prev;
    int data;
    struct dnode *next;
}*DNODE;
typedef struct dll
{
    DNODE head, tail;
    int size;
}*DLL;
DLL createList();
void addLast(DLL list, int data);
void printDLL(DLL list, int check);
void addValBetX(DLL list, int data, int x);
void delElem(DLL list, int x);
void DLL_deleteThreeMaxOccurrenceOfY(DLL list, int y);
void sort(DLL list);
void reverseList(DLL list);
DNODE mergeSort(DLL list1, DLL list);
void TwoDel(DLL list);
void delBeforeX(DLL list, int x);
void delAfterX(DLL list, int x);
DLL DLL_removeDuplicates(DLL list);
void checkPalindrome(DLL list);
int main()
{
    DLL list = createList();

    addLast(list, 3);
    addLast(list, 2);
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 3);

    printDLL(list, 0);
    checkPalindrome(list);
    //delAfterX(list, 6);
   //printDLL(list, 0);

    //addValBetX(list, 69, 3);
    //delElem(list, 7);
    //DLL_deleteThreeMaxOccurrenceOfY(list, -6);
    //sort(list);
    //reverseList(list);

    /*for(DNODE p = mergeSort(list1, list); p!=NULL;)
    {
        printf("%d->", p->data);
        p = p->next;
    }*/


}
DLL createList()
{
    DLL list = (DLL)malloc(sizeof(struct dll));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}
void addLast(DLL list, int data)
{
    DNODE newVal = (DNODE)malloc(sizeof(struct dnode));
    newVal->data = data;
    newVal->prev = NULL;
    newVal->next = NULL;

    if(list->head == NULL)
    {
        list->head = newVal;
        list->tail = newVal;
    }
    else
    {
        DNODE p = list->head;
        while(p->next!=NULL)
            p = p->next;
        p->next = newVal;
        newVal->prev = p;
        list->tail = newVal;
    }
    list->size++;
}
void printDLL(DLL list, int check)
{
    if(check == 0)
    {
        DNODE p = list->head;
        while(p!=NULL)
        {
            printf("%d->", p->data);
            p = p->next;
        }
    }
    else
    {
        DNODE p = list->tail;
        while(p!=NULL)
        {
            printf("%d->", p->data);
            p = p->prev;
        }
    }
}
void addValBetX(DLL list, int data, int x)
{
    DNODE p = list->head;

    while(p!= NULL && p->data != x)
        p = p->next;

    DNODE newVal = (DNODE)malloc(sizeof(struct dnode));
    newVal->data = data;

    newVal->next = p->next;
    p->next->prev = newVal;
    newVal->prev = p;
    p->next = newVal;

    list->size++;
}
void delElem(DLL list, int x)
{
    if(list->head->data == x)
    {
        DNODE temp = list->head;
        list->head = temp->next;
        list->head->prev = NULL;
        free(temp);
    }
    else if(list->tail->data == x)
    {
        DNODE temp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(temp);

    }
    else
    {
        DNODE p = list->head;
        while(p!=NULL && p->data != x)
            p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;

        free(p);
    }
}
void DLL_deleteThreeMaxOccurrenceOfY(DLL list, int y)
{
    int ctr = 3;
    for(DNODE p = list->tail; p!=NULL && ctr > 0;)
    {
        if(p->data == y)
        {
            DNODE x = p;
            if(p->prev != NULL)
                p->prev->next = p->next;
            else
                list->head = p->next;

            if(p->next != NULL)
                p->next->prev = p->prev;
            else
                list->tail = p->prev;

            p = p->prev;
            free(x);
            list->size--;
            ctr--;
        }
        else
            p = p->prev;
    }
}
void reverseList(DLL list)
{
    DNODE p = list->head, q = list->tail;
    int cnt = ceil(list->size/2);
    while(cnt!=0)
    {
        int temp = p->data;
        p->data = q->data;
        q->data = temp;

        cnt--;
        p = p->next;
        q = q->prev;
    }
}
void sort(DLL list)
{
    DNODE p = list->head;
    for(int i = 0; i<list->size; i++)
    {
        p = list->head;
        for(int j = 0; j<list->size-i-1; j++)
        {
            if(p->data > p->next->data)
            {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
}
DNODE mergeSort(DLL list1, DLL list)
{
    sort(list1);
    sort(list);

    if(list1->head->data < list->head->data)
    {
        list1->tail->next = list->head;
        list->head->prev = list1->tail;
        list1->size += list->size;
        sort(list1);

        return list1->head;
    }
    else
    {
        list->tail->next = list1->head;
        list1->head->prev = list->tail;
        list->size += list1->size;
        sort(list);

        return list->head;
    }
}
void TwoDel(DLL list)
{
    if(list->size <= 0)
        return;
    else
    {
        DNODE p = list->head;
        while(p!=NULL && p->next!=NULL)
        {
            if(p->data == p->next->data)
            {
                DNODE temp = p;
                if(p->prev == NULL)
                {
                    list->head = p->next;
                    p->next->prev = NULL;
                }
                else
                {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                }
                free(temp);
            }
            p = p->next;
        }
    }
}
void delBeforeX(DLL list, int x)
{
    DNODE p = list->head;
    int ctrCheck = 0;
    DNODE temp;
    while(p!=NULL)
    {
        if(p->data == x)
            ctrCheck++;
        p = p->next;
    }
    if(ctrCheck == 0 || list->size == 0)
        return;
    p = list->head;
    while(p!=NULL && p->data!=x)
    {
        temp = p;
        list->head = p->next;
        p->next->prev = NULL;

        free(temp);
        p = p->next;
    }
}
void delAfterX(DLL list, int x)
{
    DNODE p = list->tail;

    DNODE temp = p;
    while(p!=NULL && p->data!=x)
    {
        temp = p;
        list->tail = p->prev;
        p->prev->next = NULL;

        free(temp);
        p = list->tail;
    }
}
DLL DLL_removeDuplicates(DLL list)
{
    if(list->size == 0 || list->head == NULL)
        return list;

    DNODE p = list->head, q = list->head->next;
    while(p!=NULL)
    {
        q = p->next;
        while(q!=NULL)
        {
            if(p->data == q->data)
            {
                if(q->next == NULL)
                {
                    list->tail = q->prev;
                    q->prev->next = NULL;
                    free(q);
                }
                else
                {
                    q->prev->next = q->next;
                    q->next->prev = q->prev;

                    free(q);
                }
                list->size--;
            }
            q = q->next;
        }
        p = p->next;
    }

    return list;
}
void checkPalindrome(DLL list)
{
    if(list->size == 0)
        return;
    int cnt = ceil(list->size/2);
    for(DNODE p = list->head, q = list->tail; cnt>=0;)
    {
        if(p->data != q->data)
        {
            printf("\nNOT A PALINDROME\n");
            return;
        }
        p = p->next;
        q = q->prev;
        cnt--;
    }
    printf("\nPALINDROME\n");
    return;
}
