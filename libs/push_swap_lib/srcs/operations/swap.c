/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:48:42 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:08:44 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
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

void	swap_a(t_list_i **a)
{
	swap_one(a);
	ft_putstr("sa\n");
}

void	swap_b(t_list_i **b)
{
	swap_one(b);
	ft_putstr("sb\n");
}

void	swap_both(t_list_i **a, t_list_i **b)
{
	swap_one(a);
	swap_one(b);
	ft_putstr("ss\n");
}
