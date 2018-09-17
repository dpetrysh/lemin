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
	enqueue_mates(inf->start);
	while (!inf->start && !inf->start)
	{
		
	}
}

void	enqueue_mates(t_room *room, t_info *inf)
{
	t_mate	*mate;

	mate = inf->al[room->index];
	while (mate)
	{
		enqueue(mate->room, inf);
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
		front = temp;
		rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
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