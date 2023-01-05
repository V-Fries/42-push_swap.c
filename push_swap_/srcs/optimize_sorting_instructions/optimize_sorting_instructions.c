/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sorting_instructions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:05:28 by vfries            #+#    #+#             */
/*   Updated: 2023/01/05 22:02:35 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"

static t_list_i	*remove_useless_instructions(t_list_i *instructions)
{
	t_list_i	*optimized_instructions;

	optimized_instructions = NULL;
	while (instructions != NULL)
	{
		if (instructions->content == PA || instructions->content == PB)
			handle_push(&instructions, &optimized_instructions);
		else if (instructions->content == SA || instructions->content == SB
			|| instructions->content == SS)
			handle_swap(&instructions, &optimized_instructions);
		else
			handle_rotate(&instructions, &optimized_instructions);
	}
	ft_lsti_reverse(&optimized_instructions);
	return (optimized_instructions);
}

void	get_better_instructions(t_list_i *instructions)
{
	t_three_for_two	data;

	set_three_for_two_targets(&data, RA, PB, RRA);
	set_three_for_two_new(&data, SA, PB);
	change_three_for_two(instructions, data);
	set_three_for_two_targets(&data, RB, PA, RRB);
	set_three_for_two_new(&data, SB, PA);
	change_three_for_two(instructions, data);
}

t_list_i	*optimize_sorting_instructions(t_list_i *instructions)
{
	instructions = remove_useless_instructions(instructions);
	get_better_instructions(instructions);
	return (instructions);
}
