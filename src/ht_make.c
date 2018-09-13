/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_make.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:08:20 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/12 13:08:21 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		**create_ht(t_info *inf)
{
	int i;
	t_room	**table;

	if (!(table = (t_room **)malloc(sizeof(t_room *) * inf->size)))
		return (NULL);
	i = -1;
	while (++i < inf->size)
		table[i] = NULL;
	return (table);
}

int			put_in_ht(t_room **ht, t_room *new_room, t_info *inf)
{
	int fd;

	fd = ft_hashfunc(new_room->name, inf->size);
	if (!ht[fd])
	{
		ht[fd] = new_room;
		return (0);
	}
	else
	{
		new_room->next = ht[fd];
		ht[fd] = new_room;
		return (0);
	}
	return (PUTTING_ROOM_PROBLEM);
}

int			put_room_in_ht(t_room **ht, char *str_room, t_info *inf, int quality)
{
	t_room *room;

	if (!(room = create_room(str_room)))
		return (ALLOCATE_MEMORY_PROBLEM);
	printf("name=%s\n", room->name);
	if (!quality)
		return (put_in_ht(ht, room, inf)); // 0 - everything alright
	if (quality == 1) // start
	{
		inf->start = room;
		return (put_in_ht(ht, room, inf));
	}
	if (quality == 2) // end
	{
		inf->end = room;
		return (put_in_ht(ht, room, inf));
	}
	return (SOME);
}

t_room		*create_room(char *str)
{
	t_room	*room;
	char	**info;

	info = ft_strsplit(str, ' ');
	if (!(room = (t_room *)malloc(sizeof(t_room))))
	{
		free_room_info(info);
		return (NULL);
	}
	room->name = info[0];
	room->x = ft_atoi(info[1]);
	room->y = ft_atoi(info[2]);
	room->next = NULL;

	// free_room_info(info);
	return (room);
}

int			make_ht(t_info *inf)
{
	char	**room_inp;
	int i;

	if (!(inf->ht = create_ht(inf)))
		return (HT_MEMORY_PROBLEM);
	room_inp = ft_strsplit(inf->rooms, '\n');
	i = -1;
	while (++i < inf->size)
	{
		if (is_room_name(room_inp[i]))
			return (put_room_in_ht(inf->ht, room_inp[i], inf, SIMPLE));
		if (ft_strcmp(room_inp[i], "##start"))
			return (put_room_in_ht(inf->ht, room_inp[++i], inf, START));
		if (ft_strcmp(room_inp[i], "##end"))
			return (put_room_in_ht(inf->ht, room_inp[++i], inf, END));
	}
	return (20);
}
