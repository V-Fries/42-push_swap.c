/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:57:47 by vfries            #+#    #+#             */
/*   Updated: 2023/01/07 18:25:26 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_linked_list.h"
#include "ft_string.h"
#include "display_stack.h"
#include "push_swap_lib.h"
#include <stdlib.h>

bool	operate_on_stack(t_list_i **a, t_list_i **b, char *input)
{
	if (ft_strcmp(input, "sa\n") == 0)
		swap_a(a, NULL);
	else if (ft_strcmp(input, "sb\n") == 0)
		swap_b(b, NULL);
	else if (ft_strcmp(input, "ss\n") == 0)
		swap_both(a, b, NULL);
	else if (ft_strcmp(input, "pa\n") == 0)
		push_a(a, b, NULL);
	else if (ft_strcmp(input, "pb\n") == 0)
		push_b(a, b, NULL);
	else if (ft_strcmp(input, "ra\n") == 0)
		rotate_a(a, NULL);
	else if (ft_strcmp(input, "rb\n") == 0)
		rotate_b(b, NULL);
	else if (ft_strcmp(input, "rr\n") == 0)
		rotate_both(a, b, NULL);
	else if (ft_strcmp(input, "rra\n") == 0)
		reverse_rotate_a(a, NULL);
	else if (ft_strcmp(input, "rrb\n") == 0)
		reverse_rotate_b(b, NULL);
	else if (ft_strcmp(input, "rrr\n") == 0)
		reverse_rotate_both(a, b, NULL);
	else
		return (false);
	return (true);
}

bool	handle_input(t_list_i **a, t_list_i **b)
{
	char	*input;

	input = get_next_line(STDIN_FD);
	if (input == NULL)
		return (false);
	if (operate_on_stack(a, b, input) == false)
	{
		free(input);
		ft_lsti_clear(a);
		ft_lsti_clear(b);
		error();
	}
	free(input);
	return (true);
}

bool	sort_stack(t_list_i **a)
{
	t_list_i	*b;
	bool		ret;

	b = NULL;
	while (handle_input(a, &b))
		;
	ret = (is_sorted(*a, ASCENDING) == true && b == NULL);
	ft_lsti_clear(&b);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_list_i	*a;

	if (argc < 2)
		return (0);
	a = parse_arguments(argv + 1, argc - 1);
	if (a == NULL)
		error();
	if (sort_stack(&a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_lsti_clear(&a);
}
