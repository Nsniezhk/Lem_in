/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:54:58 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/11/25 17:56:17 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "ft_printf.h"

static int			path_cross(t_path **p, t_node **origin, int end)
{
	t_node	*next;
	t_node	*next_refresh;
	t_node	*cur;

	next = (*p)->vertex;
	cur = (*origin);
	while (cur)
	{
		next_refresh = next;
		while (next_refresh)
		{
			if (cur->node_id == next_refresh->node_id)
				if (cur->node_id != end)
					return (1);
			next_refresh = next_refresh->next;
		}
		cur = cur->next;
	}
	return (0);
}

static void			individual_path(t_path **p, int end)
{
	t_node	*origin;
	t_node	*next_path;
	t_path	*tmp_p;
	t_path	*next;

	tmp_p = *p;
	origin = (*p)->vertex;
	while (tmp_p)
	{
		if (tmp_p->next == NULL)
			return ;
		next = tmp_p->next;
		next_path = next->vertex;
		if (path_cross(&next, &origin, end) == 1)
		{
			node_lst_del(&next_path);
			tmp_p->next = tmp_p->next->next;
			free(next);
		}
		else
			tmp_p = tmp_p->next;
	}
}

void				del_cros_paths(t_path **p, int end)
{
	t_path	*tmp_p;

	tmp_p = *p;
	while (tmp_p)
	{
		individual_path(&tmp_p, end);
		tmp_p = tmp_p->next;
	}
}

void				del_rest(t_path **p)
{
	t_path	*cur;
	t_path	*next;
	t_node	*n;

	cur = *p;
	while (cur)
	{
		next = cur->next;
		n = cur->vertex;
		node_lst_del(&n);
		free(cur);
		cur = next;
	}
	*p = NULL;
}

void				only_one(t_path **p)
{
	t_path *single;

	single = (t_path*)ft_memalloc(sizeof(t_path));
	single->vertex = new_path(&(*p)->vertex);
	del_rest(p);
	*p = single;
}
