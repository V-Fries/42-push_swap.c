/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:21:43 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 23:35:05 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"

void	add_instruction(t_list_i **optimized_instructions, int instruction)
{
	t_list_i	*new_node;

	new_node = ft_lsti_new(instruction);
	if (new_node == NULL)
		error();
	ft_lsti_add_front(optimized_instructions, new_node);
}
