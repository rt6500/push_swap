#include <unistd.h>
#include "../libft/libft.h"
#include "../libft/srcs/printf/ft_printf.h"

typedef struct s_node
{
    long	    	num;
    long		    index;
    struct s_node	*next;
    struct s_node	*prev;
}   t_node;

// typedef struct s_stack
// {
// 	t_node  *top;
// }	t_stack;


void    ft_node_add_back(t_node **stack, t_node *new)
{
    t_node  *last;
    
    if (!lst || !new)
    return ;
    if (!*lst)
    {
        *lst = new;
        new->next = new;
        new->prev = new;
        return ;
    }
    last = (*stack)->prev;
    last->next = new;
    new->prev = last;
    new->next = *stack;
    (*stack)->prev = new;
}

void    free_stack(t_node **stack)
{
    t_node  *cur;
    t_node  *next;
    
    if (!stack || !*stack)
    return;
    cur = *stack;
    next = cur->next;
    
    while (next != *stack)
    {
        free(cur);
        cur = next;
        next = next->next;
    }
    free(cur);
    *stack = NULL;
}

int stack_size(t_node *stack)
{
    t_node *cur;
    int     size;
    
    if (!stack)
    return (0);
    size = 1;
    cur = stack->next;
    while (cur != stack)
    {
        size++;
        cur = cur->next;
    }
    return (size);
}

// int do_sa(int n, long *array)
// {
    //     long i;
    //     if (n < 3)
    //         return (1);
    //     i = array[0];
    //     array[0] = array[1];
    //     array[1] = i;
    //     return (ft_printf("sa\n"), 0);
    // }
    
    // int do_ra(int n, long *array)
    // {
//     long i;

//     i = array[n - 1];
//     array[n - 1] = array[0];
//     array[0] = array[1];
//     array[1] = i;
//     return (ft_printf("ra\n"), 0);
// }

// int do_rra(int n, long *array)
// {
    //     long i;
    
    //     i = array[0];
    //     array[0] = array[n - 1];
    //     array[n - 1] = array[1];
    //     array[1] = i;
    //     return (ft_printf("rra\n"), 0);
    // }
    
    // int command_three(int n, long *array)
    // {
        //     //3 is the last:array[n-1] == max.
        //     //1,2,3
        //     n = 3;
        //     if (array[2] == 3 && array[1] == 2) //1,2,3
        //         return (0);
        //     //2,1,3
        //     else if (array[2] == 3)
        //         do_sa(n, array);
        //     //3 is the middle
        //     //2,3,1:
        //     else if (array[1] == 3 && array[2] == 1)
        //         do_rra(n, array);
        //     //1,3,2
        //     else if (array[1] == 3)
        //     {
            //         // write(1, "asdf\n", 5);
            //         do_rra(n, array); //OR do_sa();
            //         do_sa(n, array);
            //     }
            //     //3 is the first
            //     //3,1,2
            //     else if (array[0] == 3)
            //     {
//         do_ra(n, array);
//         if (array[1] == 1)
//             do_ra(n, array);
//         else
//         //3,2,1
//             do_sa(n, array);
//     }
//     if (!(array[0] == 1 && array[1] == 2 && array[2] == 3))
//     {
    //         write(1, "asdf\n", 5);
    //         return (1);
    //     }
    //     return (0);
    // }

t_node  *ft_node_new(long num)
{
    t_node  *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return(ft_printf("Error\nAllocation failed.\n"), 1);
    new->num = num;
    new->index = -1;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}
    
int check_input(int argc, char **argv)
{
    int i;
    
    i = 0;
    if (argc < 2)
        return (ft_printf("Usage: %s num1 num2 ...\n", argv[0]), 1);
    
    while (argv[i])
    {
        if (argv[i] < 48 || 58 < argv[i])
        return (1);
        i++
    }
    return (0);
}

int build_stack(argc, argv)
{
    int i;

    i = 1;
    ft_node_new(ft_atoi(argv[i]));
}
    
int main(int argc, char **argv)
{
    t_node *stack;

    if (check_input(argc, argv) == 0)
        stack = build_stack(argc, argv);
    if (!stack)
        return(ft_printf("Error\nFaild to build stack.\n"), 1);
    while (i < n)
    {
        array[i] = ft_atoi(argv[i + 1]); 
        ft_printf("array[%d]: %d\n", i, array[i]);
        i++;
    }
    write(1, "\n", 1);
    if (argc == 3)
        command_three(n, array);
    free_stack(stack);
    return (0);
}