/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:23:10 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/06 11:00:24 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_stack *b)
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
void sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
        sa(a);
}

void	move_stack_b(t_stack **b, int target_pos)
{
	int size = ft_lstsize(*b);

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

void sort_three(t_stack **a)
{
    int n1 = (*a)->value;
    int n2 = (*a)->next->value;
    int n3 = (*a)->next->next->value;

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
	t_stack *tmpb;
	int pos;
	int target_pos;

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
	int max_pos = get_max_pos(*b);
	int size_b = ft_lstsize(*b);

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
#include "push_swap.h"
#include <stdio.h>


void	rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*prev_last;

	if (!*b || !(*b)->next)
		return ;
	prev_last = *b;
	while (prev_last->next->next)
	{
		prev_last = prev_last->next;
	}
	temp = prev_last->next;
	prev_last->next = NULL;
	temp->next = *b;
	*b = temp;
	write(1, "rrb\n", 4);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	sa(t_stack **a)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	if (!*a || !(*a)->next)
	{
		return ;
	}
	n1 = *a;
	n2 = (*a)->next;
	n3 = (*a)->next->next;
	*a = n2;
	n1->prev = n2;
	n2->next = n1;
	n2->prev = NULL;
	if (n3)
	{
		n3->prev = n1;
		n1->next = n3;
	}
	else
		n1->next = NULL;
	write(1, "sa\n", 3);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

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
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
	return ;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*x;

	x = malloc(sizeof(t_stack));
	if (!x)
		return (NULL);
	x->value = content;
	x->next = NULL;
	x->prev = NULL;
	x->index = -1;
	return (x);
}
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
	{
		return ;
	}
	temp = *a;
	*a = temp->next;
	if (*a != NULL )
		(*a)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	if (*b == NULL)
	{
		*b = temp;
	}
	else
	{
		temp->next = *b;
		(*b)->prev = temp;
		*b = temp;
	}
	write(1, "pb\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
	{
		last = last->next;
	}
	last->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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

void	ra(t_stack **a)
{
	t_stack	*n_last;
	t_stack	*head;

	if (!(*a) || !(*a)->next)
		return ;
	n_last = ft_lstlast(*a);
	head = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	n_last->next = head;
	head->prev = n_last;
	head->next = NULL;
	write(1, "ra\n", 3);
}
void	rra(t_stack **a)
{
	t_stack	*n_last;
	t_stack	*n_head;
	t_stack	*n_lminus1;

	if (!*a || !(*a)->next)
		return ;
	n_last = ft_lstlast(*a);
	n_head = *a;
	n_lminus1 = n_last->prev;
	*a = n_last;
	n_last->prev = NULL;
	n_lminus1->next = NULL;
	n_last->next = n_head;
	n_head->prev = n_last;
	write(1, "rra\n", 4);
}

void	simple_sort(t_stack	**a, t_stack **b)
{
	t_stack	*min_value;
	int		size;
	int		index;

	while (*a)
	{
		min_value = find_min(*a);
		index = get_index(min_value, *a);
		size = ft_lstsize(*a);
		if (index <= size / 2)
		{
			while (index-- > 0)
				ra(a);
		}
		else
		{
			while (index++ < size)
				rra(a);
		}
		pb(a, b);
	}
	while (*b)
		pa(a, b);
	return ;
}


int main(void)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	// Ajout de valeurs en dur : 5, 2, 10, 8, 3
	// Utilise tes propres fonctions (ici j'utilise des noms standards)
	ft_lstadd_back(&a, ft_lstnew(5));
	ft_lstadd_back(&a, ft_lstnew(4));
	ft_lstadd_back(&a, ft_lstnew(3));/*
	ft_lstadd_back(&a, ft_lstnew(2));
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
	ft_lstadd_back(&a, ft_lstnew(1));*/

	printf("--- AVANT LE TRI ---\n");
	print_stacks(a, b);
	printf("--------------------\n\n");

	// Lancement de ton algo
	insertion_sort(&a, &b);

	printf("\n--- APRES LE TRI ---\n");
	print_stacks(a, b);
	
	return (0);
}