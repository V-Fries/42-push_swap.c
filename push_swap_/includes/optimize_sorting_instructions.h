/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sorting_instructions.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:25:12 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 23:34:22 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZE_SORTING_INSTRUCTIONS_H
# define OPTIMIZE_SORTING_INSTRUCTIONS_H

# include "push_swap_lib.h"

// add_instruction.c
void		add_instruction(t_list_i **optimized_instructions, int instruction);

// optimize_sorting_instructions.c
t_list_i	*optimize_sorting_instructions(t_list_i *sorting_instructions);

// push.c
void		handle_push(t_list_i **instructions,
				t_list_i **optimized_instructions);

// rotate.c
void		handle_rotate(t_list_i **instructions,
				t_list_i **optimized_instructions);

// swap.c
void		handle_swap(t_list_i **instructions,
				t_list_i **optimized_instructions);


#endif
