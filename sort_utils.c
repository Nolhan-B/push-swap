/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:04:59 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/06 10:00:56 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void swap(t_stack **x)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	if (!*x || !(*x)->next)
	{
		return ;
	}
	n1 = *x;
	n2 = (*x)->next;
	n3 = (*x)->next->next;
	*x = n2;
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

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rotate(t_stack **x)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*x || !(*x)->next)
		return ;
	temp = *x;
	*x = (*x)->next;
	(*x)->prev = NULL;
	last = *x;
	while (last->next)
	{
		last = last->next;
	}
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	reverse_rotate(t_stack **x)
{
	t_stack	*temp;
	t_stack	*prev_last;

	if (!*x || !(*x)->next)
		return ;
	prev_last = *x;
	while (prev_last->next->next)
	{
		prev_last = prev_last->next;
	}
	temp = prev_last->next;
	prev_last->next = NULL;
	temp->next = *x;
	temp->prev = NULL;
	(*x)->prev = temp;
	*x = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = *a;
	if (*a)
		(*a)->prev = temp;
	*a = temp;
	temp->prev = NULL;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
	temp->prev = NULL;
	write(1, "pb\n", 3);
}
