/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:41:34 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 12:31:44 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"
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

t_list_i	*divide_stack(t_list_i **stack, int size, t_orders orders)
{
	int			median;
	int			nb_rotate;
	t_list_i	*new_stack;

	new_stack = NULL;
	median = get_median(*stack);
	nb_rotate = 0;
	while (size > 0 && elems_left_to_push(*stack, size, median, orders.current))
	{
		if (should_be_pushed((*stack)->content, median, orders.current))
			push_elem(stack, &new_stack, orders);
		else
		{
			rotate_stack(stack, orders);
			nb_rotate++;
		}
		size--;
	}
	while (nb_rotate-- > 0)
		reverse_rotate_stack(stack, orders);
	return (new_stack);
}

t_list_i	*divide_a(t_list_i **a, t_order order)
{
	int			size;
	int			median;
	t_list_i	*b;

	b = NULL;
	size = ft_lsti_size(*a);
	median = size / 2;
	while (size > 0 && elems_left_to_push(*a, size, median, order))
	{
		if (should_be_pushed((*a)->content, median, order))
			push_b(a, &b);
		else
			rotate_a(a);
		size--;
	}
	return (b);
}
