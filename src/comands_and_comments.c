/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_and_comments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:03:05 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/26 20:03:05 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static int			get_start(t_lem **lem)
{
	char	*line;

	if ((get_next_line(0, &line)) != -1)
	{
		if (line[0] == '\0' || (ft_strncmp(line, "#", 1)) == 0)
			return (command_error(-7));
		if (ft_strstr(line, "-") && !(ft_strstr(line, " ")))
			return (command_error(-7));
		(*lem)->start += 1;
		stdout_add(lem, line, ft_strlen(line) + 1);
		if (!(valid_room(line, &(*lem)->rooms, &(*lem)->room_id)))
			return (command_error(-5));
		(*lem)->start_name = get_room_name(line);
		(*lem)->start_id = (*lem)->room_id - 1;
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

static int			get_end(t_lem **lem)
{
	char	*line;

	if ((get_next_line(0, &line)) != -1)
	{
		if (line[0] == '\0' || (ft_strncmp(line, "#", 1)) == 0)
			return (command_error(-8));
		if (ft_strstr(line, "-") && !(ft_strstr(line, " ")))
			return (command_error(-7));
		(*lem)->end += 1;
		stdout_add(lem, line, ft_strlen(line) + 1);
		if (!(valid_room(line, &(*lem)->rooms, &(*lem)->room_id)))
			return (command_error(-6));
		(*lem)->end_name = get_room_name(line);
		(*lem)->end_id = (*lem)->room_id - 1;
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

int					is_command(t_lem **lem, char *line)
{
	if ((ft_strcmp(line, "##start")) == 0 || (ft_strcmp(line, "##START")) == 0)
	{
		if ((*lem)->start > 0)
			return (command_error(-3));
		stdout_add(lem, line, ft_strlen(line) + 1);
		if ((get_start(lem)))
			return (1);
		ft_strdel(&line);
		return (0);
	}
	else if ((ft_strcmp(line, "##end")) == 0 || (ft_strcmp(line, "##END")) == 0)
	{
		if ((*lem)->end > 0)
			return (command_error(-4));
		stdout_add(lem, line, ft_strlen(line) + 1);
		if ((get_end(lem)))
			return (1);
		ft_strdel(&line);
		return (0);
	}
	stdout_add(lem, line, ft_strlen(line) + 1);
	return (1);
}

int					is_comment(t_lem **lem, char *line)
{
	if (line[1] != '#')
	{
		stdout_add(lem, line, ft_strlen(line) + 1);
	}
	else
	{
		return (0);
	}
	return (1);
}
