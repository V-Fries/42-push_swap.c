/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:54:34 by vfries            #+#    #+#             */
/*   Updated: 2023/01/08 12:08:25 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "sort.h"

static bool	swap_to_order(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions)
{
	swap_a(stack, NULL);
	if (is_sorted(*stack, orders.current))
	{
		if (orders.current == orders.start)
			add_instruction(sorting_instructions, SA);
		else
			add_instruction(sorting_instructions, SB);
		return (true);
	}
	swap_a(stack, NULL);
	return (false);
}

bool	check_sorted(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions)
{
	if (is_sorted(*stack, orders.current))
		return (true);
	return (swap_to_order(stack, orders, sorting_instructions));
}
