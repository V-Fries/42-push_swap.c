/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_be_pushed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:45:42 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 11:50:50 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stddef.h>

bool	should_be_pushed(int value, int median, t_order order)
{
	if (order == ASCENDING)
		return (value <= median);
	return (value > median);
}

bool	elems_left_to_push(t_list_i *stack, int size, int median, t_order order)
{
	while (size-- > 0 && stack != NULL)
	{
		if (should_be_pushed(stack->content, median, order))
			return (true);
		stack = stack->next;
	}
	return (false);
}
