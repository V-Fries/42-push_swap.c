/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:31:15 by vfries            #+#    #+#             */
/*   Updated: 2023/01/05 22:12:51 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"

static void	add_pushes(t_list_i **optimized_instructions, int pushes)
{
	if (pushes > 0)
		while (pushes-- > 0)
			add_instruction(optimized_instructions, PB);
	else
		while (pushes++ < 0)
			add_instruction(optimized_instructions, PA);
}

void	handle_push(t_list_i **instructions,
				t_list_i **optimized_instructions, bool *changed_something)
{
	int	pushes;

	pushes = 0;
	while (*instructions != NULL)
	{
		if ((*instructions)->content == PB)
		{
			if (pushes < 0)
				*changed_something = true;
			pushes++;
		}
		else if ((*instructions)->content == PA)
		{
			if (pushes > 0)
				*changed_something = true;
			pushes--;
		}
		else
			break ;
		*instructions = ft_lsti_get_next_free_current(*instructions);
	}
	add_pushes(optimized_instructions, pushes);
}
