/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:32:17 by nbilyj            #+#    #+#             */
/*   Updated: 2026/01/07 11:45:39 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, t_params *flags)
{
	swap(a);
	swap(b);
	flags->data.ops[SS]++;
	flags->data.total++;
	write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b, t_params *flags)
{
	rotate(a);
	rotate(b);
	flags->data.ops[RR]++;
	flags->data.total++;
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b, t_params *flags)
{
	reverse_rotate(a);
	reverse_rotate(b);
	flags->data.ops[RRR]++;
	flags->data.total++;
	write(1, "rrr\n", 4);
}
