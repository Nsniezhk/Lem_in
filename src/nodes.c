/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:49:42 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/11/25 17:49:43 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node			*get_last_v(t_node **path)
{
	t_node	*tmp;

	tmp = *path;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int				node_links(t_graph **g, int i)
{
	t_node	*lnk_tmp;
	int		links;
	int		c;
	int		j;

	links = 0;
	c = -1;
	j = -1;
	while (++c < i)
	{
		lnk_tmp = (*g)->lnk_lst[c].links;
		if (lnk_tmp != NULL)
		{
			while (lnk_tmp)
			{
				lnk_tmp = lnk_tmp->next;
				links++;
			}
			(*g)->lnk_lst[c].lnks = links;
			links = 0;
		}
	}
	return (1);
}

t_node			*node_init(char **name, int id, int links)
{
	t_node *new_node;

	new_node = ft_memalloc(sizeof(t_node));
	new_node->name = ft_strdup(*name);
	new_node->node_id = id;
	new_node->links = links;
	new_node->next = NULL;
	return (new_node);
}
