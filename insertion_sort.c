/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:23:10 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/06 13:33:38 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_stack *b)
{
	int	i;
	int	max_value;
	int max_pos;
	t_stack	*tmp;
	
	i = 0;
	max_pos = 0;
	tmp = b;
	max_value = tmp->value;
	while (tmp)
	{
		if (tmp->value > max_value)
		{
			max_value = tmp->value;
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_pos);
}
static void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	move_stack_b(t_stack **b, int target_pos)
{
	int	size = ft_lstsize(*b);

	if (target_pos <= size / 2)
	{
		while (target_pos-- > 0)
			rb(b);
	}
	else
	{
		while (size > target_pos)
		{
			rrb(b);
			target_pos++;
		}
	}
}

static void	sort_three(t_stack **a)
{
	int	n1 = (*a)->value;
	int	n2 = (*a)->next->value;
	int	n3 = (*a)->next->next->value;

	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(a);
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		sa(a);
		rra(a);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(a);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(a);
		ra(a);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a);
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	t_stack	*tmpb;
	int		pos;
	int		target_pos;
	int		max_pos;
	int		size_b;

	if (ft_lstsize(*a) == 3)
	{
		sort_three(a);
		return ;
	}
	if (ft_lstsize(*a) == 2)
	{
		sort_two(a);
		return ;
	}
	if (ft_lstsize(*a) > 3)
	{
		pb(a, b);
		pb(a, b);
	}

	while (*a)
	{
		tmpb = *b;
		pos = 0;
		target_pos = get_max_pos(*b);
		while (tmpb->next)
		{
			if ((*a)->value < tmpb->value && (*a)->value > tmpb->next->value)
			{
				target_pos = pos + 1;
				break ;
			}
			tmpb = tmpb->next;
			pos++;
		}
		if (!tmpb->next && target_pos == get_max_pos(*b))
		{
			if ((*a)->value < tmpb->value && (*a)->value > (*b)->value)
				target_pos = 0;
		}
		move_stack_b(b, target_pos);
		pb(a, b);
	}
	max_pos = get_max_pos(*b);
	size_b = ft_lstsize(*b);
	if (max_pos <= size_b / 2)
	{
		while (max_pos-- > 0)
			rb(b);
	}
	else
	{
		while (size_b - max_pos++ > 0)
			rrb(b);
	}
	while (*b)
	pa(a, b);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++TEST++++++++++++++++++++++++++++++++++

// Fonction pour afficher la pile et voir ce qui se passe

void print_stacks(t_stack *a, t_stack *b)
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
			printf("      "); // Espace si A est plus courte que B
			
		if (b)
		{
			printf("             %d\n", b->value);
			b = b->next;
		}
		else
			printf("\n");
	}
	printf("--------------------------------\n");
}


t_stack	*find_min(t_stack *a)
{
	t_stack	*min_value;
	t_stack	*current;

	if (!a)
		return (NULL);

	current = a->next;
	min_value = a;
	while (current)
	{
		if (min_value->value > current->value)
			min_value = current;
		current = current->next;
	}
	return (min_value);
}
int	get_index(t_stack *target, t_stack *a)
{
	int	index;

	index = 0;
	while (a)
	{
		if (a == target)
			return (index);
		index++;
		a = a->next;
	}
	return (-1);
}


int main(void)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	// Ajout de valeurs en dur : 5, 2, 10, 8, 3
	// Utilise tes propres fonctions (ici j'utilise des noms standards)
	ft_lstadd_back(&a, ft_lstnew(5));
	ft_lstadd_back(&a, ft_lstnew(4));
	ft_lstadd_back(&a, ft_lstnew(3));
	ft_lstadd_back(&a, ft_lstnew(2));/*
	ft_lstadd_back(&a, ft_lstnew(1));
	ft_lstadd_back(&a, ft_lstnew(20));
	ft_lstadd_back(&a, ft_lstnew(6));
	ft_lstadd_back(&a, ft_lstnew(12));
	ft_lstadd_back(&a, ft_lstnew(98));
	ft_lstadd_back(&a, ft_lstnew(45));
	ft_lstadd_back(&a, ft_lstnew(63));
	ft_lstadd_back(&a, ft_lstnew(78));
	ft_lstadd_back(&a, ft_lstnew(95));
	ft_lstadd_back(&a, ft_lstnew(32));
	ft_lstadd_back(&a, ft_lstnew(34));
	ft_lstadd_back(&a, ft_lstnew(1));

	printf("--- AVANT LE TRI ---\n");
	print_stacks(a, b);
	printf("--------------------\n\n");

	// Lancement de ton algo
	insertion_sort(&a, &b);

	printf("\n--- APRES LE TRI ---\n");
	print_stacks(a, b);
	
	return (0);
*/
	}