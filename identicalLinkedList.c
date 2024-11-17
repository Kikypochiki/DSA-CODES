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
SLL createSLL();
void addLast(SLL list, int data);
void printSLL(SLL list);
int checkIfIdentical(SLL list1, SLL list2);
SLL findIntersection(SLL list1, SLL list2);
void insertSorted(SLL list, int data);
int main()
{
    SLL list = createSLL();
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 3);
    addLast(list, 5);
    insertSorted(list, 4);
    printSLL(list);
}
SLL createSLL()
{
    SLL sll = (SLL)malloc(sizeof(struct sll));
    sll->head = NULL;
    sll->size = 0;

    return sll;
}
void addLast(SLL list, int data)
{
    SNODE newVal = (SNODE)malloc(sizeof(struct snode));
    newVal->data = data;
    newVal->next = NULL;

    if(list->head == NULL)
        list->head = newVal;
    else
    {
       SNODE p = list->head;
       while(p->next!=NULL)
       {
           p = p->next;
       }
       p->next = newVal;
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
int checkIfIdentical(SLL list1, SLL list2)
{
    SNODE p = list1->head, q = list2->head;
    int ctr = 0;

    if(list1->size != list2->size)
        return 0;
    while(p!=NULL)
    {
        if(p->data == q->data)
            ctr++;
        p = p->next;
        q = q->next;
    }

    if(ctr == list1->size)
        return 1;

    return 0;
}
SLL findIntersection(SLL list1, SLL list2)
{
    SLL newSLL = (SLL)malloc(sizeof(struct sll));
    newSLL->head = NULL;
    newSLL->size = 0;
    SNODE p = list1->head, q = list2->head, r = newSLL->head;

    while(p!=NULL)
    {
        q = list2->head;
        while(q!=NULL)
        {
            if(p->data == q->data)
            {
                SNODE tempVal = (SNODE)malloc(sizeof(struct snode));
                tempVal->data = p->data;
                if(newSLL->head == NULL)
                {
                    newSLL->head = tempVal;
                    r = newSLL->head;
                }
                else
                {
                    r->next = tempVal;
                    r = r->next;
                }
                newSLL->size++;
            }

            q = q->next;
        }
        p = p->next;
    }
    r->next = NULL;
    return newSLL;
}
void insertSorted(SLL list, int data)
{
    SNODE p = list->head;
    SNODE newVaL = (SNODE)malloc(sizeof(struct snode));
    newVaL->data = data;
    newVaL->next = NULL;

    if(p->data >= data)
    {
        newVaL->next = p;
        list->head = newVaL;
    }
    else
    {
        p = list->head;
        while(p->next!=NULL && p->next->data < data)
        {
            p = p->next;
        }

        newVaL->next = p->next;
        p->next = newVaL;
    }
}


