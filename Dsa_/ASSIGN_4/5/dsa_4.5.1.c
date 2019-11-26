#include "STACK.h"
int main()
{
    node * stack=init_s();
    push(&stack);
    push(&stack);
    print(stack);
    print_using_pop(&stack);
    print_rev(stack);
    printf("\n");
    return 0;
}