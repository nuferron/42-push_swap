#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/libftprintf.h"
# include "ft_printf/libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				input;
	int				id;
	struct s_stack	*next;
}					t_stack;

void		add_back(t_stack **stack, t_stack *new);
int			checking_input(int argc, char **input);
int			creating_stack(int argc, char **input, t_stack **stack);
int			element_num(t_stack *stack);
long long	ft_atoll(char *str);
int			free_mem(t_stack *stack);
int			getting_a(t_stack **stack, int num, int id);
int			getting_id(int argc, int *elements, int num);
int			is_duplicated(int total, int i, int num);
int			is_max(t_stack *stack);
int			is_min(t_stack *stack);
int			is_sorted(t_stack *stack);
t_stack		*last_node(t_stack *stack);
t_stack		*new_node(int num, int id);
void		print_moves(char move, char stack);
void		print_stack(t_stack *stack, char *str);
void		push(t_stack **src, t_stack **dst, char s, char m);
void		reverse_rotate(t_stack **stack, char s, char m);
void		rotate(t_stack **stack, char s, char m);
void		sorting_five(t_stack **a, t_stack **b);
void		sorting_four(t_stack **a, t_stack **b, t_stack *last);
void		sorting_more(t_stack **a, t_stack **b);
void		sorting_three(t_stack **a);
void		swap(t_stack **stack, char m, char s);
int			where_is(t_stack *stack, int num);

#endif
