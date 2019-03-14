/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_farm_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:20:34 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/25 17:20:35 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem_in.h"
#include <stdlib.h>

int			read_line(char **line)
{
	if (get_next_line(0, line) <= 0)
	{
		ft_strdel(line);
		return (0);
	}
	if (*(line) == NULL || *(line[0]) == '\0')
	{
		link_error(2);
		return (0);
	}
	return (1);
}

int			parse_room(char **line, t_lem **lem)
{
	if (*line[0] == '#')
	{
		if (!(is_comment(lem, *line)))
			if (!(is_command(lem, *line)))
				exit(0);
		return (1);
	}
	if (!(valid_room(*line, &(*lem)->rooms, &(*lem)->room_id)))
	{
		return (0);
	}
	else
		stdout_add(lem, *line, ft_strlen(*line) + 1);
	return (1);
}

int			proceed_rooms(t_lem **lem)
{
	char	*line;

	line = NULL;
	while (1)
	{
		if ((read_line(&line)) == 0)
		{
			general_error(-2);
			exit(0);
		}
		if (link_detect(line, lem))
		{
			ft_strdel(&line);
			return (1);
		}
		if (!(parse_room(&line, lem)))
			exit(0);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

int			parse_links(char **line, t_lem **lem, char ***s)
{
	char *trim;

	if (!(check_link_split(*s, -1, &(*lem)->rooms)))
		exit(0);
	if (is_room(*line))
	{
		link_error(-5);
		return (0);
	}
	if (confirm_link(*line))
	{
		trim = trim_line(*line);
		if (!(valid_link(trim, lem, s)))
		{
			ft_strdel(&trim);
			return (0);
		}
		ft_strdel(&trim);
	}
	return (1);
}

int			proceed_links(t_lem **lem)
{
	char	*line;
	char	**s;

	line = NULL;
	while (1)
	{
		if ((read_line(&line)) == 0)
			return (1);
		if (line[0] == '#')
		{
			if (is_command(lem, line))
				ft_strdel(&line);
			else
				is_command(lem, line);
			continue ;
		}
		s = ft_strsplit(line, '-');
		if (!(parse_links(&line, lem, &s)))
			break ;
		ft_strdel(&line);
		ft_splitdel(&s);
	}
	ft_strdel(&line);
	ft_splitdel(&s);
	return (1);
}
