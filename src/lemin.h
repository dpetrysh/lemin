/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:44:33 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/07 14:44:34 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

#include <stdio.h>

typedef	struct		s_room
{
	int				ant;
	int				index;
	int				lvl;
	int				x;
	int				y;
	char			*name;
	struct	s_room	*next;
}					t_room;

typedef	struct		s_mate
{
	char			*name;
	struct	s_mate	*next;
}					t_mate;

typedef	struct		s_que
{
	t_room			*room;
	struct	s_que	*next;
}					t_que;

typedef	struct		s_way
{
	int				len;
	struct	s_que	*front;
}					t_way;

typedef	struct		s_ans
{
	t_que			*cell;
	struct	s_ans	*next;
}					t_ans;

typedef	struct		s_info
{
	bool	start_is_present;
	bool	end_is_present;
	int		in;
	int		ant;
	int		n;
	int		index;
	int		size;
	int		way_num;
	char	*rooms;
	t_mate	**al;
	t_room	**ht;
	t_way	**ways;
	t_room	*start;
	t_room	*end;
	t_que	*front;
	t_que	*rear;
	t_ans	*ans_front;
	t_ans	*ans_rear;
}					t_info;

typedef enum		e_qualities
{
	SIMPLE = 0,
	START,
	END
}					qualities;

typedef enum		e_errors
{
	ANT_AMOUNT_ERROR = 2,
	ROOM_NAME_ERROR,
	COORDINATE_PROBLEM,
	ALLOCATE_MEMORY_PROBLEM,
	MEMORY_PROBLEM,
	PUTTING_ROOM_PROBLEM,
	ROOM_NAME_DUPLICATE,
	ROOM_COORD_DUPLICATE,
	CONNECT_IS_ROOM_ISNT,
	IT_IS_NOT_CONNECTION,
	SELF_CONNECTION,
	DOUBLE_CONNECTION,
	DOUBLE_START,
	DOUBLE_END,
	ABSENT_WAYS,
	WRONG_FILE
}					errors;

/*
main.c
*/
size_t		ft_hashfunc(char *key, size_t size);
void		read_rooms(char **line, t_info *inf);

/*
checker.c
*/
int			is_digital_str(char *str);
int			is_room_name(char *str);
int			is_comment(char *str);
int			is_connection(char *str);

/*
utility.c
*/
void		make_info(t_info *inf);
char		*join_slashn(char **str);
int			enqueue_and_return(t_room *room, t_info *inf);
int			start_end_connected(t_info *inf);
t_way		*start_end_way(t_info *inf);

/*
ht_make.c
*/
t_room		**create_ht(t_info *inf);
t_room		*create_room(char *str, t_info *inf);
int			put_in_ht(t_room *new_room, t_info *inf);
int			put_room_in(char *str_room, t_info *inf, int *quality);
int			make_ht(t_info *inf);

/*
emancipator.c
*/
void		free_char_arr(char **rooms);

/*
room_checker.c
*/
void		check_new_room(t_room *new_room, t_info *inf);
int			room_is_present(char *name, t_info *inf);
int			check_connection(char *connect_str, t_info *inf);
int			check_connection_dub(char *room_name, char *mate_name, t_info *inf);

/*
errors.c
*/
void		finish(int er);
void		room_problems(int er);
void		memory_problem(int er);
void		other_errors(int er);

/*
printer.c
*/
void		print_al(t_info *inf);
void		print_ht(t_room **ht, t_info *inf);
void		print_ways(t_info *inf);
void		print_start_end_way(t_info *inf);


/*
adj_list.c
*/
t_mate		**create_al(t_info *inf);
void		add_mate(char *room_name, char *mate_name, t_info *inf);
t_room		*get_room(char *name, t_info *inf);
t_mate		*create_mate(char *name);

/*
bfs.c
*/
void		bfs_search(t_info *inf);
void		enqueue_mates(t_room *room, t_info *inf);
void		enqueue(t_room *room, t_info *inf);
void		put_in_stack(t_room *room, t_info *inf);
void		dequeue(t_info *inf);

/*
tracker.c
*/
t_way		*create_way(t_info *inf);
int			min_mate_level(t_room *current, t_info *inf);
int			have_another_older(t_room *older, t_room *applicant, t_info *inf);
int			enqueue_closest(t_room *current, t_info *inf);
int			count_safe_mates(t_room *room, t_info *inf);
void		track_ways(t_info *inf);

/*
answer.c
*/
void		give_answer(t_info *inf);
int			is_free_ways(int ways, t_info *inf);
void		enqueue_cell(t_que *prev, t_que *cell, t_info *inf);
void		dequeue_cell(t_info *inf);
int			ways_to_use(t_info *inf);
void		move_ants_in_graph(t_info *inf);
void		push_new_ants(int ways, t_info *inf);

#endif








