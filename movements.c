#include "push_swap.h"

void	swap(t_stack **stack, char m, char s)
{
	int	tmp_input;
	int	tmp_id;

	tmp_input = (*stack)->input;
	tmp_id = (*stack)->id;
	(*stack)->input = (*stack)->next->input;
	(*stack)->id = (*stack)->next->id;
	(*stack)->next->input = tmp_input;
	(*stack)->next->id = tmp_id;
	print_moves(m, s);
}

void	push(t_stack **src, t_stack **dst, char m, char s)
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
	print_moves(m, s);
}

void	rotate(t_stack **stack, char m, char s)
{
	t_stack	*last;
	t_stack	*second;

	last = last_node(*stack);
	second = (*stack)->next;
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = second;
	print_moves(m, s);
}

void	reverse_rotate(t_stack **stack, char m, char s)
{
	int		n;
	int		o;
	int		n1;
	int		o1;
	t_stack	*fil;

	fil = (*stack);
	n = (*stack)->input;
	n1 = (*stack)->id;
	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		o = (*stack)->input;
		o1 = (*stack)->id;
		(*stack)->input = n;
		(*stack)->id = n1;
		n = o;
		n1 = o1;
	}
	(*stack) = fil;
	(*stack)->input = n;
	(*stack)->id = n1;
	print_moves(m, s);
}
