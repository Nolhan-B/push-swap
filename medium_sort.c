/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbilyj <nbilyj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:16:31 by nbilyj            #+#    #+#             */
/*   Updated: 2026/01/08 10:40:49 by nbilyj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	if (size <= 500)
		return (11);
	return (size / 20);
}

int	get_index_pos(t_stack *b, int index)
{
	int	pos = 0;

	while (b)
	{
		if (b->index == index)
			return (pos);
		pos++;
		b = b->next;
	}
	return (-1);
}

int	get_max_index(t_stack *b)
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

void	medium_sort(t_stack **a, t_stack **b, t_params *flags)
{
	int	size;
	int	c_count;
	int	c_size;

	size = ft_lstsize(*a);
	c_count = get_chunk_count(size);
	c_size = size / c_count;
	push_chunks(a, b, c_size, flags);
	rebuild_stack(a, b, flags);
}