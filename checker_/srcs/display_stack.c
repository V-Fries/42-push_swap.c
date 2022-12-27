/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:11:14 by vfries            #+#    #+#             */
/*   Updated: 2022/12/27 14:11:56 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"

void	display_stack(t_list_i *stack, const char *stack_name)
{
	ft_printf("%s: ", stack_name);
	if (stack == NULL)
		ft_putstr("(null)");
	while (stack != NULL)
	{
		ft_printf("%d ", stack->content);
		stack = stack->next;
	}
	ft_putchar_fd('\n', STDOUT_FD);
}
