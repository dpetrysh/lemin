/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:10:11 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/16 10:10:12 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		**create_al(t_info *inf)
{
	int		i;
	t_room	**adj_list;

	if (!(adj_list = (t_room **)malloc(sizeof(t_room *) * inf->size)))
		return (NULL);
	i = -1;
	while (++i < inf->size)
		adj_list[i] = NULL;
	return (adj_list);
}

void	add_mate(char *line, t_info *inf)
{
	char	**connect;
	t_room	*room;
	t_room	*mate;

	connect = ft_strsplit(line, '-');
	room = get_room(connect[0], inf);
	mate = get_room(connect[1], inf);
	if (!room->mate)
	{
		room->mate = mate;
	}
	else
	{
		mate->mate = room->mate;
		room->mate = mate;
	}
}

// void	add_connection(char *line, t_info *inf)
// {
// 	char	**connect;
// 	t_room	*room1;
// 	t_room	*room2;

// 	connect = ft_strsplit(line, '-');
// 	id1 = ft_hashfunc(connect[0]);
// 	id2 = ft_hashfunc(connect[1]);
// }

t_room	*get_room(char *name, t_info *inf)
{
	t_room	*room;
	int id;

	id = ft_hashfunc(name, inf->size);
	room = inf->ht[id];
	while (room)
	{
		if (!ft_strcmp(room->name, name))
			return (room);
		room = room->next;
	}
	return (NULL);
}

