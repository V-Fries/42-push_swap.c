/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_better_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:11:24 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 01:13:54 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"

static void	get_better_instructions_three_for_two(t_list_i *instructions,
				bool *changed_something)
{
	t_three_for_two		data;

	data = get_three_for_two_targets(RA, PB, RRA);
	set_three_for_two_new(&data, SA, PB);
	change_three_for_two(instructions, data, changed_something);
	data = get_three_for_two_targets(RB, PA, RRB);
	set_three_for_two_new(&data, SB, PA);
	change_three_for_two(instructions, data, changed_something);
	data = get_three_for_two_targets(RB, PB, RRB);
	set_three_for_two_new(&data, PB, SB);
	change_three_for_two(instructions, data, changed_something);
	data = get_three_for_two_targets(RA, PA, RRA);
	set_three_for_two_new(&data, PA, SA);
	change_three_for_two(instructions, data, changed_something);
}

static void	get_better_instructions_three_for_three(t_list_i *instructions,
				bool *changed_something)
{
	t_three_for_three	data;

	data = get_three_for_three_targets(SA, RRB, SB);
	set_three_for_three_new(&data, RRB, SA, SB);
	change_three_for_three(instructions, data, changed_something);
	data = get_three_for_three_targets(SB, RRA, SA);
	set_three_for_three_new(&data, RRA, SB, SA);
	change_three_for_three(instructions, data, changed_something);
}

static void	get_better_instructions_four_for_three(t_list_i *instructions,
				bool *changed_something)
{
	t_four_for_three	data;

	data = get_four_for_three_targets(RB, PA, SA, RRB);
	set_four_for_three_new(&data, SB, PA, SA);
	change_four_for_three(instructions, data, changed_something);
	data = get_four_for_three_targets(RA, PB, SB, RRA);
	set_four_for_three_new(&data, SA, PB, SB);
	change_four_for_three(instructions, data, changed_something);
}

void	get_better_instructions(t_list_i *instructions, bool *changed_something)
{
	get_better_instructions_three_for_two(instructions, changed_something);
	get_better_instructions_three_for_three(instructions, changed_something);
	get_better_instructions_four_for_three(instructions, changed_something);
}
