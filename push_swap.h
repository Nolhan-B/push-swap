/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:41:52 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/05 10:40:41 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h> // a supprimer a la fin 
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_stack;

long		ft_atol(const char *nptr);
int			ft_lstsize(t_stack *lst);

//SIMPLE_SORT.C
int			get_index(t_stack *target, t_stack *a);
t_stack		*find_min(t_stack *a);
void		simple_sort(t_stack	**a, t_stack **b);

//STACK_UTILS.C
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int content);
int			is_dup(t_stack *stack, int value);
t_stack		*ft_create_stack(char **av);

//SORT_UTILS.C
void		sa(t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rra(t_stack **a);
void		pa(t_stack **a, t_stack **b);
void		rb(t_stack **b);
void		rrb(t_stack **b);

//CHECK_ERRORS.C
int			is_av_valid(char *av);
void		ft_free_stack(t_stack **stack);

//MEDIUM_SORT.C
void		ft_assign_index(t_stack *a);
int			ft_sqrt(int n);
int			find_index(t_stack *b, int current_index);
void		ft_back_to_a(t_stack **a, t_stack **b, int size);
void		chunk_sort(t_stack **a, t_stack **b);

#endif