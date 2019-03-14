/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_useful.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:06:47 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/28 01:06:51 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

int			get_room_id(char *search, t_room **rooms)
{
	t_room *tmp;

	tmp = *rooms;
	while (tmp)
	{
		if ((ft_strcmp(search, tmp->name)) == 0)
			return (tmp->id);
		tmp = tmp->next;
	}
	return (0);
}

int			room_exist(char *search, t_room **rooms)
{
	t_room *tmp;

	tmp = *rooms;
	if (tmp->name != NULL)
	{
		while (tmp)
		{
			if ((ft_strcmp(tmp->name, search)) == 0)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

int			valid_coord(int x, int y, t_room **r)
{
	t_room *tmp;

	tmp = *r;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

size_t		room_count(t_room **lst)
{
	t_room	*r;
	size_t	i;

	r = *lst;
	i = 0;
	while (r != NULL)
	{
		r = r->next;
		i++;
	}
	return (i);
}

char		*trim_line(char *line)
{
	size_t	l;
	char	*trim;

	l = 0;
	while (line[l] != ' ' && line[l] != '\0')
		l++;
	trim = ft_strndup(line, l);
	return (trim);
}
