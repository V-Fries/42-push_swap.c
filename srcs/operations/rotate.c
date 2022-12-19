/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:53:22 by vfries            #+#    #+#             */
/*   Updated: 2022/12/19 18:55:46 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
#include <stdbool.h>
#include <stddef.h>

bool	rotate_one(t_list_i **stack)
{
	t_list_i	*tmp;
	t_list_i	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (false);
	tmp = *stack;
	*stack = tmp->next;
	last = ft_lsti_last(*stack);
	last->next = tmp;
	tmp->next = NULL;
	return (true);
}

void	rotate_a(t_list_i **a)
{
	if (rotate_one(a))
		ft_putstr("ra\n");
}

void	rotate_b(t_list_i **b)
{
	if (rotate_one(b))
		ft_putstr("rb\n");
}

void	rotate_both(t_list_i **a, t_list_i **b)
{
	bool	ra;
	bool	rb;

	ra = rotate_one(a);
	rb = rotate_one(b);
	if (ra && rb)
		ft_putstr("rr\n");
	else if (ra)
		ft_putstr("ra\n");
	else if (rb)
		ft_putstr("rb\n");
}
