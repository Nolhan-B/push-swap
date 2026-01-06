/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:23:10 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/06 14:58:23 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a)
{
	if (ft_lstsize(*a) == 2)
		sort_two(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else 
		return ;
}

void	init_stack_b(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
}

int	get_target_pos(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		pos;
	int		target;

	tmp = b;
	pos = 0;
	target = get_max_pos(b);
	while (tmp->next)
	{
		if (a->value < tmp->value && a->value > tmp->next->value)
			return (pos + 1);
		tmp = tmp->next;
		pos++;
	}
	if (a->value < tmp->value && a->value > b->value)
		target = 0;
	return (target);
}

void	final_rotate_b(t_stack **b)
{
	int	max_pos;
	int	size;

	max_pos = get_max_pos(*b);
	size = ft_lstsize(*b);
	if (max_pos <= size / 2)
		while (max_pos-- > 0)
			rb(b);
	else
		while (size - max_pos++ > 0)
			rrb(b);
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) <= 3)
		return (small_sort(a));
	init_stack_b(a, b);
	while (*a)
	{
		move_stack_b(b, get_target_pos(*a, *b));
		pb(a, b);
	}
	final_rotate_b(b);
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

// int main(void)
// {
// 	t_stack *a = NULL;
// 	t_stack *b = NULL;

// 	// Ajout de valeurs en dur : 5, 2, 10, 8, 3
// 	// Utilise tes propres fonctions (ici j'utilise des noms standards)
// 	ft_lstadd_back(&a, ft_lstnew(5));
// 	ft_lstadd_back(&a, ft_lstnew(4));
// 	ft_lstadd_back(&a, ft_lstnew(3));
// 	ft_lstadd_back(&a, ft_lstnew(2));
// 	ft_lstadd_back(&a, ft_lstnew(1));
// 	ft_lstadd_back(&a, ft_lstnew(20));
// 	ft_lstadd_back(&a, ft_lstnew(6));
// 	ft_lstadd_back(&a, ft_lstnew(12));
// 	ft_lstadd_back(&a, ft_lstnew(98));
// 	ft_lstadd_back(&a, ft_lstnew(45));
// 	ft_lstadd_back(&a, ft_lstnew(63));
// 	ft_lstadd_back(&a, ft_lstnew(78));
// 	ft_lstadd_back(&a, ft_lstnew(95));
// 	ft_lstadd_back(&a, ft_lstnew(32));
// 	ft_lstadd_back(&a, ft_lstnew(34));
// 	ft_lstadd_back(&a, ft_lstnew(1));

// // 	printf("--- AVANT LE TRI ---\n");
// // 	print_stacks(a, b);
// // 	printf("--------------------\n\n");

// // 	// Lancement de ton algo
// // 	insertion_sort(&a, &b);

// 	printf("\n--- APRES LE TRI ---\n");
// 	print_stacks(a, b);

// 	return (0);
// }