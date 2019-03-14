/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:03:10 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/12/10 17:03:12 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void		del_path(t_path **p)
{
	if (*p != NULL)
	{
		node_lst_del(&(*p)->vertex);
		free(*p);
		*p = NULL;
	}
}

void		elem_del(t_elem **e)
{
	ft_strdel(&(*e)->node_1);
	ft_strdel(&(*e)->node_2);
	free((*e));
	*e = NULL;
}

void		node_lst_del(t_node **n)
{
	t_node	*t;
	t_node	*t_next;

	t = (*n);
	while (t)
	{
		t_next = t->next;
		ft_strdel(&t->name);
		free(t);
		t = t_next;
	}
	*n = NULL;
}
