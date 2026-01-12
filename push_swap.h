/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbilyj <nbilyj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:41:52 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/08 10:39:08 by nbilyj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h> // À supprimer à la fin
# include <stdarg.h>

/* ************************************************************************** */
/*                                DEFINES                                   */
/* ************************************************************************** */

# define SA  0
# define SB  1
# define SS  2
# define PA  3
# define PB  4
# define RA  5
# define RB  6
# define RR  7
# define RRA 8
# define RRB 9
# define RRR 10

/* ************************************************************************** */
/*                                STRUCTS                                   */
/* ************************************************************************** */

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
}	t_bench;

typedef struct s_params
{
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	int		bench;
	t_bench	data;
}	t_params;

/* ************************************************************************** */
/*                           STACK CORE OPERATIONS                            */
/* ************************************************************************** */

// STACK_UTILS_AB_FUNCTION.C
void		swap(t_stack **x);
void		rotate(t_stack **x);
void		reverse_rotate(t_stack **x);

/* ************************************************************************** */
/*                          SORT OPERATIONS A                                */
/* ************************************************************************** */

// SORT_UTILS_A.C
void		sa(t_stack **a, t_params *flags);
void		pa(t_stack **a, t_stack **b, t_params *flags);
void		ra(t_stack **a, t_params *flags);
void		rra(t_stack **a, t_params *flags);

/* ************************************************************************** */
/*                          SORT OPERATIONS B                                */
/* ************************************************************************** */

// SORT_UTILS_B.C
void		sb(t_stack **b, t_params *flags);
void		pb(t_stack **a, t_stack **b, t_params *flags);
void		rb(t_stack **b, t_params *flags);
void		rrb(t_stack **b, t_params *flags);

/* ************************************************************************** */
/*                        SORT OPERATIONS A+B                                */
/* ************************************************************************** */

// SORT_UTILS_AB.C
void		ss(t_stack **a, t_stack **b, t_params *flags);
void		rr(t_stack **a, t_stack **b, t_params *flags);
void		rrr(t_stack **a, t_stack **b, t_params *flags);

/* ************************************************************************** */
/*                                LIB UTILS                                  */
/* ************************************************************************** */

// FT_UTILS.C
long		ft_atol(const char *nptr);
int			ft_strcmp(char *s1, char *s2);

/* ************************************************************************** */
/*                              LIST UTILS                                   */
/* ************************************************************************** */

// FT_LST_UTILS.C
t_stack		*ft_lstnew(int content);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);

/* ************************************************************************** */
/*                              STACK UTILS                                  */
/* ************************************************************************** */

// STACK_UTILS.C
int			is_dup(t_stack *stack, int value);
t_stack		*ft_create_stack(char **av, int start);
t_stack		*ft_index_stack_elements(t_stack *a);

/* ************************************************************************** */
/*                              ERROR HANDLING                               */
/* ************************************************************************** */

// CHECK_ERRORS.C
int			is_av_valid(char **av, int start);
void		ft_free_stack(t_stack **stack);

/* ************************************************************************** */
/*                              SORTING                                      */
/* ************************************************************************** */

// INSERTION_SORT.C
void		insertion_sort(t_stack **a, t_stack **b, t_params *flags);

// INSERTION_SORT_UTILS.C
int			get_max_pos(t_stack *b);
void		sort_two(t_stack **a, t_params *flags);
void		sort_three(t_stack **a, t_params *flags);
void		move_stack_b(t_stack **b, int target_pos, t_params *flags);

// MEDIUM_SORT.C
void		medium_sort(t_stack **a, t_stack **b, t_params *flags);
void		push_chunks(t_stack **a, t_stack **b, int c_size, t_params *flags);
void		rebuild_stack(t_stack **a, t_stack **b, t_params *flags);
void		bring_max_to_top(t_stack **b, int max_index, t_params *flags);

// COMPLEX_SORT.C
void    	complex_sort(t_stack **a, t_stack **b, t_params *flag);
void  		push_chunks_complex(t_stack **a, t_stack **b, t_params *flag);

/* ************************************************************************** */
/*                              DEBUG / PRINT                                */
/* ************************************************************************** */

void		print_stacks(t_stack *a, t_stack *b);

// FT_PRINTF_STDERR.C
int			ft_printf_stderr(const char *str, ...);

// PRINTF_UTILS.C
int			ft_putchar(unsigned int c);
int			ft_putnbr(int n);
int			ft_putstr(const char *s);

#endif
