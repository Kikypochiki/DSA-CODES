#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int Element;

typedef struct _stack
{
    Element* storage;
    int top;
    int capacity;
}*STACK_ARR;

STACK_ARR createStack(int capacity)
{
    STACK_ARR st = (STACK_ARR)malloc(sizeof(struct _stack));
    st->top = 0;
    st->capacity = capacity;
    st->storage = (Element*)malloc(sizeof(Element)*capacity);
    for(int i = 0; i < capacity; i++)
    st->storage[i] = 0;
    return st;
}
int isFull(STACK_ARR stack)
{
    return stack->top == stack->capacity;
}

int isEmpty(STACK_ARR stack)
{
    return stack->top == 0;
}

void push(STACK_ARR stack, Element data)
{
    if (!isFull(stack))
    stack->storage[stack->top++] = data;
}

Element pop(STACK_ARR stack)
{
    return (isEmpty(stack)) ? -1 : stack->storage[--(stack->top)];
}

void reverseStack(STACK_ARR original)
{
    STACK_ARR temp1 = createStack(original->capacity);
    STACK_ARR temp2 = createStack(original->capacity);

    while(!isEmpty(original))
        push(temp1, pop(original));

    while(!isEmpty(temp1))
        push(temp2, pop(temp1));

    while(!isEmpty(temp2))
        push(original, pop(temp2));

    free(temp1->storage);
    free(temp2->storage);
    free(temp1);
    free(temp2);
}
void printStack(STACK_ARR stk)
{
    for(int i = stk->top-1; i>-1; i--)
        printf("%d ", stk->storage[i]);
}
void convertDecToBinary()
{
    int d, dig, temp;
    printf("\nEnter Num: ");
    scanf("%d", &d);

    temp = d;
    dig = ceil(log(d+1)/log(2));

    STACK_ARR binStk = createStack(dig);

    while(temp>0)
    {
        push(binStk, temp%2);
        temp/=2;
    }
    printStack(binStk);
}
void sortStack(STACK_ARR stk)
{
    STACK_ARR tempStk = createStack(stk->capacity);
    while(!isEmpty(stk))
    {
        int temp = pop(stk);
        while(!isEmpty(tempStk) && tempStk->storage[tempStk->top] > temp)
        {
            push(stk, pop(tempStk));
        }
        push(tempStk, temp);
    }
    while(!isEmpty(tempStk))
    {
        push(stk, pop(tempStk));
    }
}
int main()
{
    STACK_ARR stk =  createStack(4);
    push(stk, 1);
    push(stk, 2);
    push(stk, 4);
    push(stk, 3);

    //printStack(stk);
    //printf("\n");
    //reverseStack(stk);
    sortStack(stk);
    printStack(stk);

    //printStack(stk);
    //convertDecToBinary();
}
