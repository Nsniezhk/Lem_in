/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:34:48 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/30 20:34:50 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include <stdlib.h>

static void			ret_path(t_path **p, t_node **n)
{
	t_node	*new;
	t_path	*np;

	new = new_path(n);
	if (*p == NULL)
	{
		(*p) = ft_memalloc(sizeof(t_path));
		(*p)->vertex = new;
		(*p)->next = NULL;
	}
	else
	{
		np = *p;
		while (np->next != NULL)
			np = np->next;
		np->next = ft_memalloc(sizeof(t_path));
		np->next->vertex = new;
		np->next->next = NULL;
	}
}

static void			push_path(t_graph **g, t_node **p, t_node **e, t_lem **l)
{
	t_node	*new_p;

	new_p = new_path(p);
	add_path(&new_p, e);
	push_rear(&(*l)->q, &new_p);
	node_lst_del(&new_p);
	if ((*e)->node_id != (*l)->end_id)
		(*g)->lnk_lst[(*e)->node_id].visited = 1;
}

static void			path(t_graph **g, t_lem **l, t_path **p, t_node **add)
{
	t_path	*paths;
	t_node	*v;
	int		c;

	(void)l;
	c = -1;
	while (++c < (*l)->nodes)
		(*g)->lnk_lst[c].visited = 0;
	(*g)->lnk_lst[(*l)->start_id].visited = 1;
	ret_path(p, add);
	paths = *p;
	while (paths)
	{
		v = paths->vertex;
		while (v)
		{
			if (v->node_id != (*l)->end_id)
				(*g)->lnk_lst[v->node_id].visited = 1;
			v = v->next;
		}
		paths = paths->next;
	}
}

static void			bfs(t_graph **g, t_lem **lem, t_path **all_p)
{
	t_node	*last_v;
	t_path	*s_path;
	t_node	*edges;

	while ((*lem)->q->front != NULL)
	{
		s_path = pop_front(&(*lem)->q);
		last_v = get_last_v(&s_path->vertex);
		edges = (*g)->lnk_lst[last_v->node_id].links;
		if (is_path(&last_v, (*lem)->end_id))
			path(g, lem, all_p, &s_path->vertex);
		while (edges)
		{
			if (last_v->node_id != (*lem)->end_id &&
				(*g)->lnk_lst[edges->node_id].visited == 0)
				push_path(g, &s_path->vertex, &edges, lem);
			edges = edges->next;
		}
		del_path(&s_path);
	}
}

t_path				*pre_bfs(t_graph **g, t_lem **lem)
{
	t_node	*cur;
	t_path	*all_p;
	t_node	*new;

	all_p = NULL;
	cur = (*g)->lnk_lst[(*lem)->start_id].links;
	(*g)->lnk_lst[(*lem)->start_id].visited = 1;
	while (cur)
	{
		new = node_init(&cur->name, cur->node_id,
						(*g)->lnk_lst[cur->node_id].links->links);
		push_rear(&(*lem)->q, &new);
		(*g)->lnk_lst[cur->node_id].visited = 1;
		node_lst_del(&new);
		cur = cur->next;
	}
	bfs(g, lem, &all_p);
	return (all_p);
}
