/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:31:31 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/05 11:17:40 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_dup(t_stack *stack, int value)
{
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_stack	*ft_create_stack(char **av)
{
	t_stack	*a;
	t_stack	*new;
	int		i;
	int		value;

	a = NULL;
	i = 1;
	while (av[i])
	{
		value = (int)ft_atol(av[i]);
		if (is_dup(a, value))
		{
			ft_free_stack(&a);
			return (NULL);
		}
		new = ft_lstnew(value);
		if (!new)
		{
			ft_free_stack(&a);
			return (NULL);
		}
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}
