/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:55:47 by vfries            #+#    #+#             */
/*   Updated: 2023/01/05 22:52:01 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "ft_mem.h"
#include "optimize_sorting_instructions.h"

typedef struct s_rotates
{
	int	a;
	int	b;
	int	double_count;
}	t_rotates;

static void	change_rotate(int *rotate, int change, bool *changed_something)
{
	if ((change < 0 && *rotate > 0) || (change > 0 && *rotate < 0))
		*changed_something = true;
	*rotate += change;
}

static bool	is_rotate(int instruction, t_rotates *rotates,
				bool *changed_something)
{
	if (instruction == RA)
		change_rotate(&rotates->a, 1, changed_something);
	else if (instruction == RB)
		change_rotate(&rotates->b, 1, changed_something);
	else if (instruction == RR)
	{
		change_rotate(&rotates->a, 1, changed_something);
		change_rotate(&rotates->b, 1, changed_something);
		rotates->double_count++;
	}
	else if (instruction == RRA)
		change_rotate(&rotates->a, -1, changed_something);
	else if (instruction == RRB)
		change_rotate(&rotates->b, -1, changed_something);
	else if (instruction == RRR)
	{
		change_rotate(&rotates->a, -1, changed_something);
		change_rotate(&rotates->b, -1, changed_something);
		rotates->double_count--;
	}
	else
		return (false);
	return (true);
}

static void	add_double_rotates(t_rotates *rotates,
				t_list_i **optimized_instructions, bool *changed_something)
{
	int	double_count;

	double_count = 0;
	while (rotates->a > 0 && rotates->b > 0)
	{
		add_instruction(optimized_instructions, RR);
		rotates->a--;
		rotates->b--;
		double_count++;
	}
	while (rotates->a < 0 && rotates->b < 0)
	{
		add_instruction(optimized_instructions, RRR);
		rotates->a++;
		rotates->b++;
		double_count--;
	}
	if ((double_count > 0 && double_count > rotates->double_count)
		|| (double_count < 0 && double_count < rotates->double_count))
		*changed_something = true;
}

static void	add_rotates(t_rotates rotates, t_list_i **optimized_instructions,
				bool *changed_something)
{
	add_double_rotates(&rotates, optimized_instructions, changed_something);
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
				t_list_i **optimized_instructions, bool *changed_something)
{
	t_rotates	rotates;

	ft_bzero(&rotates, sizeof(t_rotates));
	while (*instructions != NULL)
	{
		if (is_rotate((*instructions)->content, &rotates, changed_something)
			== false)
			break ;
		*instructions = ft_lsti_get_next_free_current(*instructions);
	}
	add_rotates(rotates, optimized_instructions, changed_something);
}
