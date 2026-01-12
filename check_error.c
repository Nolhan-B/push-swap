/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:35:44 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/12 11:46:44 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_av_valid(char **av, int start)
{
	int			i;
	long long	value;

	while (av[start])
	{
		i = 0;
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
		value = ft_atol(av[start]);
		if (value > 2147483647 || value < -2147483648)
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

int	use_split(int ac, char **av, int start)
{
	int	i;

	i = 0;
	if (start < ac - 1)
		return (0);
	while (av[start][i])
	{
		if (av[start][i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
