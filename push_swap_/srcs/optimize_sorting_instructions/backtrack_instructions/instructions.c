/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:07:24 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 09:33:53 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	apply_instruction(t_list_i **stack_a, t_list_i **stack_b,
			int instruction, t_list_i **instructions)
{
	if (instruction == SA)
		swap_a(stack_a, instructions);
	else if (instruction == SB)
		swap_b(stack_b, instructions);
	else if (instruction == SS)
		swap_both(stack_a, stack_b, instructions);
	else if (instruction == PA)
		push_a(stack_a, stack_b, instructions);
	else if (instruction == PB)
		push_b(stack_a, stack_b, instructions);
	else if (instruction == RA)
		rotate_a(stack_a, instructions);
	else if (instruction == RB)
		rotate_b(stack_b, instructions);
	else if (instruction == RR)
		rotate_both(stack_a, stack_b, instructions);
	else if (instruction == RRA)
		reverse_rotate_a(stack_a, instructions);
	else if (instruction == RRB)
		reverse_rotate_b(stack_b, instructions);
	else if (instruction == RRR)
		reverse_rotate_both(stack_a, stack_b, instructions);
}

void	cancel_instruction(t_list_i **stack_a, t_list_i **stack_b,
			int instruction, t_list_i **instructions)
{
	if (instruction == SA)
		swap_a(stack_a, NULL);
	else if (instruction == SB)
		swap_b(stack_b, NULL);
	else if (instruction == SS)
		swap_both(stack_a, stack_b, NULL);
	else if (instruction == PA)
		push_b(stack_a, stack_b, NULL);
	else if (instruction == PB)
		push_a(stack_a, stack_b, NULL);
	else if (instruction == RA)
		reverse_rotate_a(stack_a, NULL);
	else if (instruction == RB)
		reverse_rotate_b(stack_b, NULL);
	else if (instruction == RR)
		reverse_rotate_both(stack_a, stack_b, NULL);
	else if (instruction == RRA)
		rotate_a(stack_a, NULL);
	else if (instruction == RRB)
		rotate_b(stack_b, NULL);
	else if (instruction == RRR)
		rotate_both(stack_a, stack_b, NULL);
	if (instructions != NULL)
		*instructions = ft_lsti_get_next_free_current(*instructions);
}

void	apply_instructions_on_stacks(t_list_i **a, t_list_i **b,
			t_list_i *instructions)
{
	while (instructions != NULL)
	{
		apply_instruction(a, b, instructions->content, NULL);
		instructions = instructions->next;
	}
}
