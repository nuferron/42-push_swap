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

#include <limits.h>

int	consec(int first, int second)
{
	if (first - second == 1)
		return (1);
	else if (first - second == -1)
		return (1);
	return (0);
}

/*int	sort_deg(t_stack *a)
{
	int	deg;

	deg = 1;
	while (a->next != NULL)
	{
		if (a->id - a->next->id == -1)
			deg++;
		a = a->next;
	}
	return (deg);
}*/

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b = NULL;
	int		i;

	i = 1;
	if (argc < 2 || argv[1][0] == '\0' || checking_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	creating_stack(argc, argv, &a);
	print_stack(a, "initial stack:");
	if (is_sorted(a) == 0)
		return (ft_printf("Already sorted\n"));
	//fixing_stack(&a, &b, getting_max_id(a));
	int voltes = 0;
	/*while (is_sorted(a) != 0 && voltes < 12)
	{
		sorting_three(&a, last_node(a));
		print_stack(a, "stack a:");
		voltes++;
		if (voltes == 12)
			write(1, "FUCK\n", 5);
	}*/
	char	prev = 'w';
	while (is_sorted(a) != 0 && voltes < 12)
	{
		sorting_five(&a, &b, last_node(a), &prev);
		print_stack(a, "stack a:");
		voltes++;
		if (voltes == 12)
			write(1, "FUCK\n", 5);
	}
	ft_printf("MOV COUNT: %d\n", voltes);
	//ft_printf("grau d'ordre: %d\n", sort_deg(a));
	print_stack(b, "stack b:");
	print_stack(a, "stack a:");
}
