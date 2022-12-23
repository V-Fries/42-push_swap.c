/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:56:56 by vfries            #+#    #+#             */
/*   Updated: 2022/12/19 18:58:28 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
#include <stdbool.h>
#include <stddef.h>

bool	reverse_rotate_one(t_list_i **stack)
{
	t_list_i	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (false);
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	return (true);
}

void	reverse_rotate_a(t_list_i **a)
{
	if (reverse_rotate_one(a))
		ft_putstr("rra\n");
}

void	reverse_rotate_b(t_list_i **b)
{
	if (reverse_rotate_one(b))
		ft_putstr("rrb\n");
}

void	reverse_rotate_both(t_list_i **a, t_list_i **b)
{
	bool	rra;
	bool	rrb;

	rra = reverse_rotate_one(a);
	rrb = reverse_rotate_one(b);
	if (rra && rrb)
		ft_putstr("rrr\n");
	else if (rra)
		ft_putstr("rra\n");
	else if (rrb)
		ft_putstr("rrb\n");
}
