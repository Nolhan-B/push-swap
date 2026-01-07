/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:41:52 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/07 15:03:17 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h> // a supprimer a la fin 
# include <unistd.h>
# include <limits.h>

#define SA 0
#define SB 1
#define SS 2
#define PA 3
#define PB 4
#define RA 5
#define RB 6
#define RR 7
#define RRA 8
#define RRB 9
#define RRR 10

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_stack;

typedef struct s_bench
{
	int		ops[11];
	int		total;
	char	*strat;
	char	*class;
} t_bench;

typedef struct s_params
{
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	int		bench;
	t_bench	data;
}	t_params;


//STACK_UTILS_AB_FUNCTION.C
void		swap(t_stack **x);
void		rotate(t_stack **x);
void		reverse_rotate(t_stack **x);

//SORT_UTILS_A.C
void		sa(t_stack **a, t_params *flags);
void		pa(t_stack **a, t_stack **b, t_params *flags);
void		ra(t_stack **a, t_params *flags);
void		rra(t_stack **a, t_params *flags);

//SORT_UTILS_B.C
void		sb(t_stack **b, t_params *flags);
void		pb(t_stack **a, t_stack **b, t_params *flags);
void		rb(t_stack **b, t_params *flags);
void		rrb(t_stack **b, t_params *flags);

//SORT_UTILS_AB.C
void		ss(t_stack **a, t_stack **b, t_params *flags);
void		rr(t_stack **a, t_stack **b, t_params *flags);
void		rrr(t_stack **a, t_stack **b, t_params *flags);

///////////////////////////////////////////////////

//FT_UTILS.C
long		ft_atol(const char *nptr);
int			ft_strcmp(char *s1, char *s2);

// FT_LST_UTILS.C
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int content);
int			ft_lstsize(t_stack *lst);

//STACK_UTILS.C
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int content);
int			is_dup(t_stack *stack, int value);
t_stack		*ft_create_stack(char **av, int start);


//CHECK_ERRORS.C
int			is_av_valid(char **av, int start);
void		ft_free_stack(t_stack **stack);

//INSERTION_SORT.C
void		insertion_sort(t_stack **a, t_stack **b, t_params *flags);
//MEDIUM_SORT.C
// void		ft_assign_index(t_stack *a);
// int			ft_sqrt(int n);
// int			find_index(t_stack *b, int current_index);
// void		ft_back_to_a(t_stack **a, t_stack **b, int size);
// void		chunk_sort(t_stack **a, t_stack **b);
void 		print_stacks(t_stack *a, t_stack *b);

//INSERTION_SORT_UTILS.C
int			get_max_pos(t_stack *b);
void		sort_two(t_stack **a, t_params *flags);
void		move_stack_b(t_stack **b, int target_pos, t_params *flags);
void		sort_three(t_stack **a, t_params *flags);

//FT_PRINTF_STDERR.C
int			ft_printf(const char *str, ...);

//PRINTF_UTILS.C
int			ft_putchar(unsigned int c);
int			ft_putnbr(int n);
int			ft_putstr(const char *s);

#endif