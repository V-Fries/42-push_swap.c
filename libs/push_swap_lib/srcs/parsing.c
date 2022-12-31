/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:00:33 by vfries            #+#    #+#             */
/*   Updated: 2022/12/31 15:14:29 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_char.h"
#include "ft_numbers.h"
#include "ft_string.h"
#include "push_swap_lib.h"
#include <stdlib.h>
#include <stdbool.h>

static char	*join_all_args(char **args, int size)
{
	char	**args_null_terminated;
	char	*ret;

	args_null_terminated = malloc(sizeof(char *) * (size + 1));
	if (args_null_terminated == NULL)
		return (NULL);
	args_null_terminated[size] = NULL;
	while (size-- > 0)
		args_null_terminated[size] = args[size];
	ret = ft_join_strs(args_null_terminated, " ");
	free(args_null_terminated);
	return (ret);
}

static t_list_i	*check_no_doubles(t_list_i *stack)
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

static t_list_i	*atoll_all_strings_to_list(char **splited)
{
	t_list_i	*ret;
	t_list_i	*new_node;
	size_t		i;

	ret = NULL;
	i = -1;
	while (splited[++i] != NULL)
	{
		new_node = ft_lsti_new(ft_atoll(splited[i]));
		if (new_node == NULL)
		{
			ft_lsti_clear(&ret);
			ft_free_split(splited);
			return (NULL);
		}
		ft_lsti_add_front(&ret, new_node);
	}
	ft_free_split(splited);
	ft_lsti_reverse(&ret);
	return (check_no_doubles(ret));
}

t_list_i	*parse_arguments(char **args, int size)
{
	char	*joined_args;
	char	**splited;

	joined_args = join_all_args(args, size);
	splited = ft_split(joined_args, ' ');
	free(joined_args);
	if (splited == NULL)
		error();
	return (atoll_all_strings_to_list(splited));
}
