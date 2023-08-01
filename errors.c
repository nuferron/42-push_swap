#include "push_swap.h"

long long	ft_atoll(char *str)
{
	int			i;
	long long	num;
	int			neg;

	i = 0;
	num = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * neg);
}

int	is_duplicated(int total, int i, int num)
{
	static int	*elements = NULL;
	int			j;

	j = 0;
	if (!elements)
	{
		elements = (int *)ft_calloc(total, sizeof (int));
		if (!elements)
			return (-1);
	}
	while (j < i)
	{
		if (elements[j] == num)
			return (-1);
		j++;
	}
	elements[i] = num;
	return (0);
}

int	checking_input(int argc, char **input)
{
	int	i;
	int	j;

	i = 1;
	while (input[i] != NULL)
	{
		j = 0;
		if ((input[i][j] == '-' || input[i][j] == '+') && input[i][j++] != '\0')
			j++;
		while (input[i][j] != '\0')
		{
			if (!(input[i][j] >= '0' && input[i][j] <= '9'))
				return (-1);
			j++;
		}
		if (ft_atoll(input[i]) > 2147483647 || ft_atoll(input[i]) < -2147483648)
			return (-1);
		if (is_duplicated(argc, i - 1, ft_atoll(input[i])) == -1)
			return (-1);
		i++;
	}
	return (0);
}
