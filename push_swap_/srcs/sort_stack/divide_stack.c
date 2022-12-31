/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:41:34 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:50:58 by vfries           ###   ########lyon.fr   */
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

t_list_i	*divide_a(t_list_i **a, t_order order,
				t_list_i **sorting_instructions)
{
	int			median;
	t_list_i	*b;

	b = NULL;
	median = get_median(*a);
	while (elems_left_to_push(*a, median, order))
	{
		while (should_be_pushed((*a)->content, median, order) == false)
			rotate_a(a, sorting_instructions);
		push_b(a, &b, sorting_instructions);
	}
	return (b);
}
