/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:05:40 by vfries            #+#    #+#             */
/*   Updated: 2023/01/02 00:59:15 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_order	reverse_order(t_order order)
{
	if (order == ASCENDING)
		return (DESCENDING);
	return (ASCENDING);
}

t_orders	reverse_orders(t_orders orders)
{
	if (orders.current == ASCENDING)
		orders.current = DESCENDING;
	else
		orders.current = ASCENDING;
	return (orders);
}

t_orders	get_orders(t_order order)
{
	t_orders	orders;

	orders.current = order;
	orders.start = order;
	return (orders);
}
