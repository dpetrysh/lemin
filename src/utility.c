/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:36:18 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/11 14:36:19 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	make_info(t_info *inf)
{
	inf->start_is_present = 0;
	inf->end_is_present = 0;
	inf->n = 0;
	inf->index = -1;
	inf->size = 0;
	inf->way_num = 0;
	inf->end = NULL;
	inf->start = NULL;
	inf->front = NULL;
	inf->rear = NULL;
}

char	*join_slashn(char **str)
{
	int		i;
	char	*ch;

	i = -1;
	if (*str == NULL)
		return (NULL);
	ch = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 2));
	if (ch != NULL)
	{
		while ((*str)[++i] != '\0')
			ch[i] = (*str)[i];
		ch[i] = '\n';
		ch[++i] = '\0';
		free(*str);
		return (ch);
	}
	return (NULL);
}

int		enqueue_and_finish(t_room *room, t_info *inf)
{
	enqueue(room, inf);
	return (0);
}

int		start_end_connected(t_info *inf)
{
	t_mate	*mate;

	mate = inf->al[inf->start->index];
	while (mate)
	{
		if (!ft_strcmp(inf->end->name, mate->name))
			return (1);
		mate = mate->next;
	}
	return (0);
}

t_way	*start_end_way(t_info *inf)
{
	t_way	*new_way;
	t_mate	*mate;

	mate = inf->al[inf->start->index];
	new_way = NULL;
	while (mate)
	{
		if (!ft_strcmp(inf->end->name, mate->name))
		{
			new_way = (t_way *)malloc(sizeof(t_way));
			enqueue(inf->end, inf);
			new_way->front = inf->front;
			new_way->rear = inf->rear;
			inf->front = NULL;
			inf->rear = NULL;
			return (new_way);
		}
		mate = mate->next;
	}
	return (new_way);
}

