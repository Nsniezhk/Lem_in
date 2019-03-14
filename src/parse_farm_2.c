/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_farm_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:52:00 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/12/03 15:52:02 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem_in.h"
#include "stdlib.h"

static int			room_check(char **s, t_room **r, int *i)
{
	t_room	*tmp;
	int		y;

	y = 0;
	if (ft_strstr(s[0], "-"))
		return (room_error(-5));
	if (*r != NULL)
		if ((room_exist(s[0], r)))
			return (room_error(-2));
	if (!(check_split(&(*s), y)))
		return (0);
	if (!(valid_coord(ft_atoi(s[1]), ft_atoi(s[2]), r)))
		return (room_error(-4));
	if (*r != NULL)
	{
		tmp = *r;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_room_node(s[0], ft_atoi(s[1]), ft_atoi(s[2]), *i);
	}
	else
		*r = new_room_node(s[0], ft_atoi(s[1]), ft_atoi(s[2]), *i);
	(*i)++;
	return (1);
}

int					valid_room(char *line, t_room **rooms, int *i)
{
	t_room	*tmp;
	char	**s;
	int		y;

	tmp = NULL;
	s = ft_strsplit(line, ' ');
	y = 0;
	if (s[0][0] != 'L')
	{
		if (!(room_check(s, rooms, &(*i))))
		{
			ft_splitdel(&s);
			return (0);
		}
		ft_splitdel(&s);
		return (1);
	}
	ft_splitdel(&s);
	return (room_error(-6));
}

int					check_link_split(char **s, int y, t_room **r)
{
	int	br;

	br = 0;
	while (s[++y] != NULL)
	{
		if (y > 1)
			return (link_error(-1));
		if (*r == NULL)
			return (0);
		if (!(room_exist(&(*s[y]), r)))
		{
			br = 1;
			link_error(-2);
			exit(0);
		}
	}
	if (br == 1)
		return (0);
	if (y == 1)
		return (general_error(-11));
	return (1);
}

static int			check_link(char **s, char **line, t_lem **lem, int *y)
{
	t_link *tmp;

	if ((ft_strcmp(s[0], s[1]) == 0))
	{
		return (link_error(-4));
	}
	if ((*y) == 0)
	{
		return (is_room(*line));
	}
	if ((*lem)->links != NULL)
	{
		tmp = (*lem)->links;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_link_node(*line);
	}
	else
		(*lem)->links = new_link_node(*line);
	stdout_add(lem, *line, ft_strlen(*line) + 1);
	return (1);
}

int					valid_link(char *line, t_lem **lem, char ***s)
{
	t_link	*tmp;
	int		y;

	tmp = NULL;
	if ((*lem)->links != NULL)
		if (link_exist(line, (*lem)->links))
			return (link_error(-3));
	y = -1;
	if (!(check_link(*s, &line, lem, &y)))
		exit(0);
	return (1);
}
