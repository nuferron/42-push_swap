#include "push_swap.h"

void	swap(t_stack **stack)
{
	int	tmp_input;
	int	tmp_id;

	tmp_input = (*stack)->input;
	tmp_id = (*stack)->id;
	(*stack)->input = (*stack)->next->input;
	(*stack)->id = (*stack)->next->id;
	(*stack)->next->input = tmp_input;
	(*stack)->next->id = tmp_id;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!(*dst))
	{
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = NULL;
	}
	else
	{
		tmp = (*dst);
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = tmp;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second;

	last = last_node(*stack);
	second = (*stack)->next;
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = second;
}

void	reverse_rotate(t_stack **stack)
{
	int		n;
	int		m;
	int		n1;
	int		m1;
	t_stack	*fil;

	fil = (*stack);
	n = (*stack)->input;
	n1 = (*stack)->id;
	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		m = (*stack)->input;
		m1 = (*stack)->id;
		(*stack)->input = n;
		(*stack)->id = n1;
		n = m;
		n1 = m1;
	}
	(*stack) = fil;
	(*stack)->input = n;
	(*stack)->id = n1;
}
