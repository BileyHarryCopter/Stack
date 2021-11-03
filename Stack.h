#include "Service.h"
typedef struct Stack Stack;

size_t CAP_SAMPLE = sizeof (double);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
struct Stack {
    long canary1;
    double * data;
    size_t size;
    size_t capacity;
    long canary2;
};
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
void StackCtor (Stack * stk, size_t capacity)
{
    meowsert (stk != NULL);
    stk -> data = (double *) calloc (capacity, sizeof (double *));
    stk -> capacity = capacity;
    stk -> size = 0;
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
void StackDtor (Stack * stk)
{
    meowsert (stk != NULL);
    stk -> size = 0;
    stk -> capacity = 0;
    free (stk -> data);
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
// Enc = encrease - увеличить
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
void StackResEnc (Stack * stk)
{
    meowsert (stk != NULL);
    stk -> capacity += CAP_SAMPLE;
    stk -> data = (double *) realloc (stk -> data, (stk -> capacity) * sizeof (double));
    meowsert (stk != NULL);
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
// Red = reduce - уменьшить
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
void StackResRed (Stack * stk)
{
    meowsert (stk != NULL);
    stk -> capacity -= CAP_SAMPLE;
    stk -> data = (double *) realloc (stk -> data, (stk -> capacity) * sizeof (double));
    meowsert (stk != NULL);
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
void StackPush (Stack * stk, double value)
{
    meowsert (stk != NULL);
    if (stk -> size >= stk -> capacity - 1)
    {
        StackResEnc (stk);
        stk -> data[stk -> size] = value;
    }
    else
    {
        stk -> data[stk -> size] = value;
    }
    (stk -> size)++;
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
