/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_useful.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:18:04 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/28 01:18:06 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

int			stdout_add(t_lem **lem, char *line, size_t len)
{
	t_list	*cur;

	cur = ft_lstnew(line, len);
	ft_lstadd(&(*lem)->stdout_list, cur);
	return (1);
}

int			confirm_link(char *line)
{
	int	i;

	i = -1;
	if (ft_strstr(line, "-"))
	{
		while (line[++i] != ' ')
			if (line[i] == '\0')
				return (1);
		if (line[i] != '\0')
			while (line[i] != '\0')
				if (line[i++] != ' ')
					return (0);
		return (1);
	}
	return (0);
}

int			link_detect(char *line, t_lem **lem)
{
	char	**s;
	char	*trim;
	int		y;

	y = 0;
	if (confirm_link(line))
	{
		trim = trim_line(line);
		s = ft_strsplit(trim, '-');
		while (s[y] != NULL)
			y++;
		if ((y != 1 && y != 2) || !valid_link(trim, lem, &s))
		{
			ft_splitdel(&s);
			ft_strdel(&trim);
			return (room_error(-7));
		}
		ft_strdel(&trim);
		ft_splitdel(&s);
		return (1);
	}
	return (0);
}

size_t		link_count(t_link *lst)
{
	t_link *l;
	size_t i;

	l = lst;
	i = 0;
	while (l != NULL)
	{
		l = l->next;
		i++;
	}
	return (i);
}

int			link_exist(char *search, t_link *links)
{
	t_link *tmp;

	tmp = links;
	if (tmp->link != NULL)
	{
		while (tmp)
		{
			if ((ft_strcmp(tmp->link, search)) == 0)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}
