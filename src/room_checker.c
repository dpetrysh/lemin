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
		if (!ft_strcmp(connect[0], connect[1]))
		{
			free_char_arr(connect);
			finish(SELF_CONNECTION);
		}
		if (!check_connection_dub(connect[0], connect[1], inf))
		{
			free_char_arr(connect);
			finish(DOUBLE_CONNECTION);
		}
		free_char_arr(connect);
		return (1);
	}
	return (0);
}

int		check_connection_dub(char *room_name, char *mate_name, t_info *inf)
{
	t_room	*room;
	t_mate	*node;

	room = get_room(room_name, inf);
	node = inf->al[room->index];
	while (node)
	{
		if (!ft_strcmp(node->name, mate_name))
			return (0);
		node = node->next;
	}
	return (1);
}

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

void	check_double_start_end(int quality, t_info *inf)
{
	if (quality == 1 && inf->start_is_present)
		finish(DOUBLE_START);
	if (quality == 2 && inf->end_is_present)
		finish(DOUBLE_END);
}







