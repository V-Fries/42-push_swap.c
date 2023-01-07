/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sorting_instructions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:05:28 by vfries            #+#    #+#             */
/*   Updated: 2023/01/07 20:25:21 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"
#include "backtrack.h"

static t_list_i	*remove_useless_instructions(t_list_i *instructions,
					bool *changed_something)
{
	t_list_i	*optimized_instructions;

	optimized_instructions = NULL;
	while (instructions != NULL)
	{
		if (instructions->content == PA || instructions->content == PB)
			handle_push(&instructions, &optimized_instructions,
				changed_something);
		else if (instructions->content == SA || instructions->content == SB
			|| instructions->content == SS)
			handle_swap(&instructions, &optimized_instructions,
				changed_something);
		else
			handle_rotate(&instructions, &optimized_instructions,
				changed_something);
	}
	ft_lsti_reverse(&optimized_instructions);
	return (optimized_instructions);
}

static t_list_i	*initial_instructions_optimization(t_list_i *instructions)
{
	bool	changed_something;

	changed_something = true;
	while (changed_something)
	{
		while (changed_something)
		{
			changed_something = false;
			get_better_instructions(instructions, &changed_something);
		}
		instructions = remove_useless_instructions(instructions,
				&changed_something);
	}
	return (instructions);
}

static bool	init_optimize_sorting_loop_condition(int stack_size,
				t_list_i *instructions, int *nb_to_backtrack,
				bool *changed_something)
{
	static int	nb_to_backtrack_original;
	int			instructions_size;

	if (nb_to_backtrack_original == 0)
		nb_to_backtrack_original = *nb_to_backtrack;
	instructions_size = ft_lsti_size(instructions);
	if (*changed_something == false)
			(*nb_to_backtrack)++;
	if (*nb_to_backtrack > instructions_size)
	{
		nb_to_backtrack_original -= *nb_to_backtrack - instructions_size;
		*nb_to_backtrack = instructions_size;
	}
	if (nb_to_backtrack_original == *nb_to_backtrack + 3)
		return (false);
	if (stack_size <= 3)
		return (instructions_size > 2);
	if (stack_size <= 4)
		return (instructions_size > 5);
	if (stack_size <= 5)
		return (instructions_size > 8);
	if (stack_size <= 100)
		return (instructions_size > 699);
	return (false);
}

static t_list_i	*optimize_sorting_instructions_loop(t_list_i *a,
				t_list_i *instructions, int stack_size, int nb_to_backtrack)
{
	bool	changed_something;

	changed_something = true;
	while (init_optimize_sorting_loop_condition(stack_size, instructions,
			&nb_to_backtrack, &changed_something))
	{
		while (changed_something)
		{
			changed_something = false;
			get_better_instructions(instructions, &changed_something);
		}
		get_backtracked_instructions(a, &instructions, &changed_something,
			nb_to_backtrack);
		instructions = remove_useless_instructions(instructions,
				&changed_something);
	}
	return (instructions);
}

t_list_i	*optimize_sorting_instructions(t_list_i *a, t_list_i *instructions,
				int stack_size)
{
	int		nb_to_backtrack;

	instructions = initial_instructions_optimization(instructions);
	nb_to_backtrack = 3;
	if (stack_size <= 10)
		nb_to_backtrack = 5;
	if (stack_size <= 5)
		nb_to_backtrack = 8;
	return (optimize_sorting_instructions_loop(a, instructions, stack_size,
			nb_to_backtrack));
}
