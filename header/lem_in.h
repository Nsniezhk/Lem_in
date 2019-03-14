/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:57:58 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/25 13:11:38 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define MAX_INT 2147483647
# include "libft.h"

/*
**		STRUCT TO STORE SPLITED LINK
*/

typedef	struct		s_elem
{
	char			*node_1;
	char			*node_2;
	int				n1_id;
	int				n2_id;
}					t_elem;

/*
**		STRUCT TO STORE VERTEX DATA
*/

typedef	struct		s_room
{
	char			*name;
	int				id;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

/*
**		STRUCT TO STORE LINK DATA
*/

typedef	struct		s_link
{
	char			*link;
	struct s_link	*next;
}					t_link;

/*
**			GRAPH AND ADJACENCY LIST
**			| | | | | | | | | | | |
**			V V V V V V V V V V V V
*/

typedef	struct		s_node
{
	char			*name;
	int				node_id;
	int				links;
	struct s_node	*next;
}					t_node;

typedef	struct		s_adjlst
{
	char			*name;
	int				v_id;
	int				visited;
	int				ant;
	int				level;
	int				v_in;
	int				v_out;
	int				v_same;
	int				lnks;
	t_node			*links;
}					t_adjlst;

typedef	struct		s_graph
{
	char			*name;
	int				links;
	t_adjlst		*lnk_lst;
}					t_graph;

/*
**			PATH QUEUE IMPLEMENTATION
**			| | | | | | | | | | | | |
**			V V V V V V V V V V V V V
*/

typedef	struct		s_path
{
	t_node			*vertex;
	unsigned int	len;
	unsigned int	id;
	struct s_path	*next;
}					t_path;

typedef	struct		s_queue
{
	struct s_path	*front;
	struct s_path	*rear;
}					t_queue;

/*
**		STRUCT TO STORE PROJECT GENERAL DATA
*/

typedef struct		s_lem
{
	t_list			*stdout_list;
	t_link			*links;
	t_room			*rooms;
	t_queue			*q;
	int				ants;
	int				ant_path;
	int				ant_start;
	int				start;
	int				end;
	int				exit_lvl;
	int				room_id;
	int				s_room;
	int				start_id;
	int				end_id;
	int				nodes;
	int				info;
	int				one_way;
	int				muse;
	int				lines;
	int				l;
	char			*start_name;
	char			*end_name;
}					t_lem;

/*
**						PROJECT FUNCTIONS
**						_________________
**						| | | | | | | | |
**						V V V V V V V V V
*/

/*
**						GRAPH AND QUEUE
*/

t_graph				*graph_init(int nodes);
void				fill_graph_list(t_graph *g, t_link *edges, t_room **rooms);
int					get_room_id(char *search, t_room **rooms);
t_node				*node_init(char **name, int id, int links);
void				node_lst_del(t_node **n);
t_path				*pre_bfs(t_graph **g, t_lem **lem);
void				push_ants(t_graph **g, t_lem **lem, t_path **paths);

/*
**						HIVE_VALIDATION
*/

int					proceed_rooms(t_lem **lem);
int					valid_room(char *line, t_room **rooms, int *id);
int					room_exist(char *search, t_room **rooms);
size_t				room_count(t_room **lst);
int					valid_coord(int x, int y, t_room **r);
int					valid_room(char *line, t_room **rooms, int *i);
int					proceed_links(t_lem **lems);
int					valid_link(char *line, t_lem **lem, char ***s);
int					check_link_split(char **s, int y, t_room **r);

/*
**						LISTS
*/

void				rev_rooms(t_room **rooms);
t_room				*new_room_node(char *name, int x, int y, int id);
void				add_link(t_link **links, char *n);
t_link				*new_link_node(char *name);
size_t				link_count(t_link *lst);

/*
**						ERROR MENEGMENT
*/

int					ant_error(int er);
int					room_error(int er);
int					link_error(int er);
int					command_error(int er);
int					general_error(int er);

/*
**						COMMENTS AND COMMANDS
*/

int					is_command(t_lem **lem, char *line);
int					is_comment(t_lem **lem, char *line);

/*
**						USEFUL
*/

int					is_room(char *line);
int					confirm_link(char *line);
int					link_detect(char *line, t_lem **lem);
int					check_split(char **s, int y);
char				*trim_line(char *line);
int					stdout_add(t_lem **lem, char *line, size_t len);
int					is_num(char *l);
int					link_exist(char *search, t_link *links);
int					node_links(t_graph **g, int i);
int					get_flags(t_lem **l, int argc, char **argv);
t_node				*get_last_v(t_node **path);

/*
**						DISPLAY
*/

void				print_hive(t_lem **lem);
void				print_extra(t_graph **g, t_lem **lem, t_path **ap);

/*
**						PATHS
*/

int					is_path(t_node **n, int node);
t_queue				*queue_init(void);
t_path				*pop_front(t_queue **q);
t_path				*pop_path(t_path **path);
void				push_rear(t_queue **q, t_node **n);
t_node				*new_path(t_node **src);
void				del_cros_paths(t_path **p, int end);
void				only_one(t_path **p);
void				set_paths_len(t_path **paths);
t_path				*get_path(t_graph **g, t_lem **lem, int node);
void				add_path(t_node **paths, t_node **cur);
void				del_rest(t_path **p);

/*
**						USEFUL
*/

char				*get_room_name(char *line);
void				reverse_path(t_node **n);
void				show_usage();
int					lem_atoi(char *string);
int					try_execute(void);
int					is_room(char *line);

/*
**						DEL
*/

void				elem_del(t_elem **e);
void				del_queue(t_queue **q);
void				del_path(t_path **p);

#endif
