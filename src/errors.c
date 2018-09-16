/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:58:19 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/09/14 11:58:20 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	finish(int er)
{
	if (er == ROOM_NAME_DUPLICATE)
		room_problems(er);
	if (er == ROOM_COORD_DUPLICATE)
		room_problems(er);
	if (er == ROOM_NAME_ERROR)
		room_problems(er);
	if (er == MEMORY_PROBLEM)
		memory_problem(er);
	if (er == ANT_AMOUNT_ERROR)
		other_errors(er);
	if (er == CONNECT_IS_ROOM_ISNT)
		other_errors(er);
}

void	room_problems(int er)
{
	if (er == ROOM_NAME_DUPLICATE)
	{
		printf("There is two rooms in your file with the same name\n");
		exit(EXIT_FAILURE);
	}
	if (er == ROOM_COORD_DUPLICATE)
	{
		printf("There is two rooms with the same coordinates in your file\n");
		exit(EXIT_FAILURE);
	}
	if (er == ROOM_NAME_ERROR)
	{
		printf("There are some problems with room's name (check if it don't start with 'L')");
		exit(EXIT_FAILURE);
	}
}

void	memory_problem(int er)
{
	if (er == MEMORY_PROBLEM)
	{
		printf("There are some problems with memory allocation");
		exit(EXIT_FAILURE);
	}
}

void	other_errors(int er)
{
	if (er == ANT_AMOUNT_ERROR)
	{
		printf("There is bad number of ants. Look closely to it. It should consist only by digits");
		exit(EXIT_FAILURE);
	}
	if (er == CONNECT_IS_ROOM_ISNT)
	{
		printf("There is a false connection\nThat does a room consists\nDevoided by perfection\nBecause the room is missed");
		exit(EXIT_FAILURE);
	}
}

