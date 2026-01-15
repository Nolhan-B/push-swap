/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:23:10 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/15 09:44:59 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sort(t_stack **a, t_params *flags)
{
	if (ft_lstsize(*a) == 2)
		sort_two(a, flags);
	else if (ft_lstsize(*a) == 3)
		sort_three(a, flags);
	else
		return ;
}

static void	init_stack_b(t_stack **a, t_stack **b, t_params *flags)
{
	pb(a, b, flags);
	pb(a, b, flags);
}

static int	get_target_pos(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		pos;
	int		target;

	tmp = b;
	pos = 0;
	target = get_max_pos(b);
	while (tmp->next)
	{
		if (a->value < tmp->value && a->value > tmp->next->value)
			return (pos + 1);
		tmp = tmp->next;
		pos++;
	}
	if (a->value < tmp->value && a->value > b->value)
		target = 0;
	return (target);
}

static void	final_rotate_b(t_stack **b, t_params *flags)
{
	int	max_pos;
	int	size;

	max_pos = get_max_pos(*b);
	size = ft_lstsize(*b);
	if (max_pos <= size / 2)
		while (max_pos-- > 0)
			rb(b, flags);
	else
		while (size - max_pos++ > 0)
			rrb(b, flags);
}

void	insertion_sort(t_stack **a, t_stack **b, t_params *flags)
{
	if (ft_disorder(*a) == 0.0)
		return ;
	if (ft_lstsize(*a) <= 3)
		return (small_sort(a, flags));
	init_stack_b(a, b, flags);
	while (*a)
	{
		move_stack_b(b, get_target_pos(*a, *b), flags);
		pb(a, b, flags);
	}
	final_rotate_b(b, flags);
	while (*b)
		pa(a, b, flags);
}
/*
void	print_stacks(t_stack *a, t_stack *b)
{
	printf("\n  [ STACK A ]      [ STACK B ]\n");
	printf("--------------------------------\n");
	while (a || b)
	{
		if (a)
		{
			printf("     %d", a->value);
			a = a->next;
		}
		else
			printf("      ");
		if (b)
		{
			printf("             %d\n", b->value);
			b = b->next;
		}
		else
			printf("\n");
	}
	printf("--------------------------------\n");
}*/
