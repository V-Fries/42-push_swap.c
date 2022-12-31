/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:59:06 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:01:52 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

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

// Operatations
// Push
void		push_one(t_list_i **dst, t_list_i **src);
void		push_a(t_list_i **a, t_list_i **b);
void		push_b(t_list_i **a, t_list_i **b);
// Reverse rotate
void		reverse_rotate_one(t_list_i **stack);
void		reverse_rotate_a(t_list_i **a);
void		reverse_rotate_b(t_list_i **b);
void		reverse_rotate_both(t_list_i **a, t_list_i **b);
// Rotate
void		rotate_one(t_list_i **stack);
void		rotate_a(t_list_i **a);
void		rotate_b(t_list_i **b);
void		rotate_both(t_list_i **a, t_list_i **b);
// Swap
void		swap_one(t_list_i **stack);
void		swap_a(t_list_i **a);
void		swap_b(t_list_i **b);
void		swap_both(t_list_i **a, t_list_i **b);

// error.c
void		error(void);

// is_sorted.c
bool		is_sorted(t_list_i *stack, t_order order);

// parsing.c
t_list_i	*parse_arguments(char **args, int size);

#endif
