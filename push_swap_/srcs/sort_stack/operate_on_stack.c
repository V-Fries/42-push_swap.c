/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_on_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:30:18 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:49:50 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "push_swap_lib.h"

void	push_elem(t_list_i **src, t_list_i **dst, t_orders orders,
			t_list_i **sorting_instructions)
{
	if (orders.current == orders.start)
		push_b(src, dst, sorting_instructions);
	else
		push_a(dst, src, sorting_instructions);
}

void	rotate_stack(t_list_i **stack, t_orders orders,
			t_list_i **sorting_instructions)
{
	if (orders.current == orders.start)
		rotate_a(stack, sorting_instructions);
	else
		rotate_b(stack, sorting_instructions);
}

void	reverse_rotate_stack(t_list_i **stack, t_orders orders,
			t_list_i **sorting_instructions)
{
	if (orders.current == orders.start)
		reverse_rotate_a(stack, sorting_instructions);
	else
		reverse_rotate_b(stack, sorting_instructions);
}
