/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:53:51 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/25 12:53:53 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem_in.h"
#include <stdlib.h>

static int			get_ants(t_lem **lem, char *line)
{
	int		res;

	res = 0;
	if ((res = ft_isstrnum(line)))
	{
		stdout_add(lem, line, ft_strlen(line) + 1);
		if (((*lem)->ants = lem_atoi(line)) == 0)
			return (0);
	}
	ft_strdel(&line);
	if (res == -2)
		return (ant_error(-1));
	if (res == -1)
		return (ant_error(-3));
	if (res == 0)
		return (ant_error(-4));
	if ((*lem)->ants == 0)
		return (ant_error(-2));
	return (1);
}

static int			validate_farm(t_lem **lem)
{
	proceed_rooms(&(*lem));
	if (!(room_count(&(*lem)->rooms)))
		return (general_error(-6));
	if (!proceed_links(lem))
		exit(0);
	if (!(link_count((*lem)->links)))
		return (general_error(-7));
	if ((*lem)->start == 0)
		return (command_error(-2));
	if ((*lem)->end == 0)
		return (command_error(-1));
	return (1);
}

static int			valid_entry(t_lem **lem)
{
	int		res;
	char	*line;

	if ((res = get_next_line(0, &line) > 0))
	{
		while (line[0] == '#')
		{
			if (ft_strstr(line, "##start") || ft_strstr(line, "##end") ||
				ft_strstr(line, "##START") || ft_strstr(line, "##END"))
			{
				ft_strdel(&line);
				return (general_error(-1));
			}
			stdout_add(lem, line, ft_strlen(line) + 1);
			get_next_line(0, &line);
		}
		if (!(get_ants(lem, line)))
			return (0);
	}
	if (line == NULL || line[0] == '\0')
		return (ant_error(-5));
	return (1);
}

static int			proceed(t_lem **lem, t_graph **g)
{
	t_path	*all_p;

	(*lem)->nodes = room_count(&(*lem)->rooms);
	(*g) = graph_init((*lem)->nodes);
	fill_graph_list(*g, (*lem)->links, &(*lem)->rooms);
	if (((*g)->lnk_lst[(*lem)->end_id].links) == NULL)
		return (general_error(-8));
	if (((*g)->lnk_lst[(*lem)->start_id].links) == NULL)
		return (general_error(-9));
	node_links(g, (*lem)->nodes);
	print_hive(lem);
	all_p = pre_bfs(g, lem);
	set_paths_len(&all_p);
	if ((*lem)->one_way == 1)
		only_one(&all_p);
	else
		del_cros_paths(&all_p, (*lem)->end_id);
	if ((*lem)->info == 1)
		print_extra(g, lem, &all_p);
	push_ants(g, lem, &all_p);
	if ((*lem)->lines == 1)
		ft_printf("\x1b[36m""LINES ON STDOUT [%d]\n""\x1b[0m", (*lem)->l);
	del_rest(&all_p);
	return (1);
}

int					main(int argc, char **argv)
{
	t_lem	*lem;
	t_graph	*graph;

	lem = (t_lem*)ft_memalloc(sizeof(t_lem));
	lem->stdout_list = NULL;
	lem->rooms = NULL;
	lem->links = NULL;
	lem->q = (t_queue*)ft_memalloc(sizeof(t_queue));
	lem->q->front = NULL;
	lem->q->rear = NULL;
	if (argc != 0)
		if (!(get_flags(&lem, argc, argv)))
			exit(0);
	if (!(valid_entry(&lem)))
	{
		show_usage();
		return (0);
	}
	if (!(validate_farm(&lem)))
		return (0);
	if (!(proceed(&lem, &graph)))
		return (0);
	return (0);
}
