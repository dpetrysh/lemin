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

t_way	*create_way(t_info *inf)
{
	t_way	*new_way;

	new_way = (t_way *)malloc(sizeof(t_way));
	enqueue(inf->end, inf);
	// inf->start->lvl = -1;
	while (inf->rear->room->lvl > 0)
	{
		// printf("BBB%s\n", inf->rear->room->name);
		if (inf->rear->room != inf->end)
		{
			// printf("KKK%s\n", inf->rear->room->name);
			inf->rear->room->lvl = -1;
		}
		enqueue_closest(inf->rear->room, inf);
	}
	// printf("CCC%s\n", inf->rear->room->name);
	// printf("DDD%d\n", inf->rear->room->lvl);
	new_way->front = inf->front;
	new_way->rear = inf->rear;
	inf->front = NULL;
	inf->rear = NULL;
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
		if (tmp->lvl < min && tmp->lvl > -1)
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
			{
				enqueue(tmp, inf);
				return (0);
			}
		}
		mate = mate->next;
	}
	if (suitable)
		enqueue(suitable, inf);
	return (1);
}















