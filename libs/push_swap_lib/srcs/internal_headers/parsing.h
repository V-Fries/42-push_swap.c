/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:19:21 by vfries            #+#    #+#             */
/*   Updated: 2023/01/07 15:30:05 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "ft_linked_list.h"
# include <stdbool.h>

t_list_i	*check_no_doubles(t_list_i *stack);
bool		check_args(char **args, int size);
bool		check_splited(char ***splited);

#endif
