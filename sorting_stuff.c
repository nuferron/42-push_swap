#include "push_swap.h"

int	getting_max_id(t_stack *stack)
{
	int	id;

	id = 0;
	while (stack->next != NULL)
	{
		if (stack->id > id)
			id = stack->id;
		stack = stack->next;
	}
	if (stack->id > id)
		id = stack->id;
	return (id);
}

int	is_sorted(t_stack *stack, int max_id)
{
	int	sort;

	sort = 0;
	if (stack->next == NULL)
		return (0);
	while (stack)
	{
		if (stack->id != sort)
			return (-1);
		sort++;
		stack = stack->next;
	}
	if (stack->id != 0 && )
	return (0);
}

int	sorting_three(t_stack **a, t_stack *last)
{
	if ((*a)->id - (*a)->next->id == 1)
	{
		swap(a);
		return (write(1, "sa\n", 3));
	}
	else if ((*a)->id + last->id == 1)
	{
		reverse_rotate(a);
		return (write(1, "rra\n", 4));
	}
	else
	{
		rotate(a);
		return (write(1, "ra\n", 3));
	}
}

/*int one_five_conecteds(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	while(tmp)
	{
		if(tmp->id == 0 && tmp->next && tmp->next->id ==  4)
			return 1;
		if(tmp->id == 4 && tmp->next && tmp->next->id ==  0)
			return 1;
		if(tmp->id == 0 && (*last_node(tmp))->id == 4)
			return 1;
		if(tmp->id == 4 && (*last_node(tmp))->id == 0)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}



int	sorting_five(t_stack **a, t_stack *last, char *prev)
{
	int swap;

	swap = 0;
	// Si primero es mas grande que segundo y no 
	if (((*a)->id > (*a)->next->id) && !one_five_conecteds(a) && ){
		swap = 1;
	}
	// Si es un 1 5 lo paso a 5 1
	if ((*a)->next->id == 0 && (*a)->next->next->id == 4)
		swap = 1;
	if()
}*/

/*int	sorting_five(t_stack **a, t_stack *last, char *prev)
{
	if (*prev != 's' && ((*a)->id - (*a)->next->id == 1 || (*a)->id - (*a)->next->next->id == 1
		|| (*a)->id - (*a)->next->next->id == -1))
	//if (*prev != 's' && ((*a)->id - (*a)->next->id == 1 || consec((*a)->id, (*a)->next->next->id)))
	{
		*prev = 's';
		swap(a);
		return (write(1, "sa\n", 3));
	}
	else if (*prev != 'r' && ((*a)->id - last->id == 1 || (*a)->id - last->id == -1
			|| (*a)->next->id - last->id == 1 || (*a)->next->id - last->id == -1))
	else if (*prev != 'r' && (consec((*a)->id, last->id) || consec((*a)->next->id, last->id)))
	{
		*prev = 'R';
		reverse_rotate(a);
		return(write(1, "rra\n", 4));
	}
	else if (*prev != 'R')
	{
		*prev = 'r';
		rotate(a);
		return (write(1, "ra\n", 3));
	}
	else
	{
		return (ft_printf("no conditions matched\n"));
	}
}*/

int	sorting_five(t_stack **a, t_stack **b, t_stack *last, char *prev)
{
	if (!(*b) && (*a)->id == 0)
	{
		*prev = 'a';
		push(a, b);
		return (write(1, "pb\n", 3));
	}
	if (b && is_sorted(*a) == 1)
	{
		*prev = 'b';
		push(b, a);
		return (write(1, "pa\n", 3));
	}
	if (*prev != 's' && (*a)->id - (*a)->next->id == 1)
	{
		*prev = 's';
		swap(a);
		return (write(1, "sa\n", 3));
	}
	if (*prev != 'r' && consec((*a)->id, last->id) == 1 && (*a)->id <= 3)
	{
		*prev = 'R';
		reverse_rotate(a);
		return (write(1, "rra\n", 4));
	}
	if (*prev != 'R' && consec((*a)->id, last->id) == 1 && (*a)->id > 3)
	{
		*prev = 'r';
		rotate(a);
		return (write(1, "ra\n", 3));
	}
	else
	{
		return (ft_printf("no conditions matched\n"));
	}
}
