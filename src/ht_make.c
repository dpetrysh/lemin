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
	int		i;
	t_room	**table;

	if (!(table = (t_room **)malloc(sizeof(t_room *) * inf->size)))
		return (NULL);
	i = -1;
	while (++i < inf->size)
		table[i] = NULL;
	return (table);
}

int			put_in_ht(t_room *new_room, t_info *inf)
{
	int	id;

	if (!new_room)
		return (0);
	id = ft_hashfunc(new_room->name, inf->size);
	check_new_room(new_room, inf);
	if (!inf->ht[id])
	{
		inf->ht[id] = new_room;
		return (0);
	}
	else
	{
		new_room->next = inf->ht[id];
		inf->ht[id] = new_room;
		return (0);
	}
	return (PUTTING_ROOM_PROBLEM);
}

int			put_room_in(char *str_room, t_info *inf, int *qlt)
{
	t_room	*room;

	room = NULL;
	if (!(room = create_room(str_room, inf)) && !is_digital_str(str_room))
		return (ALLOCATE_MEMORY_PROBLEM);
	if (*qlt == 1 && !inf->start_is_present && !is_digital_str(str_room))
	{
		room->lvl = 0;
		inf->start = room;
		*qlt = 0;
		inf->start_is_present = 1;
		return (put_in_ht(room, inf));
	}
	else if (*qlt == 1 && inf->start_is_present && !is_digital_str(str_room))
		return (return_errors(DOUBLE_START, inf, qlt));
	else if (*qlt == 2 && !inf->end_is_present && !is_digital_str(str_room))
	{
		inf->end = room;
		*qlt = 0;
		inf->end_is_present = 1;
		return (put_in_ht(room, inf));
	}
	else if (*qlt == 2 && inf->end_is_present && !is_digital_str(str_room))
		return (return_errors(DOUBLE_END, inf, qlt));
	return (put_in_ht(room, inf));
}

t_room		*create_room(char *str, t_info *inf)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit(str, ' ');
	if (!(room = (t_room *)malloc(sizeof(t_room))))
	{
		free_char_arr(room_info);
		return (NULL);
	}
	room->name = room_info[0];
	room->x = ft_atoi(room_info[1]);
	room->y = ft_atoi(room_info[2]);
	free(room_info[1]);
	free(room_info[2]);
	free(room_info);
	room->lvl = -1;
	room->ant = 0;
	room->next = NULL;
	room->index = ++inf->index;
	return (room);
}

int			make_ht(t_info *inf)
{
	int		res;
	char	**room_inp;
	char	**tmp;

	if (!(inf->ht = create_ht(inf)))
		finish(MEMORY_PROBLEM);
	if (!(inf->al = create_al(inf)))
		finish(MEMORY_PROBLEM);
	room_inp = ft_strsplit(inf->rooms, '\n');
	tmp = room_inp;
	res = 0;
	while (*room_inp)
	{
		check_on_number(*room_inp, inf);
		if (!ft_strcmp(*room_inp, "##start"))
			res = 1;
		else if (!ft_strcmp(*room_inp, "##end"))
			res = 2;
		if (is_room_name(*room_inp) == 1 && !is_comment(*room_inp) && !is_digital_str(*room_inp))
			put_room_in(*room_inp, inf, &res);
		room_inp++;
	}
	free_char_arr(tmp);
	return (0);
}

void	check_on_number(char *str, t_info *inf)
{
	if (is_digital_str(str))
		inf->ants_is_joined++;
	if (inf->ants_is_joined > 1)
		finish(ROOM_NAME_ERROR);
}






