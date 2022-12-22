/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_on_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:30:18 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 12:33:13 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"

void	push_elem(t_list_i **src, t_list_i **dst, t_orders orders)
{
	if (orders.current == orders.start)
		push_b(src, dst);
	else
		push_a(dst, src);
}

void	rotate_stack(t_list_i **stack, t_orders orders)
{
	if (orders.current == orders.start)
		rotate_a(stack);
	else
		rotate_b(stack);
}

void	reverse_rotate_stack(t_list_i **stack, t_orders orders)
{
	if (orders.current == orders.start)
		reverse_rotate_a(stack);
	else
		reverse_rotate_b(stack);
}
