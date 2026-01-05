/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:35:44 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/05 10:33:13 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_av_valid(char *av)
{
	int		i;
	long	value;

	i = 0;
	if (!av)
		return (0);
	if (av[i] == '+' || av[i] == '-')
	{
		i++;
		if (av[i] < '0' || av[i] > '9')
			return (0);
	}
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	value = ft_atol(av);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
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
