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

t_stack		*new_node(int num, int id);
t_stack		*last_node(t_stack *stack);
void		add_back(t_stack **stack, t_stack *new);
void		swap(t_stack **stack);
void		push(t_stack **src, t_stack **dst);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
long long	ft_atoll(char *str);
int			is_duplicated(int total, int i, int num);
int			checking_input(int argc, char **input);
int			getting_max_id(t_stack *stack);
int			is_sorted(t_stack *stack);
void		print_stack(t_stack *stack, char *str);
int			sorting_three(t_stack **a, t_stack *last);
int			sorting_five(t_stack **a, t_stack **b, t_stack *last, char *prev);
int			consec(int first, int second);

#endif
