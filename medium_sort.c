/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:16:31 by nbilyj            #+#    #+#             */
/*   Updated: 2026/01/12 12:03:14 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	if (size <= 500)
		return (11);
	return (size / 20);
}

int	get_index_pos(t_stack *b, int index)
{
	int	pos;

	pos = 0;
	while (b)
	{
		if (b->index == index)
			return (pos);
		pos++;
		b = b->next;
	}
	return (-1);
}

static int	get_max_index(t_stack *b)
{
	int	max;

	max = b->index;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

void	rebuild_stack(t_stack **a, t_stack **b, t_params *flags)
{
	int	max;

	while (*b)
	{
		max = get_max_index(*b);
		bring_max_to_top(b, max, flags);
		pa(a, b, flags);
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_params *flags)
{
	int	size;
	int	c_count;
	int	c_size;

	size = ft_lstsize(*a);
	if (size < 1)
		return ;
	c_count = get_chunk_count(size);
	c_size = size / c_count;
	if (c_size < 1)
		c_size = 1;
	push_chunks(a, b, c_size, flags);
	rebuild_stack(a, b, flags);
}
