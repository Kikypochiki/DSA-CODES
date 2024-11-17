#include <stdio.h>
#include <stdlib.h>

typedef struct snode
{
    int data;
    struct snode *next;
} *SNODE;
typedef struct sll
{
    SNODE head;
    int size;
} *SLL;
SLL createList();
void addFirst(SLL list, int data);
void printSLL(SLL list);
void addLast(SLL list, int data);
void deleteData(SLL list, int data);
void addBetVal(SLL list, int data, int pr);
void bubbleSort(SLL list);
void removeDoubleNum(SLL list);
SLL createSLLOnes(int n);
int SLL_addElementAfterX(SLL list, int x, int data);
void SLL_deleteBeforeX(SLL list, int x);
void SLL_flipFrontEnd(SLL list);
int main()
{
    SLL l = createList();
    addFirst(l, -6);
    addLast(l, 1);
    addLast(l, 5);
    addLast(l, 1);
    printSLL(l);
    printf("\n");
    //SLL_flipFrontEnd(l);
    SLL_deleteBeforeX(l, 1);
    //deleteData(l, 5);
    printSLL(l);
}
SLL createList()
{
    SLL list = (SLL)malloc(sizeof(struct sll));
    list->head = NULL;
    list->size = 0;

    return list;
}
void addFirst(SLL list, int data)
{
    SNODE newVal = (SNODE)malloc(sizeof(struct snode));
    newVal->data = data;
    newVal->next = NULL;

    if(list->head == NULL)
        list->head = newVal;
    else if(list->head!=NULL)
    {
        newVal->next = list->head;
        list->head = newVal;

    }
    list->size++;
}
void printSLL(SLL list)
{
    SNODE p = list->head;
    while(p!=NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
}
void addLast(SLL list, int data)
{
    SNODE newVal = (SNODE)malloc(sizeof(struct snode));
    newVal->data = data;
    newVal->next = NULL;

    SNODE p = list->head;

    while(p->next!=NULL)
        p = p->next;
    p->next = newVal;
    list->size++;
}
void deleteData(SLL list, int data)
{
    SNODE p = list->head, prev = NULL;
    if(p->data == data)
    {
        list->head = p->next;
    }
    else
    {
        while(p!=NULL)
        {
            if(p->data == data)
            {
                prev->next = p->next;
            }
            prev = p;
            p = p->next;
        }
    }
    free(p);
    list->size--;
}
void addBetVal(SLL list, int data, int pr)
{
    SNODE p = list->head;
    SNODE newVal = (SNODE)malloc(sizeof(struct snode));
    newVal->data = data;
    newVal->next = NULL;

    while(p!=NULL)
    {
        if(p->data == pr)
        {
            newVal->next = p->next;
            p->next = newVal;
            list->size++;
        }
        p = p->next;
    }
}
void bubbleSort(SLL list)
{
    SNODE p = list->head;

    for(int i = 0; i<list->size; i++)
    {
        p = list->head;
        for(int j = 0; j<list->size - i - 1; j++)
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
void removeDoubleNum(SLL list)
{
    SNODE p = list->head, prev = NULL, temp;
    while(p!=NULL)
    {
        prev = p;
        temp = p->next;
        while(temp!=NULL)
        {
            if(prev->data == temp->data)
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
                list->size--;
            }
            else
            {
                prev = temp;
                temp = prev->next;
            }
        }
        p = p->next;
    }
}
SLL createSLLOnes(int n)
{
    SLL list = (SLL)malloc(sizeof(struct sll));
    list->size = n;

    SNODE first = (SNODE)malloc(sizeof(struct snode));
    first->data = 1;
    list->head = first;

    for(int i = 1; i<n; i++)
    {
        first->next = (SNODE)malloc(sizeof(struct snode));
        first->next->data = 1;

        first = first->next;
    }

    first->next = NULL;

    return list;
}
int SLL_addElementAfterX(SLL list, int x, int data)
{
    int num = 0;

    SNODE p = list->head;
    while(p!=NULL)
    {
        if(p->data == x)
        {
            SNODE newVal = (SNODE)malloc(sizeof(struct snode));
            newVal->data = data;

            newVal->next = p->next;
            p->next = newVal;
            list->size++;
            num++;
        }
        p = p->next;
    }
    return num;
}
void SLL_deleteBeforeX(SLL list, int x)
{
    SNODE p = list->head;

    if(list->size > 1)
    {
        if(p->data == x && p->next->data == x)
        {
            while(p->next!=NULL && p->next->data == x)
            {
                list->head = p->next;
                free(p);

                p = list->head;
            }
        }
        else
        {
            p = list->head;
            while(p->next!=NULL && p->data != x)
            {
                list->head = p->next;
                free(p);

                p = list->head;
            }
        }
    }
}
void SLL_flipFrontEnd(SLL list)
{
    SNODE p = list->head, first = list->head;

    while(p->next!=NULL)
        p = p->next;
    int temp = p->data;
    p->data = first->data;
    first->data = temp;
}
