/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_useful_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:59:01 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/11/25 17:59:02 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

int			check_split(char **s, int y)
{
	while (s[++y] != NULL)
	{
		if (y > 2)
			return (room_error(-7));
		if (!(ft_isstrnum(s[y])))
			return (room_error(-3));
	}
	if (y == 1)
		return (general_error(-11));
	if (y < 3)
		return (room_error(-7));
	return (1);
}

int			is_room(char *line)
{
	char	**s;
	int		y;

	y = 0;
	s = ft_strsplit(line, ' ');
	while (s[++y] != NULL)
		if (!(ft_isstrnum(s[y])))
			return (link_error(-1));
	if (((ft_strchr(line, '-')) && y != 1))
		return (link_error(-1));
	if ((ft_strchr(line, '-')) && y == 1)
	{
		ft_splitdel(&s);
		return (0);
	}
	ft_splitdel(&s);
	return (1);
}

char		*get_room_name(char *line)
{
	char	*name;
	int		i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	name = ft_strndup(line, i);
	return (name);
}
