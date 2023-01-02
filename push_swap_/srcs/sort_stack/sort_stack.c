/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:22:42 by vfries            #+#    #+#             */
/*   Updated: 2023/01/02 17:46:11 by vfries           ###   ########lyon.fr   */
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

static void	recursive_sort(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions)
{
	int			size;
	t_list_i	*new_stack;

	size = ft_lsti_size(*stack);
	if (size <= 2)
		return (sort_last_elems(stack, orders, size, sorting_instructions));
	new_stack = divide_stack(stack, orders, sorting_instructions);
	if (orders.current == orders.start)
	{
		if (is_sorted(*stack, orders.current) == false)
			recursive_sort(stack, orders, sorting_instructions);
		if (is_sorted(new_stack, reverse_order(orders.current)) == false)
			recursive_sort(&new_stack, reverse_orders(orders),
				sorting_instructions);
		while (new_stack != NULL)
			push_a(stack, &new_stack, sorting_instructions);
	}
	else
	{
		if (is_sorted(new_stack, reverse_order(orders.current)) == false)
			recursive_sort(&new_stack, reverse_orders(orders),
				sorting_instructions);
		if (is_sorted(*stack, orders.current) == false)
			recursive_sort(stack, orders, sorting_instructions);
	}
}

void	sort_sub_stack(t_list_i **a, t_list_i **sub_stack, t_order order,
			t_list_i **sorting_instructions)
{
	t_orders	orders;

	orders.start = order;
	orders.current = reverse_order(order);
	if (is_sorted(*sub_stack, orders.current) == false)
		recursive_sort(sub_stack, orders, sorting_instructions);
	while (*sub_stack != NULL)
		push_a(a, sub_stack, sorting_instructions);
}

t_list_i	*sort_stack(t_list_i **a, t_order order)
{
	t_list_i	*sorting_instructions;
	t_list_i	*new_stack_1;
	t_list_i	*new_stack_2;

	*a = convert_value_to_index(*a);
	if (*a == NULL)
		error();
	if (is_sorted(*a, order))
		return (NULL);
	sorting_instructions = NULL;
	if (ft_lsti_size(*a) <= 2)
	{
		sort_last_elems(a, get_orders(order), ft_lsti_size(*a),
			&sorting_instructions);
		return (sorting_instructions);
	}
	new_stack_1 = get_semi_sorted_stack(a, &new_stack_2, order,
			&sorting_instructions);
	if (is_sorted(*a, order) == false)
		recursive_sort(a, get_orders(order), &sorting_instructions);
	sort_sub_stack(a, &new_stack_2, order, &sorting_instructions);
	sort_sub_stack(a, &new_stack_1, order, &sorting_instructions);
	ft_lsti_reverse(&sorting_instructions);
	return (sorting_instructions);
}
