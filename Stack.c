#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Stack.h"

int main () {

    struct Stack stk = {};
    StackCtor (&stk, 2);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//

    for (int i = 0; i < 1000; i++)
    {
        StackPush (&stk, 10.2 + i);
        printf ("data[%zu] = %0.1lf\n", stk.size - 1, stk.data[i]);
        printf ("%zu    %p   %0.1lf\n", stk.capacity, &(stk.data), stk.data[i]);
    }

//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
    printf ("\n\nSize of stack:     %zu\n"
            "Capacity of stack: %zu\n", stk.size, stk.capacity);
    StackDtor (&stk);
    return 0;
}
