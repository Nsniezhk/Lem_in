/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 03:10:14 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/28 03:10:15 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include <stdlib.h>

t_graph		*graph_init(int nodes)
{
	t_graph *new;
	int		i;

	i = -1;
	new = (t_graph*)ft_memalloc(sizeof(t_graph));
	new->lnk_lst = (t_adjlst*)ft_memalloc(sizeof(t_adjlst) * nodes);
	while (++i < nodes)
	{
		new->lnk_lst[i].links = NULL;
		new->lnk_lst[i].level = -1;
		new->lnk_lst[i].visited = 0;
	}
	return (new);
}

t_elem		*split_edge(char *link, t_room **rooms)
{
	t_elem	*n;
	char	**s;

	s = ft_strsplit(link, '-');
	n = (t_elem*)ft_memalloc(sizeof(t_elem));
	n->node_1 = ft_strdup(s[0]);
	n->node_2 = ft_strdup(s[1]);
	n->n1_id = get_room_id(s[0], rooms);
	n->n2_id = get_room_id(s[1], rooms);
	ft_splitdel(&s);
	return (n);
}

void		fill_graph_list(t_graph *g, t_link *edges, t_room **rooms)
{
	t_elem	*n;
	t_link	*l;
	t_node	*new;

	l = edges;
	while (l)
	{
		n = split_edge(l->link, rooms);
		new = node_init(&n->node_1, n->n1_id, 0);
		new->next = new_path(&g->lnk_lst[n->n2_id].links);
		if (g->lnk_lst[n->n2_id].name == NULL)
			g->lnk_lst[n->n2_id].name = ft_strdup(n->node_2);
		g->lnk_lst[n->n2_id].v_id = n->n2_id;
		add_path(&g->lnk_lst[n->n2_id].links, &new);
		node_lst_del(&new);
		new = node_init(&n->node_2, n->n2_id, 0);
		new->next = new_path(&g->lnk_lst[n->n1_id].links);
		if (g->lnk_lst[n->n1_id].name == NULL)
			g->lnk_lst[n->n1_id].name = ft_strdup(n->node_1);
		g->lnk_lst[n->n1_id].v_id = n->n1_id;
		add_path(&g->lnk_lst[n->n1_id].links, &new);
		elem_del(&n);
		node_lst_del(&new);
		l = l->next;
	}
}
