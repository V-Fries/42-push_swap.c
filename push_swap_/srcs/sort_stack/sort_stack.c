/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:22:42 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 15:06:16 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"
#include "error.h"
#include <stddef.h>

static void	sort_last_elems(t_list_i **stack, t_orders orders, int size)
{
	bool	swap;

	if (size < 2)
		return ;
	swap = false;
	if (orders.current == ASCENDING
		&& (*stack)->content > (*stack)->next->content)
		swap = true;
	else if (orders.current == DESCENDING
		&& (*stack)->content < (*stack)->next->content)
		swap = true;
	if (swap == true)
	{
		if (orders.current == orders.start)
			swap_a(stack);
		else
			swap_b(stack);
	}
}

static void	push_back_sorted_elems(t_list_i	**stack, t_list_i **new_stack,
				t_orders orders)
{
	if (orders.current == orders.start)
		while (*new_stack != NULL)
			push_a(stack, new_stack);
	else
		while (*new_stack != NULL)
			push_b(new_stack, stack);
}

static void	recursive_sort(t_list_i **stack, t_orders orders)
{
	int			size;
	t_list_i	*new_stack;

	size = ft_lsti_size(*stack);
	if (size <= 2)
		return (sort_last_elems(stack, orders, size));
	new_stack = NULL;
	new_stack = divide_stack(stack, size, orders);
	if (is_sorted(*stack, orders.current) == false)
		recursive_sort(stack, orders);
	if (is_sorted(new_stack, reverse_order(orders.current)) == false)
		recursive_sort(&new_stack, reverse_orders(orders));
	push_back_sorted_elems(stack, &new_stack, orders);
}

// TODO Don't write operations as they are done, put them in a t_list so that
// TODO the push_a and push_b can be parsed and minimized
void	sort_stack(t_list_i **a, t_order order)
{
	t_list_i	*b;
	t_orders	orders;

	*a = convert_value_to_index(*a);
	if (*a == NULL)
		error();
	if (is_sorted(*a, order))
		return ;
	b = divide_a(a, order);
	orders.current = order;
	orders.start = order;
	if (is_sorted(*a, order) == false)
		recursive_sort(a, orders);
	if (is_sorted(b, reverse_order(order)) == false)
		recursive_sort(&b, reverse_orders(orders));
	while (b)
		push_a(a, &b);
}
