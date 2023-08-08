#include "push_swap.h"

t_stack	*new_node(int num, int id)
{
	t_stack	*element;

	element = (t_stack *)malloc(sizeof (t_stack));
	if (!element)
		return (NULL);
	element->input = num;
	element->id = id;
	element->next = NULL;
	return (element);
}

t_stack *last_node(t_stack *stack)
{
	if (!stack)
		return (stack);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack *aux;

	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	aux = last_node(*stack);
	aux->next = new;
}

int	free_mem(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return (-1);
}
