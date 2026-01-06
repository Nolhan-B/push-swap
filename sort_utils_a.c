/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbilyj <nbilyj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:23:37 by nbilyj            #+#    #+#             */
/*   Updated: 2026/01/06 11:27:21 by nbilyj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
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

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
