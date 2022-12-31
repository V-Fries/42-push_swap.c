/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:56:56 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:29:40 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "ft_string.h"
#include <stddef.h>

void	reverse_rotate_one(t_list_i **stack)
{
	t_list_i	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	reverse_rotate_a(t_list_i **a, t_list_i **operations)
{
	t_list_i	*operation;

	reverse_rotate_one(a);
	if (operations != NULL)
	{
		operation = ft_lsti_new(RRA);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}

void	reverse_rotate_b(t_list_i **b, t_list_i **operations)
{
	t_list_i	*operation;

	reverse_rotate_one(b);
	if (operations != NULL)
	{
		operation = ft_lsti_new(RRB);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}

void	reverse_rotate_both(t_list_i **a, t_list_i **b, t_list_i **operations)
{
	t_list_i	*operation;

	reverse_rotate_one(a);
	reverse_rotate_one(b);
	if (operations != NULL)
	{
		operation = ft_lsti_new(RRR);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}
