/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:22:42 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 00:37:09 by vfries           ###   ########lyon.fr   */
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
	if (check_sorted(stack, orders, sorting_instructions))
		return ;
	if (size <= 2)
		return (sort_last_elems(stack, orders, size, sorting_instructions));
	new_stack = divide_stack(stack, orders, sorting_instructions);
	if (orders.current == orders.start)
	{
		recursive_sort(stack, orders, sorting_instructions);
		recursive_sort(&new_stack, reverse_orders(orders),
			sorting_instructions);
		push_all_in_a(stack, new_stack, sorting_instructions);
	}
	else
	{
		recursive_sort(&new_stack, reverse_orders(orders),
			sorting_instructions);
		recursive_sort(stack, orders, sorting_instructions);
		ft_lsti_clear(&new_stack);
	}
}

static void	recursive_sort_a(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions)
{
	int			size;
	t_list_i	*new_stack;

	if (check_sorted(stack, orders, sorting_instructions))
		return ;
	size = ft_lsti_size(*stack);
	if (size <= 2)
		return (sort_last_elems(stack, orders, size, sorting_instructions));
	new_stack = divide_stack_a(stack, orders, sorting_instructions);
	recursive_sort_a(stack, orders, sorting_instructions);
	recursive_sort(&new_stack, reverse_orders(orders),
		sorting_instructions);
	push_all_in_a(stack, new_stack, sorting_instructions);
}

static void	sort_sub_stack(t_list_i **a, t_list_i **sub_stack, t_order order,
			t_list_i **sorting_instructions)
{
	t_orders	orders;

	orders.start = order;
	orders.current = reverse_order(order);
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
	sorting_instructions = NULL;
	if (check_sorted(a, get_orders(order), &sorting_instructions))
		return (sorting_instructions);
	if (ft_lsti_size(*a) <= 2)
	{
		sort_last_elems(a, get_orders(order), ft_lsti_size(*a),
			&sorting_instructions);
		return (sorting_instructions);
	}
	new_stack_1 = get_semi_sorted_stack(a, &new_stack_2, order,
			&sorting_instructions);
	recursive_sort_a(a, get_orders(order), &sorting_instructions);
	sort_sub_stack(a, &new_stack_2, order, &sorting_instructions);
	sort_sub_stack(a, &new_stack_1, order, &sorting_instructions);
	ft_lsti_reverse(&sorting_instructions);
	return (sorting_instructions);
}
