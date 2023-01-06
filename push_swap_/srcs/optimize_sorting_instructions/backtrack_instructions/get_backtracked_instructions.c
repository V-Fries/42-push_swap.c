/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_backtracked_instructions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:55:53 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 09:55:24 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "backtrack.h"
#include "sort.h"

#define NB_OF_INSTRUCTION_TO_BACKTRACK 4

static t_list_i	*get_next_instructions(t_list_i **instructions)
{
	int			i;
	t_list_i	*next_instructions;
	t_list_i	*current;

	next_instructions = NULL;
	i = -1;
	while (++i < NB_OF_INSTRUCTION_TO_BACKTRACK)
	{
		current = *instructions;
		*instructions = (*instructions)->next;
		ft_lsti_add_front(&next_instructions, current);
	}
	return (ft_lsti_reverse(&next_instructions));
}

static t_list_i	*backtrack_instructions(t_list_i *a, t_list_i *b,
					t_list_i *instructions, bool *changed_something)
{
	t_backtrack	backtrack;
	t_list_i	*starting_instruction;
	t_list_i	*current;

	starting_instruction = get_next_instructions(&instructions);
	init_backtrack(&backtrack, ft_lsti_cpy(starting_instruction), a, b);
	backtracking(&backtrack);
	if (ft_lsti_cmp(backtrack.best, starting_instruction) != 0)
	{
		ft_lsti_reverse(&backtrack.best);
		*changed_something = true;
	}
	ft_lsti_clear(&starting_instruction);
	ft_lsti_reverse(&backtrack.best);
	while (backtrack.best != NULL)
	{
		current = backtrack.best;
		backtrack.best = backtrack.best->next;
		ft_lsti_add_front(&instructions, current);
	}
	free_backtrack(&backtrack);
	return (instructions);
}

static bool	can_call_backtrack_instructions(t_list_i *instructions)
{
	int	i;

	i = -1;
	while (++i < NB_OF_INSTRUCTION_TO_BACKTRACK)
	{
		if (instructions == NULL)
			return (false);
		instructions = instructions->next;
	}
	return (true);
}

void	get_backtracked_instructions(t_list_i *a, t_list_i **instructions,
			bool *changed_something)
{
	t_list_i	*cursor;
	t_list_i	*b;
	t_list_i	*a_copy;

	a_copy = ft_lsti_cpy(a);
	if (a_copy == NULL)
		error();
	b = NULL;
	if (can_call_backtrack_instructions(*instructions))
		*instructions = backtrack_instructions(a_copy, b, *instructions,
				changed_something);
	cursor = *instructions;
	while (cursor != NULL && can_call_backtrack_instructions(cursor->next))
	{
		apply_instruction(&a_copy, &b, cursor->content, NULL);
		cursor->next = backtrack_instructions(a_copy, b, cursor->next,
				changed_something);
		cursor = cursor->next;
	}
	ft_lsti_clear(&a_copy);
	ft_lsti_clear(&b);
}
