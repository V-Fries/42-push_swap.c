/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:27:00 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:59:42 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
#include "sort.h"
#include "push_swap_lib.h"
#include <stddef.h>

#ifndef SORT_ORDER
# define SORT_ORDER ASCENDING
#endif

void	print_instruction(int instruction)
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

void	print_instructions(t_list_i *sorting_instructions)
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
	t_list_i	*sorting_instructions;

	if (argc == 1)
	{
		ft_putstr("No arguments were given.\n");
		return (0);
	}
	a = parse_arguments(argv + 1, argc - 1);
	if (a == NULL)
		error();
	sorting_instructions = sort_stack(&a, SORT_ORDER);
	// TODO Delete me
	// for (t_list_i *cursor = a; cursor != NULL; cursor = cursor->next)
	// {
	// 	ft_putnbr_fd(cursor->content, STDOUT_FD);
	// 	ft_putchar_fd('\n', STDOUT_FD);
	// }
	// (void)argv;
	// if (is_sorted(a, SORT_ORDER))
	// 	ft_putstr("OK\n");
	// else
	// 	ft_putstr("KO\n");
	// ! TODO
	// TODO optimize sorting_instructions
	print_instructions(sorting_instructions);
	ft_lsti_clear(&a);
	ft_lsti_clear(&sorting_instructions);
	return (0);
}
