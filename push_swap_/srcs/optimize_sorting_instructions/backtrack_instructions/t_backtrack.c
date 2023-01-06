/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_backtrack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 06:20:00 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 09:34:24 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "backtrack.h"

void	init_backtrack(t_backtrack *backtrack, t_list_i *instructions,
			t_list_i *a, t_list_i *b)
{
	if (instructions == NULL)
		error();
	backtrack->best = instructions;
	backtrack->best_size = ft_lsti_size(backtrack->best);
	backtrack->current = NULL;
	backtrack->current_size = 0;
	backtrack->a = ft_lsti_cpy(a);
	backtrack->b = ft_lsti_cpy(b);
	backtrack->target_a = ft_lsti_cpy(a);
	backtrack->target_b = ft_lsti_cpy(b);
	if (((backtrack->target_a == NULL || backtrack->a == NULL) && a != NULL )
		|| ((backtrack->target_b == NULL || backtrack->b == NULL) && b != NULL))
		error();
	apply_instructions_on_stacks(&backtrack->target_a, &backtrack->target_b,
		instructions);
}

void	free_backtrack(t_backtrack *backtrack)
{
	ft_lsti_clear(&backtrack->current);
	ft_lsti_clear(&backtrack->a);
	ft_lsti_clear(&backtrack->b);
	ft_lsti_clear(&backtrack->target_a);
	ft_lsti_clear(&backtrack->target_b);
}
