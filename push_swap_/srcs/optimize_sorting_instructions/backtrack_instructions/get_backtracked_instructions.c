/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_backtracked_instructions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:55:53 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 09:10:46 by vfries           ###   ########lyon.fr   */
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

// TODO test with original and best reversed
static bool	backtrack_failed(t_list_i *a, t_list_i *b, t_list_i *original,
				t_list_i *best)
{
	t_list_i	*a_copy_1;
	t_list_i	*b_copy_1;
	t_list_i	*a_copy_2;
	t_list_i	*b_copy_2;
	bool		ret;

	a_copy_1 = ft_lsti_cpy(a);
	b_copy_1 = ft_lsti_cpy(b);
	if ((a_copy_1 == NULL && a != NULL )
		|| (b_copy_1 == NULL && b != NULL))
		error();
	apply_instructions_on_stacks(&a_copy_1, &b_copy_1, original);
	a_copy_2 = ft_lsti_cpy(a);
	b_copy_2 = ft_lsti_cpy(b);
	if ((a_copy_2 == NULL && a != NULL )
		|| (b_copy_2 == NULL && b != NULL))
		error();
	apply_instructions_on_stacks(&a_copy_2, &b_copy_2, best);
	ret = (ft_lsti_cmp(a_copy_1, a_copy_2) != 0
			|| ft_lsti_cmp(b_copy_1, b_copy_2) != 0);
	ft_lsti_clear(&a_copy_1);
	ft_lsti_clear(&a_copy_2);
	ft_lsti_clear(&b_copy_1);
	ft_lsti_clear(&b_copy_2);
	return (ret);
}

static void	fix_backtrack_fail(t_list_i **good, t_list_i **bad)
{
	t_list_i	*tmp;

	tmp = *good;
	*good = *bad;
	*bad = tmp;
}

// TODO Fix backtracking() so that backtrack_failed() never returns true
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
		if (backtrack_failed(a, b, starting_instruction, backtrack.best))
			fix_backtrack_fail(&starting_instruction, &backtrack.best);
		else
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
