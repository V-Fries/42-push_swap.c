/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sorting_instructions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:05:28 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 01:11:15 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"

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

t_list_i	*optimize_sorting_instructions(t_list_i *instructions)
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
