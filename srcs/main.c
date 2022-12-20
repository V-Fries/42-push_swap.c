/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:27:00 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 11:16:12 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
#include "sort.h"

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

int	main(void)
{
	t_list_i	*a;

	srand(time(NULL));
	a = generate_random_list();
	if (a == NULL)
		return (ft_putstr("ERROR, malloc failed\n"), 1);
	a = convert_value_to_index(a);
	// Sort_stack
	ft_lsti_clear(&a);
	return (0);
}
