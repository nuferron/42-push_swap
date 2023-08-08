#include "push_swap.h"

void	print_stack(t_stack *stack, char *str)
{
	if (!stack)
		return ;
	while (stack->next != NULL)
	{
		ft_printf("%s id: %d\n", str, stack->id);
		stack = stack->next;
	}
	if (stack->next == NULL)
		ft_printf("%s id: %d\n", str, stack->id);
	ft_printf("\n");
}

void	distributor(t_stack **a, t_stack **b)
{
	int	max_id;

	max_id = is_max(*a);
	if (max_id == 1)
		swap(a, 's', 'a');
	else if (max_id == 2)
		sorting_three(a);
	else if (max_id == 3)
		sorting_four(a, b, last_node(*a));
	else if (max_id == 4)
		sorting_five(a, b);
	else
		sorting_more(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b = NULL;
	int		i;

	i = 1;
	if (argc < 2)
		return (ft_printf("\n"));
	if (argv[1][0] == '\0' || checking_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	creating_stack(argc, argv, &a);
	if (is_sorted(a) == 0)
	{
		free_mem(a);
		return (ft_printf("\n"));
	}
	distributor(&a, &b);
	free_mem(a);
}
