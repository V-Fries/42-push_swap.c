/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sorting_instructions.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:25:12 by vfries            #+#    #+#             */
/*   Updated: 2023/01/05 21:58:24 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZE_SORTING_INSTRUCTIONS_H
# define OPTIMIZE_SORTING_INSTRUCTIONS_H

# include "push_swap_lib.h"

// get_better_instructions
typedef struct s_three_for_two
{
	int	target_1;
	int	target_2;
	int	target_3;
	int	new_1;
	int	new_2;
}	t_three_for_two;

// change_three_for_two.c
void		set_three_for_two_targets(t_three_for_two *data, int target_1,
				int target_2, int target_3);
void		set_three_for_two_new(t_three_for_two *data, int new_1, int new_2);
void		change_three_for_two(t_list_i *instructions, t_three_for_two data);
// get_next_target.c
t_list_i	*get_next_target(t_list_i *instructions, int target);

// remove_useless_instructions

// add_instruction.c
void		add_instruction(t_list_i **optimized_instructions, int instruction);
// push.c
void		handle_push(t_list_i **instructions,
				t_list_i **optimized_instructions);
// rotate.c
void		handle_rotate(t_list_i **instructions,
				t_list_i **optimized_instructions);
// swap.c
void		handle_swap(t_list_i **instructions,
				t_list_i **optimized_instructions);


// optimize_sorting_instructions.c
t_list_i	*optimize_sorting_instructions(t_list_i *sorting_instructions);

#endif
