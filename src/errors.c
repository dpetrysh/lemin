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

// void	make_warning(int er, t_info *inf)
// {
// 		inf->error = er;
// }

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
	// if (er == IT_IS_NOT_CONNECTION)
	// 	other_errors(er);
	if (er == SELF_CONNECTION)
		room_problems(er);
	if (er == START_END_ABSENT)
		room_problems(START_END_ABSENT);
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
		ft_printf("There is two rooms in your file with the same name\n");
	else if (er == ROOM_COORD_DUPLICATE)
		ft_printf("There is two rooms with the same coordinates in your file\n");
	else if (er == ROOM_NAME_ERROR)
		ft_printf("The puzzle of naming things\nI bet not first and yet not last\nLook closely if room begins\nWith 'L' or it have dash-cast!\n");
	else if (er == SELF_CONNECTION)
		ft_printf("We know that you can connect to your inner self i.e. to yourself! But rooms can't do that!\n");
	else if (er == ABSENT_WAYS)
		ft_printf("There is no ways from start to end!!!\n");
	else if (er == START_END_ABSENT)
		ft_printf("Start fon End, up to the desk! Go!\n- Sorry, master, but he is absent today...\n");
	exit(EXIT_FAILURE);
}

void	memory_problem(int er)
{
	if (er == MEMORY_PROBLEM)
		ft_printf("There are some problems with memory allocation\n");
	exit(EXIT_FAILURE);
}

int		return_errors(int er, t_info *inf, int *quality)
{
	if (er == DOUBLE_START)
	{
		*quality = 0;
		inf->error = DOUBLE_START;
		ft_printf("Be cautious: there is doubling ##start in your input file\n");
		return (DOUBLE_START);
	}
	else if (er == DOUBLE_END)
	{
		*quality = 0;
		inf->error = DOUBLE_END;
		ft_printf("Be cautious: there is doubling ##end in your input file\n");
		return (DOUBLE_START);
	}
	else if (er == IT_IS_NOT_CONNECTION)
	{
		inf->error = IT_IS_NOT_CONNECTION;
		ft_printf("There ought to be connection\nBut look! there is instead\nDemanding on defection\nSome string! Are you just mad?\n");
	}
	return (-1);
}

void	other_errors(int er)
{
	if (er == ANT_AMOUNT_ERROR)
		ft_printf("I am the Number of the ants\nAnd you know that I do like\nTo wear my pants of digits\nInstead of symbols dyke!\n");
	else if (er == CONNECT_IS_ROOM_ISNT)
		ft_printf("There is a false connection\nThat does a room consists\nDevoided by perfection\nBecause the room is missed\n");
	// else if (er == DOUBLE_CONNECTION)
	// 	ft_printf("Please give me satisfaction -\nGet rid of double connection\n");
	else if (er == DOUBLE_START)
		ft_printf("There is doubling ##START\n");
	else if (er == DOUBLE_END)
		ft_printf("There is doubling ##END\n");
	else if (er == COORDINATE_PROBLEM)
		ft_printf("There is something wrong with room coordinates\n");
	else if (er == WRONG_FILE)
		ft_printf("It was a good attempt\nTo broke my little Lem_in\nBut you cannot pretend\nThat pushing forward error!\n");
	exit(EXIT_FAILURE);
}





