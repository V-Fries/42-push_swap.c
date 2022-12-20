/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:27:00 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 16:55:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
#include "sort.h"
#include "parsing.h"
#include "error.h"
#include <stddef.h>

#define SORT_ORDER ASCENDING


// TODO delete_me
	#include <stdlib.h>
	#include <time.h>

	#define LIST_SIZE 100
	#define MAX_VALUE LIST_SIZE

	t_list_i	*get_new_elem(t_list_i *lst)
	{
		int			nb;
		t_list_i	*cursor;

		nb = rand() % MAX_VALUE;
		cursor = lst;
		while (cursor)
		{
			if (cursor->content == nb)
				return (get_new_elem(lst));
			cursor = cursor->next;
		}
		return (ft_lsti_new(nb));
	}

	t_list_i	*generate_random_list(void)
	{
		t_list_i	*new;
		int			i;

		new = NULL;
		i = 0;
		while (i < LIST_SIZE)
		{
			ft_lsti_add_front(&new, get_new_elem(new));
			i++;
		}
		return (new);
	}
//! TODO

int	main(int argc, char **argv)
{
	t_list_i	*a;

	if (argc == 1)
	{
		ft_putstr("No arguments were given\n");
		return (0);
	}
	// TODO Use args when testing is done
	a = parse_arguments(argv + 1, argc - 1);
	//a = generate_random_list();
	// ! TODO
	if (a == NULL)
		error();
	sort_stack(&a, SORT_ORDER);
	// TODO Delete me
		for (t_list_i *cursor = a; cursor != NULL; cursor = cursor->next)
		{
			ft_putnbr_fd(cursor->content, STDOUT_FD);
			ft_putchar_fd('\n', STDOUT_FD);
		}
		(void)argv;
		if (is_sorted(a, SORT_ORDER))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	// ! TODO
	ft_lsti_clear(&a);
	return (0);
}
