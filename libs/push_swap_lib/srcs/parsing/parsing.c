/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:00:33 by vfries            #+#    #+#             */
/*   Updated: 2023/01/07 15:58:53 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "parsing.h"
#include "ft_string.h"
#include "ft_numbers.h"
#include <stdlib.h>
#include <limits.h>

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

static t_list_i	*atoll_all_strings_to_list(char **splited)
{
	t_list_i	*ret;
	t_list_i	*new_node;
	size_t		i;
	long long	tmp;

	ret = NULL;
	i = -1;
	while (splited[++i] != NULL)
	{
		tmp = ft_atoll(splited[i]);
		new_node = ft_lsti_new((int)tmp);
		ft_lsti_add_front(&ret, new_node);
		if (new_node == NULL || tmp > INT_MAX || tmp < INT_MIN)
		{
			ft_lsti_clear(&ret);
			ft_free_split(splited);
			return (NULL);
		}
	}
	ft_free_split(splited);
	ft_lsti_reverse(&ret);
	return (check_no_doubles(ret));
}

t_list_i	*parse_arguments(char **args, int size)
{
	char	*joined_args;
	char	**splited;

	if (check_args(args, size))
		error();
	joined_args = join_all_args(args, size);
	splited = ft_split(joined_args, ' ');
	free(joined_args);
	if (splited == NULL || check_splited(&splited))
		error();
	return (atoll_all_strings_to_list(splited));
}
