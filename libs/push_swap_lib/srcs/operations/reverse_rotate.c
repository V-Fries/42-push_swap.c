/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:56:56 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:00:02 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
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

void	reverse_rotate_a(t_list_i **a)
{
	reverse_rotate_one(a);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_list_i **b)
{
	reverse_rotate_one(b);
	ft_putstr("rrb\n");
}

void	reverse_rotate_both(t_list_i **a, t_list_i **b)
{
	reverse_rotate_one(a);
	reverse_rotate_one(b);
	ft_putstr("rrr\n");
}
