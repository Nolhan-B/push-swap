/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:38:44 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/12 11:51:23 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks(t_stack **a, t_stack **b, int c_size, t_params *flags)
{
	int	pushed;
	int	chunk_min;
	int	chunk_max;

	pushed = 0;
	chunk_min = 0;
	chunk_max = c_size - 1;
	while (*a)
	{
		if ((*a)->index >= chunk_min && (*a)->index <= chunk_max)
		{
			pb(a, b, flags);
			pushed++;
			if ((*b)->index > (chunk_min + chunk_max) / 2)
				rb(b, flags);
		}
		else
			ra(a, flags);
		if (pushed == c_size)
		{
			pushed = 0;
			chunk_min += c_size;
			chunk_max += c_size;
		}
	}
}

void	bring_max_to_top(t_stack **b, int max_index, t_params *flags)
{
	int	pos;
	int	size;

	pos = get_index_pos(*b, max_index);
	size = ft_lstsize(*b);
	if (pos <= size / 2)
	{
		while ((*b)->index != max_index)
			rb(b, flags);
	}
	else
	{
		while ((*b)->index != max_index)
			rrb(b, flags);
	}
}
