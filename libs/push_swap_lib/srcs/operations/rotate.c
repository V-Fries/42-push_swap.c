/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:53:22 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:00:38 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
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

void	rotate_a(t_list_i **a)
{
	rotate_one(a);
	ft_putstr("ra\n");
}

void	rotate_b(t_list_i **b)
{
	rotate_one(b);
	ft_putstr("rb\n");
}

void	rotate_both(t_list_i **a, t_list_i **b)
{
	rotate_one(a);
	rotate_one(b);
	ft_putstr("rr\n");
}
