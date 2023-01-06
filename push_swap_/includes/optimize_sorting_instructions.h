/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sorting_instructions.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:25:12 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 03:59:36 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZE_SORTING_INSTRUCTIONS_H
# define OPTIMIZE_SORTING_INSTRUCTIONS_H

# include "push_swap_lib.h"

// get_better_instructions
typedef struct s_four_for_three
{
	int	target_1;
	int	target_2;
	int	target_3;
	int	target_4;
	int	new_1;
	int	new_2;
	int	new_3;
}	t_four_for_three;

typedef struct s_three_for_three
{
	int	target_1;
	int	target_2;
	int	target_3;
	int	new_1;
	int	new_2;
	int	new_3;
}	t_three_for_three;

typedef struct s_three_for_two
{
	int	target_1;
	int	target_2;
	int	target_3;
	int	new_1;
	int	new_2;
}	t_three_for_two;

// change_four_for_three.c
t_four_for_three	get_four_for_three_targets(int target_1,
						int target_2, int target_3, int target_4);
void				set_four_for_three_new(t_four_for_three *data, int new_1,
						int new_2, int new_3);
void				change_four_for_three(t_list_i *instructions,
						t_four_for_three data, bool *changed_something);
// change_three_for_three.c
t_three_for_three	get_three_for_three_targets(int target_1, int target_2,
						int target_3);
void				set_three_for_three_new(t_three_for_three *data, int new_1,
						int new_2, int new_3);
void				change_three_for_three(t_list_i *instructions,
						t_three_for_three data, bool *changed_something);
// change_three_for_two.c
t_three_for_two		get_three_for_two_targets(int target_1, int target_2,
						int target_3);
void				set_three_for_two_new(t_three_for_two *data, int new_1,
						int new_2);
void				change_three_for_two(t_list_i *instructions,
						t_three_for_two data, bool *changed_something);
// get_better_instructions.c
void				get_better_instructions(t_list_i *instructions,
						bool *changed_something);
// get_next_target.c
t_list_i			*get_next_target(t_list_i *instructions, int target);

// remove_useless_instructions
// push.c
void				handle_push(t_list_i **instructions,
						t_list_i **optimized_instructions,
						bool *changed_something);
// rotate.c
void				handle_rotate(t_list_i **instructions,
						t_list_i **optimized_instructions,
						bool *changed_something);
// swap.c
void				handle_swap(t_list_i **instructions,
						t_list_i **optimized_instructions,
						bool *changed_something);

// optimize_sorting_instructions.c
t_list_i			*optimize_sorting_instructions(t_list_i *a,
						t_list_i *instructions, int stack_size);

#endif
