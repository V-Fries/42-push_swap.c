/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:13:38 by vfries            #+#    #+#             */
/*   Updated: 2023/01/07 16:00:52 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_char.h"
#include "ft_string.h"
#include <stdbool.h>
#include <stddef.h>

t_list_i	*check_no_doubles(t_list_i *stack)
{
	t_list_i	*cursor;
	t_list_i	*cursor_2;

	cursor = stack;
	while (cursor != NULL)
	{
		cursor_2 = cursor->next;
		while (cursor_2 != NULL)
		{
			if (cursor_2->content == cursor->content)
			{
				ft_lsti_clear(&stack);
				return (NULL);
			}
			cursor_2 = cursor_2->next;
		}
		cursor = cursor->next;
	}
	return (stack);
}

bool	check_args(char **args, int size)
{
	while (size-- > 0)
	{
		if (args[size][0] == '\0')
			return (true);
	}
	return (false);
}

bool	check_splited_failed(char ***splited)
{
	ft_free_split(*splited);
	*splited = NULL;
	return (true);
}

bool	check_splited(char ***splited)
{
	int	i;
	int	k;

	i = -1;
	while ((*splited)[++i] != NULL)
	{
		if (ft_isdigit((*splited)[i][0]) == false
			&& (((*splited)[i][0] != '-' && (*splited)[i][0] != '+')
			|| (*splited)[i][1] == '\0'))
			return (check_splited_failed(splited));
		k = 0;
		while ((*splited)[i][++k] != '\0')
			if (ft_isdigit((*splited)[i][k]) == false)
				return (check_splited_failed(splited));
	}
	return (false);
}
