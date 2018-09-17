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

t_mate		**create_al(t_info *inf)
{
	int		i;
	t_mate	**adj_list;

	if (!(adj_list = (t_mate **)malloc(sizeof(t_room *) * inf->size)))
		return (NULL);
	i = -1;
	while (++i < inf->size)
		adj_list[i] = NULL;
	return (adj_list);
}

void	add_mate(char *room_name, char *mate_name, t_info *inf)
{
	t_room	*room;
	t_mate	*mate;

	room = get_room(room_name, inf);
	mate = create_mate(mate_name);
	mate->next = inf->al[room->index];
	inf->al[room->index] = mate;

	room = get_room(mate_name, inf);
	mate = create_mate(room_name);
	mate->next = inf->al[room->index];
	inf->al[room->index] = mate;
}

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

t_mate	*create_mate(char *name)
{
	t_mate *mate;
	mate = (t_mate *)malloc(sizeof(t_mate));
	mate->name = name;
	mate->next = NULL;
	return (mate);
}
