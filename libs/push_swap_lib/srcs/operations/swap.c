/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:48:42 by vfries            #+#    #+#             */
/*   Updated: 2022/12/19 18:52:15 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
#include <stdbool.h>
#include <stddef.h>

bool	swap_one(t_list_i **stack)
{
	t_list_i	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (false);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	return (true);
}

void	swap_a(t_list_i **a)
{
	if (swap_one(a))
		ft_putstr("sa\n");
}

void	swap_b(t_list_i **b)
{
	if (swap_one(b))
		ft_putstr("sb\n");
}

void	swap_both(t_list_i **a, t_list_i **b)
{
	bool	sa;
	bool	sb;

	sa = swap_one(a);
	sb = swap_one(b);
	if (sa && sb)
		ft_putstr("ss\n");
	else if (sa)
		ft_putstr("sa\n");
	else if (sb)
		ft_putstr("sb\n");
}
