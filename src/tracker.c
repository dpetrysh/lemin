/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:08:25 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/18 15:08:26 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	track_ways(t_info *inf)
{
	int		i;

	i = -1;
	inf->way_num = count_safe_mates(inf->end, inf);
	if (inf->way_num < 1)
		finish(ABSENT_WAYS);
	if (start_end_connected(inf))
	{
		print_start_end_way(inf);
		exit(0);
	}
	inf->ways = (t_way **)malloc(sizeof(t_way *) * inf->way_num);
	while (++i < inf->way_num)
		inf->ways[i] = create_way(inf);
}

t_way	*create_way(t_info *inf)
{
	t_way	*new_way;

	new_way = (t_way *)malloc(sizeof(t_way));
	put_in_stack(inf->end, inf);
	new_way->len = 1;
	while ((inf->front->room->lvl > 1 || inf->front->room == inf->end))
	{
		++new_way->len;
		inf->front->room->lvl = -1;
		enqueue_closest(inf->front->room, inf);
	}
	inf->front->room->lvl = -1;
	new_way->front = inf->front;
	inf->front = NULL;
	return (new_way);
}

int		min_mate_level(t_room *current, t_info *inf)
{
	int		min;
	t_mate	*mate;
	t_room	*tmp;

	min = INT_MAX;
	mate = inf->al[current->index];
	while (mate)
	{
		tmp = get_room(mate->name, inf);
		if (tmp->lvl < min && tmp->lvl > 0)
			min = tmp->lvl;
		mate = mate->next;
	}
	return (min);
}

int		have_another_older(t_room *older, t_room *applicant, t_info *inf)
{
	t_mate	*mate;
	t_room	*tmp;

	mate = inf->al[applicant->index];
	while (mate)
	{
		tmp = get_room(mate->name, inf);
		if (tmp->lvl == (applicant->lvl + 1) && tmp != older)
			return (1);
		mate = mate->next;
	}
	return (0);
}

int		enqueue_closest(t_room *current, t_info *inf)
{
	int		min;
	t_mate	*mate;
	t_room	*tmp;
	t_room	*suitable;

	suitable = NULL;
	min = min_mate_level(current, inf);
	mate = inf->al[current->index];
	while (mate)
	{
		tmp = get_room(mate->name, inf);
		if (tmp->lvl == min)
		{
			suitable = tmp;
			if (!have_another_older(current, tmp, inf))
				return (enqueue_and_return(tmp, inf));
		}
		mate = mate->next;
	}
	if (suitable)
		return (enqueue_and_return(suitable, inf));
	return (0);
}

int		count_safe_mates(t_room *room, t_info *inf)
{
	int		count;
	t_mate	*mate;
	t_room	*tmp;

	count = 0;
	mate = inf->al[room->index];
	while (mate)
	{
		tmp = get_room(mate->name, inf);
		if (tmp->lvl > 0)
			count++;
		mate = mate->next;
	}
	return (count);
}












