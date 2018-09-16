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
# include "libft.h"

#include <stdio.h>

typedef	struct		s_room
{
	int				index;
	int				lvl;
	int				x;
	int				y;
	char			*name;
	struct	s_room	*next;
}					t_room;

// typedef	struct		s_alel
// {
// 	struct	s_room	*room;
// 	struct	s_room	*next;
// }					t_alel;

typedef	struct		s_info
{
	int		n;
	int		index;
	int		size;
	char	*rooms;
	t_room	**ht;
	t_room	**al;
	t_room	*start;
	t_room	*end;
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
	SOME,
	ROOM_NAME_DUPLICATE,
	ROOM_COORD_DUPLICATE,
	CONNECT_IS_ROOM_ISNT
}					errors;

/*
main.c
*/
size_t		ft_hashfunc(char *key, size_t size);
void		read_rooms(char **line, t_info *inf);

/*
checker.c
*/
int		is_digital_str(char *str);
int		is_room_name(char *str);
int		is_comment(char *str);
int		is_connection(char *str);

/*
utility.c
*/
void	make_info(t_info *inf);
char	*join_slashn(char **str);

/*
ht_make.c
*/
t_room		**create_ht(t_info *inf);
t_room		*create_room(char *str, t_info *inf);
int			put_in_ht(t_room *new_room, t_info *inf);
int			put_room_in(char *str_room, t_info *inf, int quality);
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


/*
neighbours.c
*/
t_room		**create_al(t_info *inf);

#endif



