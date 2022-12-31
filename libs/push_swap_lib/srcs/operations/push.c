/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:51:50 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:29:47 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "ft_string.h"
#include <stddef.h>

void	push_one(t_list_i **dst, t_list_i **src)
{
	t_list_i	*tmp;

	if (dst == NULL || src == NULL || *src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	push_a(t_list_i **a, t_list_i **b, t_list_i **operations)
{
	t_list_i	*operation;

	push_one(a, b);
	if (operations != NULL)
	{
		operation = ft_lsti_new(PA);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}

void	push_b(t_list_i **a, t_list_i **b, t_list_i **operations)
{
	t_list_i	*operation;

	push_one(b, a);
	if (operations != NULL)
	{
		operation = ft_lsti_new(PB);
		if (operation == NULL)
			error();
		ft_lsti_add_front(operations, operation);
	}
}
