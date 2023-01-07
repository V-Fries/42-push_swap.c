/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:57:47 by vfries            #+#    #+#             */
/*   Updated: 2023/01/07 15:25:33 by vfries           ###   ########lyon.fr   */
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

char	*get_input(t_list_i *a, t_list_i *b)
{
	char	*str;

	ft_putchar_fd('\n', STDOUT_FD);
	display_stack(a, "A");
	display_stack(b, "B");
	str = get_next_line(STDIN_FD);
	ft_printf("INPUT == %s\n", str);
	return (str);
}

bool	handle_input(char *input, t_list_i **a, t_list_i **b,
			int *instruction_count)
{
	if (input == NULL)
		return (false);
	if (ft_strcmp(input, "exit\n") == 0)
	{
		free(input);
		ft_lsti_clear(a);
		ft_lsti_clear(b);
		return (true);
	}
	if (operate_on_stack(a, b, input))
		(*instruction_count)++;
	free(input);
	return (false);
}

bool	sort_stack(t_list_i **a, int *instruction_count)
{
	t_list_i	*b;
	char		*input;
	bool		ret;

	b = NULL;
	input = get_input(*a, b);
	if (handle_input(input, a, &b, instruction_count))
		return (false);
	while (input != NULL)
	{
		input = get_input(*a, b);
		if (handle_input(input, a, &b, instruction_count))
			return (false);
	}
	ret = (is_sorted(*a, ASCENDING) == true && b == NULL);
	ft_lsti_clear(a);
	ft_lsti_clear(&b);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_list_i	*a;
	int			instruction_count;

	if (argc < 2)
		return (0);
	a = parse_arguments(argv + 1, argc - 1);
	if (a == NULL)
		error();
	instruction_count = 0;
	if (sort_stack(&a, &instruction_count))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_printf("Number of instruction == %d\n", instruction_count);
}
