/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbilyj <nbilyj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:41:52 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/06 14:14:08 by nbilyj           ###   ########.fr       */
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

typedef struct s_params
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_params;

//STACK_UTILS_AB_FUNCTION.C
void		swap(t_stack **x);
void		rotate(t_stack **x);
void		reverse_rotate(t_stack **x);

//SORT_UTILS_A.C
void		sa(t_stack **a);
void		pa(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rra(t_stack **a);

//SORT_UTILS_B.C
void		sb(t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		rb(t_stack **b);
void		rrb(t_stack **b);

//SORT_UTILS_AB.C
void		ss(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);

///////////////////////////////////////////////////

//FT_UTILS.C
long		ft_atol(const char *nptr);


// FT_LST_UTILS.C
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int content);
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
t_stack		*ft_create_stack(char **av, int start);


//CHECK_ERRORS.C
int			is_av_valid(char *av);
void		ft_free_stack(t_stack **stack);

//INSERTION_SORT.C
void 		print_stacks(t_stack *a, t_stack *b);

//INSERTION_SORT_UTILS.C
int			get_max_pos(t_stack *b);
void		sort_two(t_stack **a);
void		move_stack_b(t_stack **b, int target_pos);
void		sort_three(t_stack **a);

#endif