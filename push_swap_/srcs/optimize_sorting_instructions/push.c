/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:31:15 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 23:35:19 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"

void	handle_push(t_list_i **instructions,
				t_list_i **optimized_instructions)
{
	int	push;

	push = 0;
	while (*instructions != NULL)
	{
		if ((*instructions)->content == PB)
			push++;
		else if ((*instructions)->content == PA)
			push--;
		else
			break ;
		*instructions = ft_lsti_get_next_free_current(*instructions);
	}
	if (push > 0)
		while (push-- > 0)
			add_instruction(optimized_instructions, PB);
	else
		while (push++ < 0)
			add_instruction(optimized_instructions, PA);
}
