#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct stack
{
    Element* storage;
    int top;
    int capacity;
}*STACK_ARR;
STACK_ARR createStack(int capacity)
{
    STACK_ARR newStk = (STACK_ARR)malloc(sizeof(struct stack));
    newStk->top = 0;
    newStk->capacity = capacity;
    newStk->storage = (Element*)malloc(sizeof(Element)*capacity);
    for(int i = 0; i<capacity; i++)
        newStk->storage[i] = 0;

    return newStk;
}
int isFull(STACK_ARR stack)
{
    if(stack->top == stack->capacity)
        return 1;
    return 0;
}
int isEmpty(STACK_ARR stack)
{
    if(stack->top == 0)
        return 1;
    return 0;
}
void push(STACK_ARR stack, int data)
{
    if(!isFull(stack))
        stack->storage[stack->top++] = data;
}

Element pop(STACK_ARR stack)
{
    if(!isEmpty(stack))
        return stack->storage[--(stack->top)];
    else
        return -1;
}
STACK_ARR reverseStack(STACK_ARR stack)
{

}
int main()
{

}
