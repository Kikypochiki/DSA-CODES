#include <stdio.h>
#include <stdlib.h>

typedef struct cnode
{
    int data;
    struct cnode *next;
}*CNODE;
typedef struct cll
{
    CNODE head;
    int size;
}*CLL;
CLL createCLL();
void addLast(CLL list, int data);
void printCLL(CLL list);
CLL createCLLHex(int n);
CLL createBin(int n);
int main()
{
    CLL l = createBin(69);
    printCLL(l);
}
CLL createCLL()
{
    CLL list = (CLL)malloc(sizeof(struct cll));
    list->head = NULL;
    list->size = 0;

    return list;
}
void addLast(CLL list, int data)
{
    CNODE newVal = (CNODE)malloc(sizeof(struct cnode));
    newVal->data = data;
    newVal->next = NULL;

    if(list->head == NULL)
    {
        list->head = newVal;
    }
    else
    {
        CNODE p = list->head;
        while(p->next!=list->head)
            p = p->next;
        p->next = newVal;
    }
    newVal->next = list->head;
    list->size++;
}
void printCLL(CLL list)
{
    CNODE p = list->head;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != list->head);
}
CLL createCLLHex(int n)
{
    int temp = n;
    int mod;

    CLL list = (CLL)malloc(sizeof(struct _cll));
    list->head = NULL;
    list->size = 0;

    CNODE p = (CNODE)malloc(sizeof(struct _cnode));
    if (temp % 16 < 10) {
        p->data = (temp % 16) + '0';
    } else {
        p->data = (temp % 16) + 'A' - 10;
    }
    p->next = NULL;
    list->size++;
    list->head = p;

    temp /= 16;

    CNODE q = list->head;
    while (temp > 0)
    {
        CNODE newVal = (CNODE)malloc(sizeof(struct _cnode));
        mod = temp % 16;
        if (mod < 10)
        {
            newVal->data = mod + '0';
        } else {
            newVal->data = mod + 'A' - 10;
        }

        q->next = newVal;
        q = q->next;
        list->size++;

        temp /= 16;
    }

    int arr[list->size];
    CNODE r = list->head;
    for(int i = list->size-1; i >= 0; i--)
    {
        arr[i] = r->data;
        r = r->next;
    }
    r = list->head;
    for(int i = 0;  i<list->size; i++)
    {
        r->data = arr[i];
        r = r->next;
    }
    q->next = list->head;
    return list;
}
CLL createBin(int n)
{
    int temp = n;

    CLL list = (CLL)malloc(sizeof(struct cll));
    list->head = NULL;
    list->size = 0;

    CNODE p = (CNODE)malloc(sizeof(struct cnode));
    p->data = temp%2;
    temp/=2;
    list->size++;
    list->head = p;

    CNODE q = list->head;
    while(temp > 0)
    {
        CNODE newVal = (CNODE)malloc(sizeof(struct cnode));
        newVal->data = temp%2;
        temp/=2;

        q->next = newVal;
        list->size++;
        q = q->next;
    }

    q->next = list->head;

    int arr[list->size];

    q = list->head;
    for(int i = list->size-1; i>=0; i--)
    {
        arr[i] = q->data;
        q = q->next;
    }
    q = list->head;
    for(int i = 0; i<list->size; i++)
    {
        q->data = arr[i];
        q = q->next;
    }

    return list;
}
