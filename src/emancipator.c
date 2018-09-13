/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emancipator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 22:26:51 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/12 22:26:52 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_room_info(char **rooms)
{
	char **tmp;

	tmp = rooms;
	while (*rooms)
	{
		free(*rooms);
		rooms++;
	}
	free(tmp);
}
