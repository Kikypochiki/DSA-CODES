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
void pairwiseSwap(SLL list);
void fastAndSlow(SLL list);
int main()
{
    SLL list = createSLL();
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 3);
    addLast(list, 4);
    addLast(list, 5);
    addLast(list, 6);
    addLast(list, 1);
    printSLL(list);
    printf("\n");
    fastAndSlow(list);
}
SLL createSLL()
{
    SLL list = (SLL)malloc(sizeof(struct sll));
    list->head = NULL;
    list->size = 0;

    return list;
}
void addLast(SLL list, int data)
{
    SNODE newVal = (SNODE)malloc(sizeof(struct snode));
    newVal->data = data;
    newVal->next = NULL;

    SNODE p = list->head;

    if(p == NULL)
        list->head = newVal;
    else
    {
        while(p->next!=NULL)
            p = p->next;

        p->next = newVal;
    }
    list->size++;
}
void printSLL(SLL list)
{
    SNODE p = list->head;

    if(list->size > 0)
    {
        while(p!=NULL)
        {
            printf("%d->", p->data);
            p = p->next;
        }
    }
}
void pairwiseSwap(SLL list)
{
    SNODE p = list->head;

    while(p!=NULL && p->next != NULL)
    {
        int temp = p->data;
        p->data = p->next->data;
        p->next->data = temp;

        p = p->next->next;
    }
}
void fastAndSlow(SLL list)
{
    SNODE f = list->head, s = list->head;

    while(f->next!=NULL)
    {
        s = s->next;
        f = f->next->next;
    }
    printf("%d is the middle pointer", s->data);
}
