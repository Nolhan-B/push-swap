/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:16:31 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/07 13:51:38 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_select_sort(t_stack **a, t_stack **b, t_params *flag)
// {
	
// }
double	ft_disorder(t_stack *a)
{
	int		wrong;
	int		total_pairs;
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
	return ((double)wrong / total_pairs);
}

void	ft_print_bench(t_params *flags, double dis)
{	
	int	*ops;
	if (flags->bench <= 0)
		return ;
	ops = flags->data.ops;
	printf("[bench] disorder: %.2f%%\n", (dis * 100));
	printf("[bench] strategy: %s / %s\n",flags->data.strat, flags->data.class);
	printf("[bench] total_ops: %d\n",flags->data.total);
	printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ops[SA], ops[SB], ops[SS], ops[PA], ops[PB]);
	printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ops[RA], ops[RB], ops[RR], ops[RRA], ops[RRB], ops[RRR]);	
}

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
	double		dis;
	
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
	dis = ft_disorder(a);
	insertion_sort(&a, &b, &flag); // A remplacer par une fonction qui choisis le plus adapte avec le disorder si adaptive = 1
	/* faut aussi que selon le choix du type de tri ca modifie la class de flags */
	//ft_select_sort(&a, &b, &flag);
	ft_print_bench(&flag, dis);
	//printf("\n--- APRES LE TRI ---\n");
	//print_stacks(a, b);
	ft_free_stack(&a);
	return (0);
}
