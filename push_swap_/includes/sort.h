/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:10:54 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 00:40:12 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "ft_linked_list.h"
# include "push_swap_lib.h"
# include <stdbool.h>

// add_instruction.c
void		add_instruction(t_list_i **optimized_instructions, int instruction);

// check_sorted.c
bool		check_sorted(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions);

// convert_value_to_index.c
t_list_i	*convert_value_to_index(t_list_i *stack);

// divide_stack.c
t_list_i	*divide_stack(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions);
t_list_i	*divide_stack_a(t_list_i **a, t_orders orders,
				t_list_i **sorting_instructions);
t_list_i	*get_semi_sorted_stack(t_list_i	**a, t_list_i	**new_stack_2,
				t_order order, t_list_i	**sorting_instructions);

// operate_on_stack.c
void		push_elem(t_list_i **src, t_list_i **dst, t_orders orders,
				t_list_i **sorting_instructions);
void		rotate_stack(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions);
void		reverse_rotate_stack(t_list_i **stack, t_orders orders,
				t_list_i **sorting_instructions);
void		push_all_in_a(t_list_i **a, t_list_i *b,
				t_list_i **sorting_instructions);

// orders.c
t_order		reverse_order(t_order order);
t_orders	reverse_orders(t_orders orders);
t_orders	get_orders(t_order order);

// should_be_pushed.c
bool		should_be_pushed(int value, int median, t_order order);
bool		elems_left_to_push(t_list_i *stack, int median, t_order order);

// sort_stack.c
t_list_i	*sort_stack(t_list_i **a, t_order order);

#endif
