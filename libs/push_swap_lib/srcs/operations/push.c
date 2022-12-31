/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:51:50 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:00:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
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

void	push_a(t_list_i **a, t_list_i **b)
{
	push_one(a, b);
	ft_putstr("pa\n");
}

void	push_b(t_list_i **a, t_list_i **b)
{
	push_one(b, a);
	ft_putstr("pb\n");
}
