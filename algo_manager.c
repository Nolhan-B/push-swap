/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:16:31 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/15 09:46:38 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_disorder(t_stack *a)
{
	int			wrong;
	int			total_pairs;
	t_stack		*i;
	t_stack		*j;

	if (!a || !a->next)
		return (0.00);
	total_pairs = 0;
	wrong = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				wrong++;
			j = j->next;
		}
		i = i->next;
	}
	return (((double)wrong / total_pairs) * 100);
}

static void	ft_print_bench(t_params *flags, double dis)
{
	int	*ops;

	if (flags->bench <= 0)
		return ;
	ops = flags->data.ops;
	ft_printf_stderr("[bench] disorder: %f%%\n", dis);
	ft_printf_stderr("[bench] strategy: %s / %s\n",
		flags->data.strat, flags->data.class);
	ft_printf_stderr("[bench] total_ops: %d\n", flags->data.total);
	ft_printf_stderr("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ops[SA], ops[SB], ops[SS], ops[PA], ops[PB]);
	ft_printf_stderr("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ops[RA], ops[RB], ops[RR], ops[RRA], ops[RRB], ops[RRR]);
}

static void	ft_select_sort(t_stack **a, t_stack **b, t_params *flag)
{
	double	dis;

	dis = ft_disorder(*a);
	if (flag->adaptive == 1)
	{
		if (dis < 20.0)
		{
			ft_set_strat(flag, "Adaptive (Insertion)", "O(n2)", 1);
		}
		else if (dis >= 20.0 && dis < 50.0)
		{
			ft_set_strat(flag, "Adaptive (Chunk-based)", "O(n√n)", 2);
		}
		else if (dis >= 50.0)
		{
			ft_set_strat(flag, "Adaptive (Butterfly Sort)", "O(n log n)", 3);
		}
	}
	if (flag->simple == 1)
		insertion_sort(a, b, flag);
	else if (flag->medium == 1)
		medium_sort(a, b, flag);
	else if (flag->complex == 1)
		complex_sort(a, b, flag);
	ft_print_bench(flag, dis);
}

static int	param_manager(int ac, char **av, t_params *flag, t_stack **a)
{
	int		start;
	int		do_free;
	char	**arg;

	do_free = 0;
	if (ac < 2)
		return (0);
	init_flag(flag);
	start = parse_flag(av, flag);
	if (start <= 0)
		return (0);
	if (use_split(ac, av, start))
	{
		arg = ft_split(av[start], ' ');
		do_free = 1;
		start = 0;
	}
	else
		arg = av;
	if (!ft_stack_creation(arg, start, do_free, a))
		return (0);
	ft_index_stack_elements(*a);
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
	ft_select_sort(&a, &b, &flag);
	ft_free_stack(&a);
	return (0);
}
