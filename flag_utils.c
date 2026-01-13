/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:21:13 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/13 11:24:09 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_flags(char *av, t_params *flag)
{
	if (!ft_strcmp(av, "--bench"))
		flag->bench = 1;
	else if (!ft_strcmp(av, "--simple"))
		ft_set_strat(flag, "Simple (Insertion Sort)", "O(n2)", 1);
	else if (!ft_strcmp(av, "--medium"))
		ft_set_strat(flag, "Medium (Chunks Sort)", "O(n√n)", 2);
	else if (!ft_strcmp(av, "--complex"))
		ft_set_strat(flag, "Complex (Butterfly Sort)", "O(n log n)", 3);
	else if (!ft_strcmp(av, "--adaptive"))
		ft_set_strat(flag, "Adaptive", "O(n log n)", 4);
	else
		return (0);
	return (1);
}

int	parse_flag(char **av, t_params *flag)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while (av[i] && i <= 2)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			if (!ft_flags(av[i], flag))
				return (0);
			j++;
		}
		i++;
	}
	return (j);
}

void	init_flag(t_params *flag)
{
	int	i;

	i = 0;
	flag->simple = 0;
	flag->medium = 0;
	flag->complex = 0;
	flag->adaptive = 1;
	flag->bench = 0;
	flag->data.strat = "Adaptive";
	flag->data.class = "O(n log n)";
	flag->data.total = 0;
	while (i < 11)
	{
		flag->data.ops[i] = 0;
		i++;
	}
}

void	ft_set_strat(t_params *flag, char *s, char *c, int type)
{
	flag->data.strat = s;
	flag->data.class = c;
	flag->simple = (type == 1);
	flag->medium = (type == 2);
	flag->complex = (type == 3);
	flag->adaptive = (type == 4);
}
