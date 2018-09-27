/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:29:06 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/26 14:29:07 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	push_new_ants(int ways, t_info *inf)
{
	int i;

	i = -1;
	while (++i < ways)
		if (inf->n && !inf->ways[i]->front->room->ant)
			enqueue_cell(NULL, inf->ways[i]->front, inf);
}

void	move_ants_in_graph(t_info *inf)
{
	int i;

	printf("\n");
	i = -1;
	while (++i < inf->in)
	{
		if (inf->ans_front->cell->room == inf->end)
		{
			dequeue_cell(inf);
			inf->in--;
			--i;
		}
		else
		{
			enqueue_cell(inf->ans_front->cell, inf->ans_front->cell->next, inf);
			dequeue_cell(inf);
		}
	}
}

void	give_answer(t_info *inf)
{
	int ways;

	while (inf->in > 0 || inf->n > 0)
	{
		ways = ways_to_use(inf);
		if (inf->n && is_free_ways(ways, inf))
			push_new_ants(ways, inf);
		else
			move_ants_in_graph(inf);
	}
}

int		ways_to_use(t_info *inf)
{
	int		i;
	int		ways;

	i = 0;
	ways = 1;
	while (inf->way_num > 1 && ++i < inf->way_num)
	{
		if (inf->n >= inf->ways[i]->len)
			++ways;
		else
			break;
	}
	return (ways);
}

int		is_free_ways(int ways, t_info *inf)
{
	int	i;

	i = -1;
	while (++i < inf->way_num && i < ways)
		if (!inf->ways[i]->front->room->ant)
		{
			return (1);
		}
	return (0);
}

void	enqueue_cell(t_que *prev, t_que *cell, t_info *inf)
{
	t_ans	*temp;

	if (!(temp = (t_ans *)malloc(sizeof(t_ans))))
		finish(ALLOCATE_MEMORY_PROBLEM);
	temp->cell = cell;
	temp->next = NULL;
	if (!prev)
	{
		temp->cell->room->ant = ++inf->ant;
		inf->n--;
		inf->in++;
	}
	else
		temp->cell->room->ant = prev->room->ant;
	printf("L[%d]-%s ", temp->cell->room->ant, temp->cell->room->name);
	if (!inf->ans_front && !inf->ans_rear)
	{
		inf->ans_front = temp;
		inf->ans_rear = temp;
		return;
	}
	inf->ans_rear->next = temp;
	inf->ans_rear = temp;
}

void	dequeue_cell(t_info *inf)
{
	t_ans *temp;

	temp = inf->ans_front;
	if (!inf->ans_front)
		return;
	if (inf->ans_front == inf->ans_rear)
	{
		inf->ans_front = NULL;
		inf->ans_rear = NULL;
	}
	else
	{
		inf->ans_front->cell->room->ant = 0;
		inf->ans_front = inf->ans_front->next;
	}
	free(temp);
}






