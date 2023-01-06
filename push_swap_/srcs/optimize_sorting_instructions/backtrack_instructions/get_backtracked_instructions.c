/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_backtracked_instructions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:55:53 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 13:44:32 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "backtrack.h"
#include "sort.h"

typedef struct s_two_list
{
	t_list_i	*a;
	t_list_i	*b;
}	t_two_list;

static t_list_i	*get_next_instructions(t_list_i **instructions,
					int nb_to_backtrack)
{
	int			i;
	t_list_i	*next_instructions;
	t_list_i	*current;

	next_instructions = NULL;
	i = -1;
	while (++i < nb_to_backtrack)
	{
		current = *instructions;
		*instructions = (*instructions)->next;
		ft_lsti_add_front(&next_instructions, current);
	}
	return (ft_lsti_reverse(&next_instructions));
}

static t_list_i	*backtrack_instructions(t_two_list stacks, int nb_to_backtrack,
					t_list_i *instructions, bool *changed_something)
{
	t_backtrack	backtrack;
	t_list_i	*starting_instruction;
	t_list_i	*current;

	starting_instruction = get_next_instructions(&instructions,
			nb_to_backtrack);
	init_backtrack(&backtrack, ft_lsti_cpy(starting_instruction), stacks.a,
		stacks.b);
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

static bool	can_call_backtrack_instructions(t_list_i *instructions,
				int nb_to_backtrack)
{
	int	i;

	i = -1;
	while (++i < nb_to_backtrack)
	{
		if (instructions == NULL)
			return (false);
		instructions = instructions->next;
	}
	return (true);
}

void	get_backtracked_instructions(t_list_i *a, t_list_i **instructions,
			bool *changed_something, int nb_to_backtrack)
{
	t_list_i	*cursor;
	t_two_list	stacks;

	stacks.a = ft_lsti_cpy(a);
	if (stacks.a == NULL)
		error();
	stacks.b = NULL;
	if (can_call_backtrack_instructions(*instructions, nb_to_backtrack))
		*instructions = backtrack_instructions(stacks, nb_to_backtrack,
				*instructions, changed_something);
	cursor = *instructions;
	while (cursor != NULL
		&& can_call_backtrack_instructions(cursor->next, nb_to_backtrack))
	{
		apply_instruction(&stacks.a, &stacks.b, cursor->content, NULL);
		cursor->next = backtrack_instructions(stacks, nb_to_backtrack,
				cursor->next, changed_something);
		cursor = cursor->next;
	}
	ft_lsti_clear(&stacks.a);
	ft_lsti_clear(&stacks.b);
}
