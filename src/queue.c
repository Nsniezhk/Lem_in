/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:33:30 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/11/25 17:33:33 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include <stdlib.h>

t_queue		*queue_init(void)
{
	t_queue	*q;

	q = (t_queue*)ft_memalloc(sizeof(t_queue));
	q->front = NULL;
	q->rear = NULL;
	return (q);
}

void		push_rear(t_queue **q, t_node **n)
{
	t_path *new;

	new = (t_path*)ft_memalloc(sizeof(t_path));
	new->vertex = new_path(n);
	if ((*q)->rear == NULL)
	{
		(*q)->front = new;
		(*q)->rear = new;
		return ;
	}
	(*q)->rear->next = new;
	(*q)->rear = new;
}

t_path		*pop_path(t_path **path)
{
	t_path	*tmp;
	t_path	*ret;

	tmp = *path;
	ret = (t_path*)ft_memalloc(sizeof(t_path));
	ret->vertex = new_path(&tmp->vertex);
	return (ret);
}

t_path		*pop_front(t_queue **q)
{
	t_path	*t;
	t_path	*del;

	if ((*q)->front == NULL)
		return (NULL);
	t = pop_path(&(*q)->front);
	del = (*q)->front;
	(*q)->front = (*q)->front->next;
	if ((*q)->front == NULL)
		(*q)->rear = NULL;
	node_lst_del(&del->vertex);
	free(del);
	return (t);
}

void		del_queue(t_queue **q)
{
	free((*q)->front);
	free((*q)->rear);
	free((*q));
	*q = NULL;
}
