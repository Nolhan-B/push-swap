/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:23:37 by nbilyj            #+#    #+#             */
/*   Updated: 2026/01/07 11:45:09 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_params *flags)
{
	swap(a);
	flags->data.ops[SA]++;
	flags->data.total++;
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b, t_params *flags)
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
	flags->data.ops[PA]++;
	flags->data.total++;
	write(1, "pa\n", 3);
}

void	ra(t_stack **a, t_params *flags)
{
	rotate(a);
	flags->data.ops[RA]++;
	flags->data.total++;
	write(1, "ra\n", 3);
}

void	rra(t_stack **a, t_params *flags)
{
	reverse_rotate(a);
	flags->data.ops[RRA]++;
	flags->data.total++;
	write(1, "rra\n", 4);
}
