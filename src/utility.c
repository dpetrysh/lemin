/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:36:18 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/11 14:36:19 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*join_slashn(char **str)
{
	int		i;
	char	*ch;

	i = -1;
	if (*str == NULL)
		return (NULL);
	ch = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 2));
	if (ch != NULL)
	{
		while ((*str)[++i] != '\0')
			ch[i] = (*str)[i];
		ch[i] = '\n';
		ch[++i] = '\0';
		free(*str);
		return (ch);
	}
	return (NULL);
}
