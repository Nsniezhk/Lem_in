/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:33:03 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/11/25 17:33:05 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include <stdlib.h>

void		set_paths_len(t_path **paths)
{
	t_path			*p;
	t_node			*n;
	unsigned int	id;
	unsigned int	len;

	p = *paths;
	len = 0;
	id = 0;
	while (p)
	{
		n = p->vertex;
		len = 0;
		id++;
		while (n)
		{
			len++;
			n = n->next;
		}
		p->len = len;
		p->id = id;
		p = p->next;
	}
}

t_node		*new_path_node(t_node **n)
{
	t_node	*new_node;

	if (!(new_node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (NULL);
	else
	{
		new_node->name = ft_strdup((*n)->name);
		new_node->node_id = (*n)->node_id;
		new_node->links = (*n)->links;
	}
	new_node->next = NULL;
	return (new_node);
}

void		add_path(t_node **paths, t_node **cur)
{
	t_node *tmp;

	if (*paths != NULL)
	{
		tmp = *paths;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new_path_node(cur);
	}
	else
	{
		*paths = new_path_node(cur);
	}
}

t_node		*new_path(t_node **src)
{
	t_node	*new;
	t_node	*tmp;

	tmp = *src;
	new = NULL;
	while (tmp)
	{
		add_path(&new, &tmp);
		tmp = tmp->next;
	}
	return (new);
}

int			is_path(t_node **n, int node)
{
	t_node *tmp;

	if (!(tmp = *n))
		ft_printf("ERROR\n");
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->node_id == node)
		return (1);
	else
		return (0);
}
