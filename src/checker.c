/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:50:26 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/09 21:50:27 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_comment(char *str)
{
	if (*str == '#')
		return (1);
	return (0);
}

int		is_connection(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '-' || is_comment(str) || ft_strchr(str, ' '))
		return (0);
	if (ft_strchr(str, '-'))
	{
		while (str[i] != '-')
			i++;
		++i;
		while (str[i] && str[i] !='-')
			i++;
		if (str[i] == '-')
			return (0);
		return (1);
	}
	return (0);
}

int		is_room_name(char *str)
{
	int i;

	i = 0;
	if (is_comment(str))
		return (1);
	while (str[i] != ' ' && str[i])
		++i;
	if (!str[i] || str[0] == 'L' || ft_strchr(str, '-'))
		finish(ROOM_NAME_ERROR);
	++i;
	while (ft_isdigit(str[i]))
		i++;
	if (!str[i])
		other_errors(COORDINATE_PROBLEM);
	if ((str[i] && str[i] != ' ') || !ft_isdigit(str[i + 1]))
		other_errors(COORDINATE_PROBLEM);
	++i;
	while (str[i] && ft_isdigit(str[i]))
		++i;
	if (str[i])
		other_errors(COORDINATE_PROBLEM);
	return (1);
}

int		is_digital_str(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

