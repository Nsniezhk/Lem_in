/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:04:30 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/26 19:04:31 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

int		ant_error(int er)
{
	ft_printf("\x1b[97m""Lem_in:");
	ft_printf("\x1b[91m"" [ERROR] ""\x1b[93m");
	if (er == -1)
		ft_printf("No ants provided!\n");
	if (er == -2)
		ft_printf("Amount of ants is zero!\n");
	if (er == -3)
		ft_printf("Negative amount of ants!\n");
	if (er == -4)
		ft_printf("Ant value must be a number!\n");
	if (er == -5)
		ft_printf("Ant value is too large to handle!\n");
	if (er == 0)
		ft_printf("UNDEFINED ERROR!!!\n");
	ft_printf("\x1b[0m");
	return (0);
}

int		room_error(int er)
{
	ft_printf("\x1b[97m""Lem_in:");
	ft_printf("\x1b[91m"" [ERROR] ""\x1b[93m");
	if (er == -2)
		ft_printf("Rooms with same name are not allowed!\n");
	if (er == -3)
		ft_printf("Passed coordinate is not number!\n");
	if (er == -4)
		ft_printf("Rooms must have different coordinates!\n");
	if (er == -5)
		ft_printf("Room name should not contain charecter '-'!\n");
	if (er == -6)
		ft_printf("Room name could not start with charecter 'L'!\n");
	if (er == -7)
		ft_printf("Invalid room. ABORTING!\n");
	if (er == 0)
		ft_printf("UNDEFINED ERROR!!!\n");
	ft_printf("\x1b[0m");
	return (0);
}

int		command_error(int er)
{
	ft_printf("\x1b[97m""Lem_in:");
	ft_printf("\x1b[91m"" [ERROR] ""\x1b[93m");
	if (er == -1)
		ft_printf("No command ##End!\n");
	if (er == -2)
		ft_printf("No command ##Start!\n");
	if (er == -3)
		ft_printf("More than one command ##Start. ABORTING!\n");
	if (er == -4)
		ft_printf("More than one command ##End. ABORTING!\n");
	if (er == -5)
		ft_printf("Start room is not valid. ABORTING!\n");
	if (er == -6)
		ft_printf("End room is not valid. ABORTING!\n");
	if (er == -7)
		ft_printf("No valid room after command #START. ABORTING!\n");
	if (er == -8)
		ft_printf("No valid room after command #END. ABORTING!\n");
	if (er == 0)
		ft_printf("COMMAND UNDEFINED ERROR!!!\n");
	ft_printf("\x1b[0m");
	return (0);
}

int		link_error(int er)
{
	ft_printf("\x1b[97m""Lem_in:");
	ft_printf("\x1b[91m"" [ERROR] ""\x1b[93m");
	if (er == -1)
		ft_printf("Link is not valid!\n");
	if (er == -2)
		ft_printf("Link to non existing room!\n");
	if (er == -3)
		ft_printf("Link already exist!\n");
	if (er == -4)
		ft_printf("Link to room itself!\n");
	if (er == -5)
	{
		ft_printf("During links validation room declaration ocures!\n");
		ft_printf("\x1b[91m""Check that no rooms declared in links block, ");
		ft_printf("and no links declared in room block!\n""\x1b[0m");
	}
	if (er == -6)
		ft_printf("##Start command in link block!\n");
	if (er == -7)
		ft_printf("##End command in link block!\n");
	if (er == 2)
		return (try_execute());
	return (0);
}

int		general_error(int er)
{
	ft_printf("\x1b[97m""Lem_in:");
	ft_printf("\x1b[91m"" [ERROR] ""\x1b[93m");
	if (er == -1)
		ft_printf("Comand ##Start or ##End before ant declaration!\n");
	if (er == -2)
		ft_printf("Not enough data ABORTING!\n");
	if (er == -5)
		ft_printf("Invalid firsr entry line!\n");
	if (er == -6)
		ft_printf("No rooms provided!\n");
	if (er == -7)
		ft_printf("No links provided!\n");
	if (er == -8)
		ft_printf("START and END has no possible paths to go through!\n");
	if (er == -9)
		ft_printf("START has no edges!\n");
	if (er == -10)
		ft_printf("No connection to one or more nodes!\n");
	if (er == -11)
		ft_printf("Undefined sequance of symbols!\n");
	return (0);
}
