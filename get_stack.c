#include "push_swap.h"

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
		nums[aux++] = ft_atoll(input[i++]);
	i = 0;
	while ((i + 1) < argc)
	{
		aux = getting_a(stack, nums[i], getting_id (argc, nums, i));
		if (aux == -1)
		{
			free(nums);
			return (-1);
		}
		i++;
	}
	free(nums);
	return (0);
}
