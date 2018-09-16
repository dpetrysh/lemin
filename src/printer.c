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
			printf("--->id=%d, %s", i, ht[i]->name);
			tmp = ht[i]->next;
			while (tmp)
			{
				printf("-->%s", tmp->name);
				tmp = tmp->next;
			}
			printf("\n");
		}
	}
}

void		print_al(t_info *inf)
{
	int i;

	i = -1;
	while (++i < inf->size)
	{
		printf("%s\n", (inf->al[i])->name);
	}
}

