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

int		free_char_arr(char **rooms)
{
	char **tmp;

	tmp = rooms;
	while (*rooms)
	{
		free(*rooms);
		rooms++;
	}
	free(tmp);
	return (0);
}

