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
	else if (er == ROOM_COORD_DUPLICATE)
		room_problems(er);
	else if (er == ROOM_NAME_ERROR)
		room_problems(er);
	else if (er == MEMORY_PROBLEM)
		memory_problem(er);
	else if (er == ANT_AMOUNT_ERROR)
		other_errors(er);
	else if (er == CONNECT_IS_ROOM_ISNT)
		other_errors(er);
	else if (er == SELF_CONNECTION)
		room_problems(er);
	else if (er == START_END_ABSENT)
		room_problems(START_END_ABSENT);
	else if (er == DOUBLE_START)
		other_errors(DOUBLE_START);
	else if (er == DOUBLE_END)
		other_errors(DOUBLE_END);
	else if (er == ABSENT_WAYS)
		room_problems(ABSENT_WAYS);
	else if (er == EMPTY_LINE)
		other_errors(EMPTY_LINE);
}

void	room_problems(int er)
{
	ft_printf(RED"ERROR:\n"RESET);
	if (er == ROOM_NAME_DUPLICATE)
		ft_printf("There is two rooms in your file with the same name\n");
	else if (er == ROOM_COORD_DUPLICATE)
		ft_printf("There is rooms with the same coordinates in your file\n");
	else if (er == ROOM_NAME_ERROR)
		poem_about_room_name();
	else if (er == SELF_CONNECTION)
	{
		ft_printf("We know that you can connect to your inner self");
		ft_printf(" i.e. to yourself! But rooms can't do that!\n");
	}
	else if (er == ABSENT_WAYS)
		ft_printf("There is no ways from start to end!!!\n");
	else if (er == START_END_ABSENT)
	{
		ft_printf("Start fon End, up to the desk! Go!\n");
		ft_printf("- Sorry, master, but he is absent today...\n");
	}
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
		return (DOUBLE_START);
	}
	else if (er == DOUBLE_END)
	{
		*quality = 0;
		inf->error = DOUBLE_END;
		return (DOUBLE_END);
	}
	else if (er == IT_IS_NOT_CONNECTION)
		inf->error = IT_IS_NOT_CONNECTION;
	return (-1);
}

void	other_errors(int er)
{
	ft_printf(RED"ERROR:\n"RESET);
	if (er == ANT_AMOUNT_ERROR)
		poem_about_ants_num();
	else if (er == EMPTY_LINE)
		ft_printf("Watch out! Empty line on the way!\n");
	else if (er == CONNECT_IS_ROOM_ISNT)
		poem_about_absent_room();
	else if (er == DOUBLE_START)
		ft_printf("There is doubling ##START\n");
	else if (er == DOUBLE_END)
		ft_printf("There is doubling ##END\n");
	else if (er == COORDINATE_PROBLEM)
		ft_printf("There is something wrong with room coordinates\n");
	else if (er == WRONG_FILE)
		poem_about_wrong_file();
	exit(EXIT_FAILURE);
}





