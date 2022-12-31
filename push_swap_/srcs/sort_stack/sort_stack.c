/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:22:42 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 17:02:03 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "push_swap_lib.h"
#include <stddef.h>

static void	sort_last_elems(t_list_i **stack, t_orders orders, int size,
				t_list_i **sorting_instructions)
{
	if (size < 2)
		return ;
	if ((orders.current == ASCENDING
			&& (*stack)->content > (*stack)->next->content)
		|| (orders.current == DESCENDING
			&& (*stack)->content < (*stack)->next->content))
	{
		if (orders.current == orders.start)
			swap_a(stack, sorting_instructions);
		else
			swap_b(stack, sorting_instructions);
	}
}

static void	push_back_sorted_elems(t_list_i	**stack, t_list_i **new_stack,
				t_orders orders, t_list_i **sorting_instructions)
{
	if (orders.current == orders.start)
		while (*new_stack != NULL)
			push_a(stack, new_stack, sorting_instructions);
	else
		while (*new_stack != NULL)
			push_b(new_stack, stack, sorting_instructions);
}

static void	recursive_sort(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions)
{
	int			size;
	t_list_i	*new_stack;

	size = ft_lsti_size(*stack);
	if (size <= 2)
		return (sort_last_elems(stack, orders, size, sorting_instructions));
	new_stack = divide_stack(stack, orders, sorting_instructions);
	if (is_sorted(*stack, orders.current) == false)
		recursive_sort(stack, orders, sorting_instructions);
	if (is_sorted(new_stack, reverse_order(orders.current)) == false)
		recursive_sort(&new_stack, reverse_orders(orders),
			sorting_instructions);
	push_back_sorted_elems(stack, &new_stack, orders, sorting_instructions);
}

t_list_i	*sort_stack(t_list_i **a, t_order order)
{
	t_list_i	*b;
	t_list_i	*sorting_instructions;
	t_orders	orders;

	*a = convert_value_to_index(*a);
	if (*a == NULL)
		error();
	if (is_sorted(*a, order))
		return (NULL);
	sorting_instructions = NULL;
	b = divide_a(a, order, &sorting_instructions);
	orders.current = order;
	orders.start = order;
	if (is_sorted(*a, order) == false)
		recursive_sort(a, orders, &sorting_instructions);
	if (is_sorted(b, reverse_order(order)) == false)
		recursive_sort(&b, reverse_orders(orders), &sorting_instructions);
	while (b)
		push_a(a, &b, &sorting_instructions);
	ft_lsti_reverse(&sorting_instructions);
	return (sorting_instructions);
}
