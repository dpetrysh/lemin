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
	if (er == IT_IS_NOT_CONNECTION)
		other_errors(er);
	if (er == SELF_CONNECTION)
		room_problems(er);
	if (er == DOUBLE_CONNECTION)
		other_errors(er);
	if (er == DOUBLE_START)
		other_errors(DOUBLE_START);
	if (er == DOUBLE_END)
		other_errors(DOUBLE_END);
	if (er == ABSENT_WAYS)
		room_problems(ABSENT_WAYS);
}

void	room_problems(int er)
{
	if (er == ROOM_NAME_DUPLICATE)
		printf("There is two rooms in your file with the same name\n");
	else if (er == ROOM_COORD_DUPLICATE)
		printf("There is two rooms with the same coordinates in your file\n");
	else if (er == ROOM_NAME_ERROR)
		printf("There are some problems with room's name (check if it don't start with 'L')");
	else if (er == SELF_CONNECTION)
		printf("We know that you can connect to your inner self i.e. to yourself! But rooms can't do that!");
	else if (er == ABSENT_WAYS)
		printf("The is no ways from start to end!!!\n");
	exit(EXIT_FAILURE);
}

void	memory_problem(int er)
{
	if (er == MEMORY_PROBLEM)
		printf("There are some problems with memory allocation");
	exit(EXIT_FAILURE);
}

void	other_errors(int er)
{
	if (er == ANT_AMOUNT_ERROR)
		printf("I am the Number of the ants\nAnd you know that I do like\nTo wear my pants of digits\nInstead of symbols dyke!\n I say: fix it!");
	else if (er == CONNECT_IS_ROOM_ISNT)
		printf("There is a false connection\nThat does a room consists\nDevoided by perfection\nBecause the room is missed");
	else if (er == IT_IS_NOT_CONNECTION)
		printf("There ought to be connection\nBut look! there is instead\nDemanding on defection\nSome string! Are you just mad?");
	else if (er == DOUBLE_CONNECTION)
		printf("Please give me satisfaction -\nGet rid of double connection");
	else if (er == DOUBLE_START)
		printf("There is doubling ##START\n");
	else if (er == DOUBLE_END)
		printf("There is doubling ##END\n");
	else if (er == COORDINATE_PROBLEM)
		printf("There is something wrong with room coordinates\n");
	exit(EXIT_FAILURE);
}






