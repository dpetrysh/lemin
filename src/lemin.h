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
	int				lvl;
	int				x;
	int				y;
	char			*name;
	struct	s_room	*next;
}					t_room;

typedef	struct		s_info
{
	int		n;
	int		size;
	char	*rooms;
	t_room	**ht;
	t_room	*start;
	t_room	*end;
}					t_info;

typedef enum
{
	SIMPLE = 0,
	START,
	END
}					qualities;

typedef enum
{
	ANT_AMOUNT_ERROR = 2,
	ROOM_NAME_ERROR,
	COORDINATE_PROBLEM,
	ALLOCATE_MEMORY_PROBLEM,
	HT_MEMORY_PROBLEM,
	PUTTING_ROOM_PROBLEM,
	SOME
}					errors;

/*
main.c
*/
size_t	ft_hashfunc(char *key, size_t size);

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
char	*join_slashn(char **str);

/*
ht_make.c
*/
t_room		**create_ht(t_info *inf);
t_room		*create_room(char *str);
int			put_in_ht(t_room **ht, t_room *new_room, t_info *inf);
int			put_room_in_ht(t_room **ht, char *str_room, t_info *inf, int quality);
int			make_ht(t_info *inf);

/*
emancipator.c
*/
void	free_room_info(char **rooms);


#endif