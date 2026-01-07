/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:15:59 by nbilyj            #+#    #+#             */
/*   Updated: 2026/01/07 15:20:22 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_stack *b)
{
	int		i;
	int		max_value;
	int		max_pos;
	t_stack	*tmp;

	i = 0;
	max_pos = 0;
	tmp = b;
	max_value = tmp->value;
	while (tmp)
	{
		if (tmp->value > max_value)
		{
			max_value = tmp->value;
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_pos);
}

void	sort_two(t_stack **a, t_params *flags)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, flags);
}

void	move_stack_b(t_stack **b, int target_pos, t_params *flags)
{
	int	size;

	size = ft_lstsize(*b);
	if (target_pos <= size / 2)
	{
		while (target_pos-- > 0)
			rb(b, flags);
	}
	else
	{
		while (size > target_pos)
		{
			rrb(b, flags);
			target_pos++;
		}
	}
}

void	sort_three(t_stack **a, t_params *flags)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->value;
	n2 = (*a)->next->value;
	n3 = (*a)->next->next->value;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(a, flags);
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		sa(a, flags);
		rra(a, flags);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(a, flags);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(a, flags);
		ra(a, flags);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a, flags);
}
