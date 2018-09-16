/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:01:24 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/14 12:01:25 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_new_room(t_room *new_room, t_info *inf)
{
	int		i;
	t_room	*tmp;

	i = -1;
	while (++i < inf->size)
	{
		tmp = inf->ht[i];
		while (tmp)
		{
			if (!ft_strcmp(tmp->name, new_room->name))
				finish(ROOM_NAME_DUPLICATE);
			if (tmp->x == new_room->x && tmp->y == new_room->y)
				finish(ROOM_COORD_DUPLICATE);
			tmp = tmp->next;
		}
	}
}

int		room_is_present(char *name, t_info *inf)
{
	int		i;
	int		id;
	t_room	*tmp;

	i = -1;
	id = ft_hashfunc(name, inf->size);
	tmp = inf->ht[id];
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		check_connection(char *connect_str, t_info *inf)
{
	char	**connect;

	if (!is_comment(connect_str))
	{
		connect = ft_strsplit(connect_str, '-');
		if (!room_is_present(connect[0], inf) || !room_is_present(connect[1], inf))
		{
			free_char_arr(connect);
			finish(CONNECT_IS_ROOM_ISNT);
		}
			free_char_arr(connect);
			return (1);
	}
	return (0);
}



