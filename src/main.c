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
	int		er;
	char	*line;
	bool	mistake;

	mistake = false;
	inf->rooms = (char *)ft_memalloc(1);
	er = get_next_line(0, &line);
	if (er == 0 || er == -1)
		other_errors(WRONG_FILE);
	if (is_comment(line))
	{
		join_input(line, inf);
		while (get_next_line(0, &line) && is_comment(line))
			join_input(line, inf);
	}
	if (is_digital_str(line))
	{
		if ((inf->n = ft_atoi(line)) < 1)
			mistake = true;
	}
	else
		mistake = true;
	join_input(line, inf);
	return (!mistake);
}

void		join_input(char *line, t_info *inf)
{
	char *tmp;
	tmp = inf->rooms;
	inf->rooms = ft_strjoin(inf->rooms, line);
	inf->rooms = join_slashn(&inf->rooms);
	if (tmp)
		free(tmp);
	free(line);
}

void		read_rooms(char **line, t_info *inf)
{
	int		err;

	while (get_next_line(0, line) && !is_connection(*line) && (err = is_room_name(*line)) == 1)
	{
		if (!is_comment(*line))
			inf->size++;
		join_input(*line, inf);
	}
	if (err != 1 && !is_connection(*line))
		finish(ROOM_NAME_ERROR);
}

int		ft_read(t_info *inf)
{
	char	*line;

	if (!get_ants_number(inf))
		finish(ANT_AMOUNT_ERROR);
	read_rooms(&line, inf);
	make_ht(inf);
	check_start_end_presence(inf);
	read_connect(&line, inf);
	if (!is_connection(line) && !is_comment(line))
	{
		free(line);
		return_errors(IT_IS_NOT_CONNECTION, inf, 0);
	}
	return (0);
}

void	read_connect(char **line, t_info *inf)
{
	char	**connect;
	bool	is_finished;

	is_finished = 1;
	while (is_finished && (is_connection(*line) || is_comment(*line)))
	{
		if (is_connection(*line))
		{
			connect = ft_strsplit(*line, '-');
			if (check_connection(*line, connect, inf))
				add_mate(connect[0], connect[1], inf);
			else
			{
				free(connect);
				free(*line);
				break;
			}
			free(connect);
		}
		free(*line);
		is_finished = get_next_line(0, line);
	}
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

int		main(void)
{
	t_info inf;

	int n;

	make_info(&inf);
	if (!(n = ft_read(&inf)))
	{
		// ft_printf("%s\n", inf.rooms);
		bfs_search(&inf);
		print_ht(inf.ht, &inf);
		print_al(&inf);
		track_ways(&inf);
		print_ways(&inf);
		give_answer(&inf);
		// give warnings
		system("leaks lem-in");
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


