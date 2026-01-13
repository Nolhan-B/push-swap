/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_ab_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:04:59 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/06 14:20:55 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **x)
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
