/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:16:31 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/06 13:29:16 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_flags(char *av, t_params *flag)
{
	if (!strcmp(av, "--bench"))
		flag->bench = 1;
	else if(!strcmp(av, "--simple"))
		flag->simple = 1;
	else if(!strcmp(av, "--medium"))
		flag->medium = 1;
	else if(!strcmp(av, "--complex"))
		flag->complex = 1;
	else if(!strcmp(av, "--adaptive"))
		flag->adaptive = 1;
	else 
		return (0);
	if (flag->simple == 1)
		flag->adaptive = 0;
	else if (flag->medium == 1)
		flag->adaptive = 0;
	else if (flag->complex == 1)
		flag->adaptive = 0;
	return (1);
}

int	parse_flag(char **av, t_params *flag)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-' && av[i][1] == '-')
			if(!ft_flags(av[i], flag))
			{
				return (0);
			}
		i++;
	}
	return (i);
}

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
		value = ft_atol(av);
		if (value > INT_MAX || value < INT_MIN)
			return (0);
		start++;
	}
		return (1);
	}
	

void	init_flag(t_params *flag)
{
	flag->simple = 0;
	flag->medium = 0;
	flag->complex = 0;
	flag->adaptive = 1;
	flag->bench = 0;
}	

int	param_manager(int ac, char **av, t_params *flag, t_stack *a)
{
	int start;

	if (ac < 2)
		return (0);
	init_flag(flag);
	start = parse_flag(av, flag);
	if (start == 0)
		return (0);
	if (!is_av_valid(av, start))
		return (0);
	a = ft_create_stack(av, start);
	if (!a)
		return (0);
	return (1);
}

int main(int ac, char **av)
{
	t_params flag;
	t_stack a;
	t_stack b = NULL;
	
	if (!param_manager(ac, **av, &flag, &a))
	{
		write(2, "Error\n", 7);
		return (0);
	}	
}
