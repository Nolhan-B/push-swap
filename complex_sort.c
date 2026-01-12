#include "push_swap.h"

void    push_chunks_complex(t_stack **a, t_stack **b, t_params *flag)
{
    int    i;
    int    range;
    int    size;

    i = 0;
    size = ft_lstsize(*a);
    range = 35;
    if (size <= 100)
        range = 15;
    while (*a)
    {
        if ((*a)->index <= i)
        {
            pb(a, b, flag);
            rb(b, flag);
            i++;
        }
        else if ((*a)->index <= i + range)
        {
            pb(a, b, flag);
            i++;
        }
        else
            ra(a, flag);
    }
}

void    complex_sort(t_stack **a, t_stack **b, t_params *flag)
{
    push_chunks_complex(a, b, flag);
    rebuild_stack(a, b, flag);
}