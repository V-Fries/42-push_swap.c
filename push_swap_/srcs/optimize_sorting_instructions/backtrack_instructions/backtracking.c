/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:29:14 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 09:35:55 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "sort.h"
#include "backtrack.h"
#include "ft_mem.h"

static void	update_best(t_backtrack *backtrack)
{
	ft_lsti_clear(&backtrack->best);
	backtrack->best = ft_lsti_cpy(backtrack->current);
	if (backtrack->best == NULL && backtrack->current != NULL)
		error();
	backtrack->best_size = backtrack->current_size;
}

static bool	is_backtrack_sorted(t_backtrack *backtrack)
{
	return (ft_lsti_cmp(backtrack->a, backtrack->target_a) == 0
		&& ft_lsti_cmp(backtrack->b, backtrack->target_b) == 0);
}

static bool	does_instruction_cancel_previous(t_backtrack *backtrack,
				int instruction)
{
	if (backtrack->current == NULL)
		return (false);
	if (instruction == SA && backtrack->current->content == SA)
		return (true);
	if (instruction == SB && backtrack->current->content == SB)
		return (true);
	if (instruction == SS && backtrack->current->content == SS)
		return (true);
	if (instruction == PA && backtrack->current->content == PB)
		return (true);
	if (instruction == PB && backtrack->current->content == PA)
		return (true);
	if (instruction == RA && backtrack->current->content == RRA)
		return (true);
	if (instruction == RB && backtrack->current->content == RRB)
		return (true);
	if (instruction == RR && backtrack->current->content == RRR)
		return (true);
	if (instruction == RRA && backtrack->current->content == RA)
		return (true);
	if (instruction == RRB && backtrack->current->content == RB)
		return (true);
	if (instruction == RRR && backtrack->current->content == RR)
		return (true);
	return (false);
}

static bool	is_instruction_bad(t_backtrack *backtrack, int instruction)
{
	if (instruction == SA && backtrack->a == NULL)
		return (true);
	if (instruction == SB && backtrack->b == NULL)
		return (true);
	if (instruction == SS && (backtrack->a == NULL || backtrack->b == NULL))
		return (true);
	if (instruction == PA && backtrack->b == NULL)
		return (true);
	if (instruction == PB && backtrack->a == NULL)
		return (true);
	if (instruction == RA && backtrack->a == NULL)
		return (true);
	if (instruction == RB && backtrack->b == NULL)
		return (true);
	if (instruction == RR && (backtrack->a == NULL || backtrack->b == NULL))
		return (true);
	if (instruction == RRA && backtrack->a == NULL)
		return (true);
	if (instruction == RRB && backtrack->b == NULL)
		return (true);
	if (instruction == RRR && (backtrack->a == NULL || backtrack->b == NULL))
		return (true);
	return (does_instruction_cancel_previous(backtrack, instruction));
}

void	backtracking(t_backtrack *backtrack)
{
	int	i;

	if (backtrack->current_size < backtrack->best_size
		&& is_backtrack_sorted(backtrack))
		return (update_best(backtrack));
	if (backtrack->current_size >= backtrack->best_size - 1)
		return ;
	i = -1;
	while (++i < 11)
	{
		if (is_instruction_bad(backtrack, i))
			continue ;
		apply_instruction(&backtrack->a, &backtrack->b, i, &backtrack->current);
		backtrack->current_size++;
		backtracking(backtrack);
		cancel_instruction(&backtrack->a, &backtrack->b, i,
			&backtrack->current);
		backtrack->current_size--;
	}
}
