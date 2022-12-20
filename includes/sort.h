/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:10:54 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 11:36:39 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "ft_linked_list.h"
# include <stdbool.h>

typedef enum e_order
{
	ASCENDING = 0,
	DESCENDING = 1,
}	t_order;

typedef struct s_orders
{
	t_order	current;
	t_order	start;
}	t_orders;

// convert_value_to_index.c
t_list_i	*convert_value_to_index(t_list_i *stack);

// is_sorted.c
bool		is_sorted(t_list_i *stack, t_order order);

// sort_stack.c
void		sort_stack(t_list_i **a, t_orders order);

#endif
