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
			ft_printf("--->id=%d, %s(%d)", i, ht[i]->name, ht[i]->index);
			tmp = ht[i]->next;
			while (tmp)
			{
				ft_printf("-->%s(%d)", tmp->name, tmp->index);
				tmp = tmp->next;
			}
			ft_printf("\n");
		}
	}
}

t_room		*get_room_with_id(int id, char *mate_name, t_info *inf)
{
	t_mate 	*tmp;
	t_room	*mate_room;


	mate_room = get_room(mate_name, inf);
	tmp = inf->al[mate_room->index];

	while (tmp)
	{
		mate_room = get_room(tmp->name, inf);
		if (id == mate_room->index)
			return (mate_room);
		tmp = tmp->next;
	}
	return (NULL);
}

void		print_al(t_info *inf)
{
	t_room	*room;
	t_mate	*tmp;
	int i;

	i = -1;
	while (++i < inf->size)
	{
		if (inf->al[i])
		{
			room = get_room_with_id(i, inf->al[i]->name, inf);
			ft_printf("%s", room->name);
			ft_printf(":->%s", inf->al[i]->name);
			tmp = inf->al[i]->next;
			while (tmp)
			{
				ft_printf("-->%s", tmp->name);
				tmp = tmp->next;
			}
			ft_printf("\n");
		}
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
		ft_printf("Way:");
		while (tmp)
		{
			ft_printf("%s-->", tmp->room->name);
			tmp = tmp->next;
		}
		ft_printf("|length|=%d\n", inf->ways[i]->len);
	}
}

void	print_start_end_way(t_info *inf)
{
	int	i;

	i = 0;
	while (++i <= inf->n)
		ft_printf("L%d-%s ", i, inf->end->name);
	ft_printf("\n");
}





