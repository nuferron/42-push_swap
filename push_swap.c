#include "push_swap.h"

int	free_mem(t_stack *stack)
{
	t_stack	*tmp;

	while (stack->next != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return (-1);
}

int	getting_a(t_stack **stack, int num, int id)
{
	t_stack	*tmp;

	tmp = new_node(num, id);
	if (!tmp)
		return (free_mem(*stack));
	if (*stack == NULL)
		*stack = tmp;
	else
		add_back(stack, tmp);
	return (0);
}

int	getting_id(int argc, int *elements, int num)
{
	int	i;
	int	id;

	i = 0;
	id = 0;
	while ((i + 1) < argc)
	{
		if (elements[num] > elements[i])
			id++;
		i++;
	}
	return (id);
}

int	creating_stack(int argc, char **input, t_stack **stack)
{
	int	*nums;
	int	i;
	int	aux;

	i = 1;
	aux = 0;
	nums = ft_calloc(argc - 1, sizeof (int));
	if (!nums)
		return (-1);
	while (i < argc)
	{
		nums[aux] = ft_atoll(input[i]);
		aux++;
		i++;
	}
	i = 0;
	while ((i + 1) < argc)
	{
		aux = getting_a(stack, nums[i], getting_id (argc, nums, i));
		if (aux == -1)
			return (-1);
		i++;
	}
	return (0);
}

void	print_stack(t_stack *stack, char *str)
{
	if (!stack)
		return ;
	while (stack->next != NULL)
	{
		//ft_printf("%s value: %d\n", str, stack->input);
		ft_printf("%s id: %d\n", str, stack->id);
		stack = stack->next;
	}
	if (stack->next == NULL)
	{
		//ft_printf("%s value: %d\n", str, stack->input);
		ft_printf("%s id: %d\n", str, stack->id);
	}
	ft_printf("\n");
}

int	distributor(t_stack **a, t_stack **b)
{
	int	max_id;

	max_id = getting_max_id(*a);
	if (max_id == 1)
		swap(a, 's', 'a');
	else if (max_id == 2)
		sorting_three(a);
	else if (max_id == 3)
		sorting_four(a, b, last_node(*a));
	else if (max_id == 4)
		sorting_five(a, b);
	else
		ft_printf("\n\nWTF SORTED!\n\n");
	return (0);
}

/*int	print_moves(t_stack **a, t_stack **b, char m, void (*ft)(t_stack**))
{
	if (m == 'b')
	{
		push(a, b);
		return (ft_printf("pb\n"));
	}
	if (m == 'a')
	{
		push(b, a);
		return (ft_printf("pa\n"));
	}
	else
		ft(a);
	if (m == 's')
		return (ft_printf("sa\n"));
	if (m == 'r')
		return (ft_printf("ra\n"));
	if (m == 'R')
		return (ft_printf("rra\n"));
	return (0);
}*/

void	print_moves(char move, char stack)
{
	if (move == 'S')
		ft_printf("ss\n");
	else if (move == 'R')
		ft_printf("rr\n");
	else if (move == 'V')
		ft_printf("rrr");
	if (move == 'S' || move == 'R' || move == 'V')
		return ;
	if (move == 's')
		ft_printf("s");
	else if (move == 'r')
		ft_printf("r");
	else if (move == 'v')
		ft_printf("rr");
	else if (move == 'p')
		ft_printf("p");
	if (stack == 'a')
		ft_printf("a\n");
	else if (stack == 'b')
		ft_printf("b\n");
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
	print_stack(a, "initial stack:");
	if (is_sorted(a) == 0)
		return (ft_printf("ALREADY SORTED! 😎\n"));
	voltes = distributor(&a, &b);
	if (voltes == 12)
		ft_printf("NOT SORTED! 🤬\nFUCK\n");
		write(1, "FUCK 🤬\n", 5);
	ft_printf("\nMOV COUNT: %d\n", voltes);
	if (is_sorted(a) == 0 && (last_node(a))->id == getting_max_id(a)
		&& a->id == 0)
		ft_printf("SORTED! 🥳\n\n");
	else
		ft_printf("NOT SORTED! 🤬\n\n");
	print_stack(b, "stack b:");
	print_stack(a, "stack a:");
}
