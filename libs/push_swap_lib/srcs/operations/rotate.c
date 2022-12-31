/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:53:22 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:29:32 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "ft_string.h"
#include <stddef.h>

void	rotate_one(t_list_i **stack)
{
	t_list_i	*tmp;
	t_list_i	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	last = ft_lsti_last(*stack);
	last->next = tmp;
	tmp->next = NULL;
}

void	rotate_a(t_list_i **a, t_list_i **operations)
{
	t_list_i	*operation;

	rotate_one(a);
	if (operations != NULL)
	{
		operation = ft_lsti_new(RA);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}

void	rotate_b(t_list_i **b, t_list_i **operations)
{
	t_list_i	*operation;

	rotate_one(b);
	if (operations != NULL)
	{
		operation = ft_lsti_new(RB);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}

void	rotate_both(t_list_i **a, t_list_i **b, t_list_i **operations)
{
	t_list_i	*operation;

	rotate_one(a);
	rotate_one(b);
	if (operations != NULL)
	{
		operation = ft_lsti_new(RR);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}
