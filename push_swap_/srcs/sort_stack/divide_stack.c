/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:41:34 by vfries            #+#    #+#             */
/*   Updated: 2023/01/02 20:24:21 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "push_swap_lib.h"
#include <stddef.h>

/*
 * This function technically returns an average.
 * Since I replaced numbers with their sorted indexes,
 * the median and average are the same.
  */
static int	get_median(t_list_i *stack)
{
	int	size;
	int	total;

	size = 0;
	total = 0;
	while (stack != NULL)
	{
		size++;
		total += stack->content;
		stack = stack->next;
	}
	return (total / size);
}

t_list_i	*divide_stack(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions)
{
	int			median;
	int			nb_rotate;
	t_list_i	*new_stack;

	new_stack = NULL;
	median = get_median(*stack);
	nb_rotate = 0;
	while (elems_left_to_push(*stack, median, orders.current))
	{
		while (should_be_pushed((*stack)->content, median, orders.current)
			== false)
		{
			rotate_stack(stack, orders, sorting_instructions);
			nb_rotate++;
		}
		push_elem(stack, &new_stack, orders, sorting_instructions);
	}
	while (nb_rotate-- > 0)
		reverse_rotate_stack(stack, orders, sorting_instructions);
	return (new_stack);
}

typedef struct s_limiters
{
	int		low;
	int		high;
	t_order	order;
}	t_limiters;

static t_list_i	*divide_initial_stack(t_list_i **a,
					t_list_i **new_stack_2, t_limiters limiters,
					t_list_i **sorting_instructions)
{
	t_list_i	*new_stack_1;

	new_stack_1 = NULL;
	while (elems_left_to_push(*a, limiters.high, limiters.order))
	{
		if (should_be_pushed((*a)->content, limiters.low, limiters.order))
		{
			push_b(a, &new_stack_1, sorting_instructions);
			if (*new_stack_2 != NULL)
				rotate_b(&new_stack_1, sorting_instructions);
		}
		else if (should_be_pushed((*a)->content, limiters.high, limiters.order))
			push_b(a, new_stack_2, sorting_instructions);
		else
			rotate_a(a, sorting_instructions);
	}
	return (new_stack_1);
}

t_list_i	*get_semi_sorted_stack(t_list_i	**a, t_list_i	**new_stack_2,
				t_order order, t_list_i	**sorting_instructions)
{
	t_limiters	limiters;

	*new_stack_2 = NULL;
	limiters.order = order;
	if (order == ASCENDING)
	{
		limiters.low = ft_lsti_size(*a) / 3;
		limiters.high = limiters.low * 2;
	}
	else
	{
		limiters.high = ft_lsti_size(*a) / 3;
		limiters.low = limiters.high * 2;
	}
	return (divide_initial_stack(a, new_stack_2,
			limiters, sorting_instructions));
}
