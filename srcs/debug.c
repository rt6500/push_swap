#include "../push_swap.h"

void    print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current;

    current = stack_a->top;

    ft_printf("stack:a ");
    while(current)
    {
        ft_printf("%d(%d) -> ", current->num, current->rank);
        current = current -> next;
    }
    current = stack_b->top;
    ft_printf("\nstack:b: ");
    while(current)
    {
        ft_printf("%d(%d) -> ", current->num, current->rank);
        current = current -> next;
    }
}
