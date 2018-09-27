/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:36:43 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/15 20:36:44 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_ht(t_room **ht, t_info *inf)
{
	t_room *tmp;
	int i;

	i = -1;
	while (++i < inf->size)
	{
		if (ht[i])
		{
			printf("--->id=%d, %s(%d)", i, ht[i]->name, ht[i]->lvl);
			tmp = ht[i]->next;
			while (tmp)
			{
				printf("-->%s(%d)", tmp->name, tmp->index);
				tmp = tmp->next;
			}
			printf("\n");
		}
	}
}

void		print_al(t_info *inf)
{
	t_mate *tmp;
	int i;

	i = -1;
	while (++i < inf->size)
	{
		printf("%s", inf->al[i]->name);
		tmp = inf->al[i]->next;
		while (tmp)
		{
			printf("-->%s", tmp->name);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

void		print_ways(t_info *inf)
{
	int i;
	t_que	*tmp;

	i = -1;
	while (++i < inf->way_num)
	{
		tmp = inf->ways[i]->front;
		printf("Way:");
		while (tmp)
		{
			printf("%s-->", tmp->room->name);
			tmp = tmp->next;
		}
		printf("    len=%d\n", inf->ways[i]->len);
	}
}

void	print_start_end_way(t_info *inf)
{
	int	i;

	i = 0;
	while (++i <= inf->n)
		printf("L[%d]-%s ", i, inf->end->name);
	printf("\n");
}





