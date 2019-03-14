/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:02:20 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/12/07 18:02:22 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static int			bon_voyage(t_graph **g, t_lem **lem, int node, int ant)
{
	if ((*g)->lnk_lst[node].ant > 0 && node != (*lem)->end_id)
		return (0);
	if ((*g)->lnk_lst[node].ant == 0 && node != (*lem)->end_id)
	{
		(*g)->lnk_lst[node].ant = ant;
		ft_printf("L%d-%s ", ant, (*g)->lnk_lst[node].name);
	}
	if (node == (*lem)->end_id)
	{
		(*g)->lnk_lst[(*lem)->end_id].ant += 1;
		ft_printf("L%d-%s ", ant, (*g)->lnk_lst[node].name);
	}
	return (1);
}

static unsigned int	path_sum(t_path **paths, unsigned int id, unsigned int len)
{
	t_path			*p;
	unsigned int	sum;

	sum = 0;
	p = *paths;
	while (p)
	{
		if (p->id == id)
			break ;
		sum += len - p->len;
		p = p->next;
	}
	return (sum);
}

static void			push_on_path(t_graph **g, t_lem **lem, t_path **paths)
{
	t_path	*p;

	p = *paths;
	while (p && (*lem)->ant_start > 0)
	{
		if ((*lem)->ant_start > (int)path_sum(paths, p->id, p->len))
		{
			if (bon_voyage(g, lem, p->vertex->node_id, (*lem)->ant_path))
			{
				(*lem)->ant_path++;
				(*lem)->ant_start--;
			}
		}
		p = p->next;
	}
}

static void			move_ants(t_graph **g, t_lem **lem, t_path **ap, int prev)
{
	t_path	*p;
	t_node	*n;
	t_node	*s;

	p = *ap;
	while (p)
	{
		n = new_path(&p->vertex);
		reverse_path(&n);
		s = n;
		prev = (*lem)->end_id;
		while (n)
		{
			if (n->node_id != (*lem)->end_id)
				if ((*g)->lnk_lst[n->node_id].ant > 0)
				{
					bon_voyage(g, lem, prev, (*g)->lnk_lst[n->node_id].ant);
					(*g)->lnk_lst[n->node_id].ant = 0;
				}
			prev = n->node_id;
			n = n->next;
		}
		p = p->next;
		node_lst_del(&s);
	}
}

void				push_ants(t_graph **g, t_lem **lem, t_path **paths)
{
	int		prev_len;
	int		voyage;

	prev_len = 0;
	voyage = 1;
	(*lem)->ant_start = (*lem)->ants;
	(*lem)->ant_path = 1;
	(*lem)->l = 0;
	while (1)
	{
		if ((*g)->lnk_lst[(*lem)->end_id].ant == (*lem)->ants)
			return ;
		move_ants(g, lem, paths, 0);
		if ((*lem)->ant_start > 0)
			push_on_path(g, lem, paths);
		ft_printf("\n");
		(*lem)->l += 1;
	}
}
