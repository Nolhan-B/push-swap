/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:35:44 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/06 14:14:08 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_av_valid(char **av, int start)
{
	int		i;
	long	value;

	i = 0;
	while (av[start])
	{
		if (av[start][i] == '+' || av[start][i] == '-')
		{
			i++;
			if (av[start][i] < '0' || av[start][i] > '9')
				return (0);
		}
		while (av[start][i])
		{
			if (av[start][i] < '0' || av[start][i] > '9')
				return (0);
			i++;
		}
		value = ft_atol(*av);
		if (value > INT_MAX || value < INT_MIN)
			return (0);
		start++;
	}
	return (1);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
