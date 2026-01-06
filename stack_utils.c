/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbilyj <nbilyj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:31:31 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/06 13:22:31 by nbilyj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_dup(t_stack *stack, int value)
{
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_stack	*ft_create_stack(char **av)
{
	t_stack	*a;
	t_stack	*new;
	int		i;
	int		value;

	a = NULL;
	i = 1;
	while (av[i])
	{
		value = (int)ft_atol(av[i]);
		if (is_dup(a, value))
		{
			ft_free_stack(&a);
			return (NULL);
		}
		new = ft_lstnew(value);
		if (!new)
		{
			ft_free_stack(&a);
			return (NULL);
		}
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}
