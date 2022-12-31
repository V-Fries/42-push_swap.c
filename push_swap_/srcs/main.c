/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:27:00 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 16:08:26 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
#include "sort.h"
#include "push_swap_lib.h"
#include <stddef.h>

#define SORT_ORDER ASCENDING

int	main(int argc, char **argv)
{
	t_list_i	*a;

	if (argc == 1)
	{
		ft_putstr("No arguments were given.\n");
		return (0);
	}
	a = parse_arguments(argv + 1, argc - 1);
	if (a == NULL)
		error();
	sort_stack(&a, SORT_ORDER);
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
	ft_lsti_clear(&a);
	return (0);
}
