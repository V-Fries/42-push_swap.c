/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:59:06 by vfries            #+#    #+#             */
/*   Updated: 2022/12/19 19:23:41 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "ft_linked_list.h"
# include <stdbool.h>

// Push
bool	push_one(t_list_i **dst, t_list_i **src);
void	push_a(t_list_i **a, t_list_i **b);
void	push_b(t_list_i **a, t_list_i **b);

// Reverse rotate
bool	reverse_rotate_one(t_list_i **stack);
void	reverse_rotate_a(t_list_i **a);
void	reverse_rotate_b(t_list_i **b);
void	reverse_rotate_both(t_list_i **a, t_list_i **b);

// Rotate
bool	rotate_one(t_list_i **stack);
void	rotate_a(t_list_i **a);
void	rotate_b(t_list_i **b);
void	rotate_both(t_list_i **a, t_list_i **b);

// Swap
bool	swap_one(t_list_i **stack);
void	swap_a(t_list_i **a);
void	swap_b(t_list_i **b);
void	swap_both(t_list_i **a, t_list_i **b);

#endif
