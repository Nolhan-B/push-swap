/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:16:31 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/07 10:56:53 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_strat(t_params *flag, char *s, char *c, int type)
{
	flag->data.strat = s;
	flag->data.class = c;
	flag->simple = (type == 1);
	flag->medium = (type == 2);
	flag->complex = (type == 3);
	flag->adaptive = (type == 4);
}

int	ft_flags(char *av, t_params *flag)
{
	if (!ft_strcmp(av, "--bench"))
		flag->bench = 1;
	else if (!ft_strcmp(av, "--simple"))
		ft_set_strat(flag, "Simple (Insertion Sort)", "O(n2)", 1);
	else if (!ft_strcmp(av, "--medium"))
		ft_set_strat(flag, "Medium (Chunks Sort)", "O(n√n)", 2);
	else if (!ft_strcmp(av, "--complex"))
		ft_set_strat(flag, "Complex (Radix Sort)", "O(n log n)", 3);
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
	while (av[i] && i < 3)
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
	flag->simple = 0;
	flag->medium = 0;
	flag->complex = 0;
	flag->adaptive = 1;
	flag->bench = 0;
	flag->data.strat = "Adaptive";
	flag->data.class = "O(n log n)";
}

int	param_manager(int ac, char **av, t_params *flag, t_stack **a)
{
	int	start;

	if (ac < 2)
		return (0);
	init_flag(flag);
	start = parse_flag(av, flag);
	if (start <= 0)
		return (0);
	if (!is_av_valid(av, start))
		return (0);
	*a = ft_create_stack(av, start);
	if (!*a)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_params	flag;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (!param_manager(ac, av, &flag, &a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	//printf("--- AVANT LE TRI ---\n");
	//print_stacks(a, b);
	//printf("--------------------\n\n");
	insertion_sort(&a, &b, &flag);
	//printf("\n--- APRES LE TRI ---\n");
	//print_stacks(a, b);
	ft_free_stack(&a);
	return (0);
}
