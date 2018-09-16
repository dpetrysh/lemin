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





// void	add_connection(char *line, t_info *inf)
// {
// 	int		id1;
// 	int		id2;
// 	char	**connect;
// 	t_room	*room1;
// 	t_room	*room2;

// 	connect = ft_strsplit(line, '-');
// 	id1 = ft_hashfunc(connect[0]);
// 	id2 = ft_hashfunc(connect[1]);

// }

// t_room	*find_room(char *name, t_info *inf)
// {
// 	t_room	*room;
// 	int fd;

// 	fd = ft_hashfunc(name, inf->size);
// 	room = inf->ht[id];
// 	while (room)
// 	{

// 	}
// }

