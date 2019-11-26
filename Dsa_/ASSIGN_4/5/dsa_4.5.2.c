#include "STACK_ARRAY.h"
int main()
{
    stack *s;
    stack *s1;
    init_s(&s1);
    init_s(&s);
    push(s,5);
    push(s,6);
    print(s);
    push(s,9);
    print_rev(s);
    push(s1,5);
    push(s1,6);
    push(s1,9);
    printf("\n equality is %d",equal(s,s));
    pop(s1);
    printf("\n equality is %d",equal(s,s1));
    print_with_pop(s);
    printf("\n");
    return 0;
}