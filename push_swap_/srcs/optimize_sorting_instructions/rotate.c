/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:55:47 by vfries            #+#    #+#             */
/*   Updated: 2023/01/02 19:16:59 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "ft_mem.h"
#include "optimize_sorting_instructions.h"

typedef struct s_rotates
{
	int	a;
	int	b;
}	t_rotates;

static bool	is_rotate(int instruction, t_rotates *rotates)
{
	if (instruction == RA)
		rotates->a++;
	else if (instruction == RB)
		rotates->b++;
	else if (instruction == RR)
	{
		rotates->a++;
		rotates->b++;
	}
	else if (instruction == RRA)
		rotates->a--;
	else if (instruction == RRB)
		rotates->b--;
	else if (instruction == RRR)
	{
		rotates->a--;
		rotates->b--;
	}
	else
		return (false);
	return (true);
}

static void	add_double_rotates(t_rotates *rotates,
				t_list_i **optimized_instructions)
{
	if (rotates->a > 0 && rotates->b > 0)
	{
		while (rotates->a > 0 && rotates->b > 0)
		{
			add_instruction(optimized_instructions, RR);
			rotates->a--;
			rotates->b--;
		}
	}
	else if (rotates->a < 0 && rotates->b < 0)
	{
		while (rotates->a < 0 && rotates->b < 0)
		{
			add_instruction(optimized_instructions, RRR);
			rotates->a++;
			rotates->b++;
		}
	}
}

static void	add_rotates(t_rotates rotates, t_list_i **optimized_instructions)
{
	add_double_rotates(&rotates, optimized_instructions);
	if (rotates.a > 0)
		while (rotates.a-- > 0)
			add_instruction(optimized_instructions, RA);
	else
		while (rotates.a++ < 0)
			add_instruction(optimized_instructions, RRA);
	if (rotates.b > 0)
		while (rotates.b-- > 0)
			add_instruction(optimized_instructions, RB);
	else
		while (rotates.b++ < 0)
			add_instruction(optimized_instructions, RRB);
}

void	handle_rotate(t_list_i **instructions,
				t_list_i **optimized_instructions)
{
	t_rotates	rotates;

	ft_bzero(&rotates, sizeof(t_rotates));
	while (*instructions != NULL)
	{
		if (is_rotate((*instructions)->content, &rotates) == false)
			break ;
		*instructions = ft_lsti_get_next_free_current(*instructions);
	}
	add_rotates(rotates, optimized_instructions);
}
