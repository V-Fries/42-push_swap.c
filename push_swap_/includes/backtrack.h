/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 04:06:34 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 09:33:59 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACK_H
# define BACKTRACK_H

# include "push_swap_lib.h"

typedef struct s_backtrack
{
	t_list_i	*best;
	int			best_size;
	t_list_i	*current;
	int			current_size;
	t_list_i	*a;
	t_list_i	*b;
	t_list_i	*target_a;
	t_list_i	*target_b;
}	t_backtrack;

// backtracking.c
void		backtracking(t_backtrack *backtrack);

// get_backtracked_instructions.c
void		get_backtracked_instructions(t_list_i *a, t_list_i **instructions,
				bool *changed_something);

// instructions.c
void		apply_instruction(t_list_i **stack_a, t_list_i **stack_b,
				int instruction, t_list_i **instructions);
void		cancel_instruction(t_list_i **stack_a, t_list_i **stack_b,
				int instruction, t_list_i **instructions);
void		apply_instructions_on_stacks(t_list_i **a, t_list_i **b,
				t_list_i *instructions);

// t_backtrack.c
void		init_backtrack(t_backtrack *backtrack, t_list_i *instructions,
				t_list_i *a, t_list_i *b);
void		free_backtrack(t_backtrack *backtrack);

#endif
