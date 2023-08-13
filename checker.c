#include "push_swap.h"

void	reading_moves(t_stack **a, t_stack **b)
{
	char	*move;

	move = (char *)ft_calloc(4, sizeof (char));
	read(1, move, 3);
	if (ft_strcmp(move, "sa") == 0)
		swap(a, '0');
	free(move);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 1;
	b = NULL;
	if (argc < 2)
		return (-1);
	if (argv[1][0] == '\0' || checking_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	creating_stack(argc, argv, &a);
	if (is_sorted(a) == 0)
	{
		free_mem(a);
		return (ft_printf("OK\n"));
	}
	reading_moves(&a, &b);
	free_mem(a);
	return (0);
}
