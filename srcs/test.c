#include <unistd.h>
#include "../libft/libft.h"
#include "../libft/srcs/printf/ft_printf.h"

// typedef struct s_node
// {
//     long	    	data;
//     long		    index;
//     struct s_node	*next;
//     struct s_node	*prev;
// }   t_node;

// typedef struct s_stack
// {
// 	t_node  *top;
// }	t_stack;

int command_three(int n, long *array)
{
    if (array[0] < array[1] && array[0] < array[2])
    {
        if (array[1] < array[2])
            return (0);
        else
            do_sa();
    }
}

int main(int argc, char **argv)
{
    int     i;
    int     n;
    long    *array;

    if (argc < 2)
        return (ft_printf("Usage: %s num1 num2 ...\n", argv[0]), 1);
    
    n = argc - 1;
    i = 0;
    array = ft_calloc(1, n * sizeof(long));
    if (!array)
        return(ft_printf("Error\nAllocation failed.\n"), 1);
    while (i < n)
    {
        array[i] = ft_atoi(argv[i + 1]); 
        ft_printf("array[%d]: %d\n", i, array[i]);
        i++;
    }
    write(1, "\n", 1);
    if (n == 3)
        command_three(n, array);
    free(array);
    return (0);
}