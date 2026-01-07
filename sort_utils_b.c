/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:27:40 by nbilyj            #+#    #+#             */
/*   Updated: 2026/01/07 11:46:11 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, t_params *flags)
{
	swap(b);
	flags->data.ops[SB]++;
	flags->data.total++;
	write(1, "sb\n", 3);
}

void	pb(t_stack **a, t_stack **b, t_params *flags)
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
	flags->data.ops[PB]++;
	flags->data.total++;
	write(1, "pb\n", 3);
}

void	rb(t_stack **b, t_params *flags)
{
	rotate(b);
	flags->data.ops[RB]++;
	flags->data.total++;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b, t_params *flags)
{
	reverse_rotate(b);
	flags->data.ops[RRB]++;
	flags->data.total++;
	write(1, "rrb\n", 4);
}
