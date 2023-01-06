/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:48:18 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 00:41:01 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "sort.h"
#include "optimize_sorting_instructions.h"

static void	add_swaps(int swap_a, int swap_b, t_list_i **optimized_instructions,
				bool *changed_something)
{
	if (swap_a != swap_a % 2 || swap_b != swap_b % 2)
		*changed_something = true;
	swap_a %= 2;
	swap_b %= 2;
	if (swap_a > 0 && swap_b > 0)
		add_instruction(optimized_instructions, SS);
	else if (swap_a > 0)
		add_instruction(optimized_instructions, SA);
	else if (swap_b > 0)
		add_instruction(optimized_instructions, SB);
}

void	handle_swap(t_list_i **instructions,
				t_list_i **optimized_instructions, bool *changed_something)
{
	int	swap_a;
	int	swap_b;

	swap_a = 0;
	swap_b = 0;
	while (*instructions != NULL)
	{
		if ((*instructions)->content == SA)
			swap_a++;
		else if ((*instructions)->content == SB)
			swap_b++;
		else if ((*instructions)->content == SS)
		{
			swap_a++;
			swap_b++;
		}
		else
			break ;
		*instructions = ft_lsti_get_next_free_current(*instructions);
	}
	add_swaps(swap_a, swap_b, optimized_instructions, changed_something);
}
