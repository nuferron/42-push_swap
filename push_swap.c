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

int	distributor(t_stack **a, t_stack **b)
{
	int	max_id;
	int voltes = 0;

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
	return (voltes);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b = NULL;
	int		i;
	int		voltes = 0;

	i = 1;
	if (argc < 2 || argv[1][0] == '\0' || checking_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	creating_stack(argc, argv, &a);
	//print_stack(a, "initial stack:");
	if (is_sorted(a) == 0)
		return (ft_printf("ALREADY SORTED! 😎\n"));
	voltes = distributor(&a, &b);
	if (voltes == 550)
		ft_printf("NOT SORTED! 🤬\nFUCK\n");
	//ft_printf("\nMOV COUNT: %d\n", voltes);
	if (is_sorted(a) == 0 && (last_node(a))->id == is_max(a)
		&& a->id == 0)
		ft_printf("SORTED! 🥳\n");
	else
		ft_printf("NOT SORTED! 🤬\n\n");
	//print_stack(b, "stack b:");
	//print_stack(a, "stack a:");
}
