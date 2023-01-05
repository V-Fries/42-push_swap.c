/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:57:45 by vfries            #+#    #+#             */
/*   Updated: 2023/01/05 21:57:54 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

t_list_i	*get_next_target(t_list_i *instructions, int target)
{
	while (instructions != NULL)
	{
		if (instructions->content == target)
			return (instructions);
		instructions = instructions->next;
	}
	return (NULL);
}
