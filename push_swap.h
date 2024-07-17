/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:03:59 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 23:34:55 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				input;
	int				id;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void		add_back(t_stack **stack, t_stack *new);
int			checking_input(int argc, char **input);
int			creating_stack(int argc, char **input, t_stack **stack);
int			element_num(t_stack *stack);
long long	ft_atoll(char *str);
int			free_mem(t_stack *stack);
int			getting_a(t_stack **stack, int num, int id);
int			getting_id(int argc, int *elements, int num);
char		*is_duplicated(int total, int i, int num);
int			is_max(t_stack *stack);
int			is_min(t_stack *stack);
int			is_sorted(t_stack *stack);
t_stack		*last_node(t_stack *stack);
t_stack		*new_node(int num, int id);
void		print_moves(char move, char stack);
void		print_stack(t_stack *stack, char *str);
void		push(t_stack **src, t_stack **dst, char s);
void		reverse_rotate(t_stack **stack, char s);
void		rotate(t_stack **stack, char s);
void		sorting_five(t_stack **a, t_stack **b);
void		sorting_four(t_stack **a, t_stack **b, t_stack *last);
void		sorting_more(t_stack **a, t_stack **b);
void		sorting_three(t_stack **a);
void		swap(t_stack **stack, char s);

/********************* CHECKER *********************/
int			do_push(t_stack **a, t_stack **b, char *str);
int			do_swap(t_stack **a, t_stack **b, char *str);
int			do_rot(t_stack **a, t_stack **b, char *str);
int			do_rr(t_stack **a, t_stack **b, char *str);

#endif
