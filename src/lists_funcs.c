/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:12:09 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/26 18:12:11 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

t_room		*new_room_node(char *name, int x, int y, int id)
{
	t_room	*new_room;

	if (!(new_room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (NULL);
	else
	{
		new_room->name = ft_strdup(name);
		new_room->x = x;
		new_room->y = y;
		new_room->id = id;
	}
	new_room->next = NULL;
	return (new_room);
}

t_link		*new_link_node(char *name)
{
	t_link	*new_link;

	if (!(new_link = (t_link*)ft_memalloc(sizeof(t_link))))
		return (NULL);
	else
		new_link->link = ft_strdup(name);
	new_link->next = NULL;
	return (new_link);
}

void		add_link(t_link **links, char *n)
{
	t_link *tmp;

	tmp = *links;
	if (links != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_link_node(n);
	}
	else
		*links = new_link_node(n);
}
