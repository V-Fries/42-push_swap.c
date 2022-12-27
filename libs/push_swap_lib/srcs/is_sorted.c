/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:28:00 by vfries            #+#    #+#             */
/*   Updated: 2022/12/27 12:18:39 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <stdbool.h>
#include <stddef.h>

static bool	correct_order(int current, int next, t_order order)
{
	if (order == ASCENDING)
		return (current < next);
	return (current > next);
}

bool	is_sorted(t_list_i *stack, t_order order)
{
	int	tmp;

	if (stack == NULL)
		return (true);
	tmp = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (correct_order(tmp, stack->content, order) == false)
			return (false);
		tmp = stack->content;
		stack = stack->next;
	}
	return (true);
}
