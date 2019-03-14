/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 05:15:30 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/28 05:15:32 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static void		print_paths(t_path **path, int i)
{
	t_node	*tmp;

	while ((*path))
	{
		tmp = (*path)->vertex;
		if (i == 1)
		{
			ft_printf("\x1b[32m""SHORTEST path [len [%d]]", (*path)->len);
			i++;
		}
		else
			ft_printf("\x1b[35m""path (%d) [len [%d]]", i++, (*path)->len);
		ft_printf("\x1b[36m"" [START");
		while (tmp)
		{
			ft_printf("\x1b[31m""->");
			ft_printf("\x1b[36m""(%s)", tmp->name);
			tmp = tmp->next;
		}
		ft_printf("]");
		ft_printf("\x1b[33m""\n____________________");
		ft_printf("___________________\n""\x1b[0m");
		(*path) = (*path)->next;
	}
}

void			print_hive(t_lem **lem)
{
	t_list	*ls;

	ft_lstrev(&(*lem)->stdout_list);
	ls = (*lem)->stdout_list;
	while (ls)
	{
		ft_printf("%s\n", ls->content);
		ls = ls->next;
	}
	ft_printf("\n");
}

void			print_rooms(t_lem **lem)
{
	t_room *r;

	r = (*lem)->rooms;
	while (r)
	{
		ft_printf("\x1b[32m""room name(%s)is:  id(%d) x(%d) y(%d)\n""\x1b[0m",
			r->name, r->id, r->x, r->y);
		r = r->next;
	}
}

static void		print_g(t_graph **g, int i)
{
	int		c;
	t_node	*n;

	c = -1;
	ft_printf("\x1b[33m""_____________ADJACENCY LIST_____________\n");
	while (++c < i)
	{
		n = (*g)->lnk_lst[c].links;
		if (n != NULL)
		{
			ft_printf("\x1b[97m""Links of room [%s] amount of links [%d]\n",
				(*g)->lnk_lst[c].name, (*g)->lnk_lst[c].lnks);
			while (n)
			{
				ft_printf("\x1b[32m""->%s", n->name);
				n = n->next;
			}
			ft_printf("\n");
		}
	}
}

void			print_extra(t_graph **g, t_lem **lem, t_path **ap)
{
	t_room	*r;
	t_link	*lnk;
	t_path	*p;

	r = (*lem)->rooms;
	lnk = (*lem)->links;
	while (r)
	{
		ft_printf("\x1b[32m""room name(%s)is:  id(%d) x(%d) y(%d)\n""\x1b[0m",
			r->name, r->id, r->x, r->y);
		r = r->next;
	}
	while (lnk)
	{
		ft_printf("\x1b[36m""Link is: (%s)\n", lnk->link);
		lnk = lnk->next;
	}
	print_g(g, (*lem)->nodes);
	ft_printf("\x1b[33m""_______________BFS PATHS_______________\n");
	p = *ap;
	print_paths(&p, 1);
}
