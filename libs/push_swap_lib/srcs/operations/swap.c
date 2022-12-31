/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:48:42 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:29:20 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "ft_string.h"
#include <stddef.h>

void	swap_one(t_list_i **stack)
{
	t_list_i	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	swap_a(t_list_i **a, t_list_i **operations)
{
	t_list_i	*operation;

	swap_one(a);
	if (operations != NULL)
	{
		operation = ft_lsti_new(SA);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}

void	swap_b(t_list_i **b, t_list_i **operations)
{
	t_list_i	*operation;

	swap_one(b);
	if (operations != NULL)
	{
		operation = ft_lsti_new(SB);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}

void	swap_both(t_list_i **a, t_list_i **b, t_list_i **operations)
{
	t_list_i	*operation;

	swap_one(a);
	swap_one(b);
	if (operations != NULL)
	{
		operation = ft_lsti_new(SS);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}
