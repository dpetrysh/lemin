/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:18:40 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/09 20:18:41 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"



int		get_ants_number(t_info *inf)
{
	char *line;

	if (get_next_line(0, &line) && is_digital_str(line))
		inf->n = ft_atoi(line);
	else
	{
		free(line);
		return (0);
	}
	if (inf->n < 1)
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

int		check_rooms(t_info *inf)
{
	char	*line;
	char	*tmp;
	int		err;

	inf->rooms = (char *)ft_memalloc(1);
	while (get_next_line(0, &line) && (err = is_room_name(line)) && err == 1)
	{
		if (!is_comment(line))
			inf->size++;
		tmp = inf->rooms;
		inf->rooms = ft_strjoin(inf->rooms, line);
		inf->rooms = join_slashn(&inf->rooms);
		free(tmp);
		free(line);
	}
	if (err != 1 && !is_connection(line))
	{
		return (err);
	}
	return (0);
}

int		ft_read(t_info *inf)
{
	char	*line;
	int err;

	if (!get_ants_number(inf))
		return (ANT_AMOUNT_ERROR);
	if (!(err = check_rooms(inf)))
		return (err);
	while (get_next_line(0, &line) && is_connection(line)) // read connections
	{
		free(line);
	}
	return (0);
}

size_t	ft_hashfunc(char *key, size_t size)
{
	size_t s1;
	size_t s2;

	s1 = 1;
	s2 = 0;
	while (*key)
	{
		s1 = (s1 + *(key++)) % 2147483647;
		s2 = (s2 + s1) % 2147483647;
	}
	return ((s2 << 16) + s1) % size;
}


void		print_ht(t_room **ht, t_info *inf)
{
	t_room *tmp;
	int i;

	i = -1;
	while (++i < inf->size)
	{
		// printf("i=%d\n", i);
		if (ht[i])
		{
			printf("--->id=%d, name=%s\n", i, ht[i]->name);
			tmp = ht[i]->next;
			while (tmp)
			{
				printf("--->id=%d, name=%s\n", i, tmp->name);
				tmp = tmp->next;
			}
		}
	}
}

int		main(void)
{
	t_info inf;

	int n;

	if (!(n = ft_read(&inf)))
	{
		printf("n=%d\n", inf.n);
		printf("size=%d\n", inf.size);
		// printf("%s\n", inf.rooms);
		printf("make_ht=%d\n", make_ht(&inf));
		print_ht(inf.ht, &inf);
	}
	return (0);
}





























// void	testfunc(char **a, char *line)
// {
// 	int i = 0;
// 	while (a[i])
// 	{
// 		i++;
// 	}
// 	a[i] = line;
// }


	// int i = -1;
	// char **a;
	// char *line;

	// a = (char **)malloc(sizeof(char *) * 3);
	// a[0] = NULL;
	// a[1] = NULL;
	// a[2] = NULL;
	// get_next_line(0, &line);
	// testfunc(a, line);
	// get_next_line(0, &line);
	// testfunc(a, line);
	// get_next_line(0, &line);
	// testfunc(a, line);
	// while (++i < 3)
	// 	printf("%s\n", a[i]);
	// a[0] = "a";
	// a[1] = "a";
	// a[2] = "a";

	// while (1);








