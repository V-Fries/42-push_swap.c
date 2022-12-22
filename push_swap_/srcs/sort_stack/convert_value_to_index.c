/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_value_to_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:10:13 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 11:43:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <stddef.h>

static int	get_index(t_list_i *stack, int target)
{
	int		nb_of_smaller_numbers;

	nb_of_smaller_numbers = 0;
	while (stack)
	{
		if (stack->content < target)
			nb_of_smaller_numbers++;
		stack = stack->next;
	}
	return (nb_of_smaller_numbers);
}

t_list_i	*convert_value_to_index(t_list_i *stack)
{
	t_list_i	*cursor;
	t_list_i	*new_list;
	t_list_i	*new_node;

	new_list = NULL;
	cursor = stack;
	while (cursor)
	{
		new_node = ft_lsti_new(get_index(stack, cursor->content));
		if (new_node == NULL)
			return (ft_lsti_clear(&new_list), ft_lsti_clear(&stack), NULL);
		ft_lsti_add_front(&new_list, new_node);
		cursor = cursor->next;
	}
	ft_lsti_clear(&stack);
	ft_lsti_reverse(&new_list);
	return (new_list);
}
