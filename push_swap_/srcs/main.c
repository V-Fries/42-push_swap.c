/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:27:00 by vfries            #+#    #+#             */
/*   Updated: 2023/01/07 15:00:05 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "ft_io.h"
#include "sort.h"
#include "optimize_sorting_instructions.h"
#include <stddef.h>

#ifndef SORT_ORDER
# define SORT_ORDER ASCENDING
#endif

static void	print_instruction(int instruction)
{
	if (instruction == SA)
		ft_putstr("sa\n");
	else if (instruction == SB)
		ft_putstr("sb\n");
	else if (instruction == SS)
		ft_putstr("ss\n");
	else if (instruction == PA)
		ft_putstr("pa\n");
	else if (instruction == PB)
		ft_putstr("pb\n");
	else if (instruction == RA)
		ft_putstr("ra\n");
	else if (instruction == RB)
		ft_putstr("rb\n");
	else if (instruction == RR)
		ft_putstr("rr\n");
	else if (instruction == RRA)
		ft_putstr("rra\n");
	else if (instruction == RRB)
		ft_putstr("rrb\n");
	else
		ft_putstr("rrr\n");
}

static void	print_instructions(t_list_i *sorting_instructions)
{
	while (sorting_instructions != NULL)
	{
		print_instruction(sorting_instructions->content);
		sorting_instructions = sorting_instructions->next;
	}
}

int	main(int argc, char **argv)
{
	t_list_i	*a;
	t_list_i	*a_copy;
	t_list_i	*sorting_instructions;

	if (argc == 1)
		return (0);
	a = parse_arguments(argv + 1, argc - 1);
	if (a == NULL)
		error();
	a_copy = ft_lsti_cpy(a);
	if (a_copy == NULL)
		error();
	sorting_instructions = sort_stack(&a, SORT_ORDER);
	sorting_instructions = optimize_sorting_instructions(a_copy,
			sorting_instructions, ft_lsti_size(a_copy));
	print_instructions(sorting_instructions);
	ft_lsti_clear(&a);
	ft_lsti_clear(&a_copy);
	ft_lsti_clear(&sorting_instructions);
	return (0);
}
