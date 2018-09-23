/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:27:21 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/17 18:27:22 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	bfs_search(t_info *inf)
{
	t_que	*first;

	enqueue_mates(inf->start, inf);
	while (inf->front && inf->rear)
	{
		first = inf->front;
		if (first->room != inf->end)
		{
			enqueue_mates(first->room, inf);
			dequeue(inf);
		}
		else
			dequeue(inf);
	}
}

void	enqueue_mates(t_room *room, t_info *inf)
{
	t_mate	*mate;
	t_room	*tmp;

	mate = inf->al[room->index];
	while (mate)
	{
		tmp = get_room(mate->name, inf);
		if (tmp->lvl == -1)
		{
			enqueue(tmp, inf);
			tmp->lvl = room->lvl + 1;
		}
		mate = mate->next;
	}
}

void	enqueue(t_room *room, t_info *inf)
{
	t_que	*temp;

	temp = (t_que *)malloc(sizeof(t_que));
	temp->room = room;
	temp->next = NULL;
	if (!inf->front && !inf->rear)
	{
		inf->front = temp;
		inf->rear = temp;
		return;
	}
	inf->rear->next = temp;
	inf->rear = temp;
}

void	dequeue(t_info *inf)
{
	t_que *temp;

	temp = inf->front;
	if (!inf->front)
		return;
	if (inf->front == inf->rear)
	{
		inf->front = NULL;
		inf->rear = NULL;
	}
	else
		inf->front = inf->front->next;
	free(temp);
}




