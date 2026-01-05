/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:04:59 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/05 09:56:21 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;
	
	if (!*a || !(*a)->next)
	{
		return ;
	}
	n1 = *a;
	n2 = (*a)->next;
	n3 = (*a)->next->next;
	*a = n2; 
	n1->prev = n2;
	n2->next = n1;
	n2->prev = NULL;
	if (n3)
	{
		n3->prev = n1;
		n1->next = n3;
	}
	else 
		n1->next = NULL;
}
void	pb(t_stack **a, t_stack **b)
{
	t_stack *temp;
	
	if (!*a)
	{
		return ;
	}
	temp = *a;
	*a = temp->next;
	if (*a != NULL )
		(*a)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	if (*b == NULL)
	{
		*b = temp;
	} 
	else
	{ 
		temp->next = *b;
		(*b)->prev = temp;
		*b = temp;
	}
}
void	ra(t_stack **a)
{
	t_stack *n_last;
	t_stack *head;
	if (!(*a) || !(*a)->next)
		return;
	n_last = ft_lstlast(*a);
	head = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	n_last->next = head;
	head->prev = n_last;
	head->next = NULL;
}
void	rra(t_stack **a)
{
	t_stack	*n_last;
	t_stack	*n_head;
	t_stack *n_lminus1;
	if (!*a || !(*a)->next)
		return ;
	n_last = ft_lstlast(*a);
	n_head = *a;
	n_lminus1 = n_last->prev;
	
	*a = n_last;
	n_last->prev = NULL;
	n_lminus1->next = NULL;
	n_last->next = n_head;
	n_head->prev = n_last;

}	
	
void pa(t_stack **a, t_stack **b)
{
    t_stack *temp;
    if (!*b)
        return ;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
}

void rb(t_stack **b)
{
    t_stack *temp;
    t_stack *last;
    if (!*b || !(*b)->next)
        return ;
    temp = *b;

    *b = (*b)->next;
    last = *b;
    while (last->next)
    {
        last = last->next;
    }
    last->next = temp;
    temp->next = NULL; 
}

void rrb(t_stack **b)
{
    t_stack *temp;
    t_stack *prev_last;
    if (!*b || !(*b)->next)
        return ;
    prev_last = *b;
    while (prev_last->next->next) 
    {
        prev_last = prev_last->next;
    }
    temp = prev_last->next; 
    prev_last->next = NULL;
    temp->next = *b;
    *b = temp;
}

void	sb(t_stack **b)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;
	
	if (!*b || !(*b)->next)
	{
		return ;
	}
	n1 = *b;
	n2 = (*b)->next;
	n3 = (*b)->next->next;
	*b = n2; 
	n1->prev = n2;
	n2->next = n1;
	n2->prev = NULL;
	if (n3)
	{
		n3->prev = n1;
		n1->next = n3;
	}
	else 
		n1->next = NULL;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}


void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}