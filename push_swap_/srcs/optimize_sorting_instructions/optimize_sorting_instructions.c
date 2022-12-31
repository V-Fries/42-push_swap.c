/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sorting_instructions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:05:28 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 23:34:38 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"

t_list_i	*optimize_sorting_instructions(t_list_i *sorting_instructions)
{
	t_list_i	*optimized_instructions;
	t_list_i	*cursor;

	optimized_instructions = NULL;
	cursor = sorting_instructions;
	while (cursor != NULL)
	{
		if (cursor->content == PA || cursor->content == PB)
			handle_push(&cursor, &optimized_instructions);
		else if (cursor->content == SA || cursor->content == SB
			|| cursor->content == SS)
			handle_swap(&cursor, &optimized_instructions);
		else
			handle_rotate(&cursor, &optimized_instructions);
	}
	ft_lsti_reverse(&optimized_instructions);
	return (optimized_instructions);
}
