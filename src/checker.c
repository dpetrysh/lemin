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
	char	**ingred;

	if (is_comment(str) || is_digital_str(str))
		return (1);
	ingred = ft_strsplit(str, ' ');
	if (!ingred[0] || !ingred[1] || !ingred[2])
		finish(ROOM_NAME_ERROR);
	if (ingred[3])
		finish(ROOM_NAME_ERROR);
	if (!ingred[0][0] || ingred[0][0] == 'L' || ft_strchr(ingred[0], '-'))
		finish(ROOM_NAME_ERROR);
	if (!ft_isdigit(ingred[1][0]) && !(ingred[1][0] == '-' ||
		ingred[1][0] == '+'))
		other_errors(COORDINATE_PROBLEM);
	else if ((ingred[1][0] == '-' || ingred[1][0] == '+') &&
		!is_digital_str(ingred[1] + 1))
		other_errors(COORDINATE_PROBLEM);
	if (!ft_isdigit(ingred[2][0]) && !(ingred[2][0] == '-' ||
		ingred[2][0] == '+'))
		other_errors(COORDINATE_PROBLEM);
	else if ((ingred[2][0] == '-' || ingred[2][0] == '+') &&
		!is_digital_str(ingred[2] + 1))
		other_errors(COORDINATE_PROBLEM);
	free_char_arr(ingred);
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

