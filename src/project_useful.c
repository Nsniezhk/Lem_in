/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_useful.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:28:10 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/12/10 15:28:11 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "stdlib.h"

void			show_usage(void)
{
	ft_printf("\x1b[32m");
	ft_printf("___________________________________________________\n");
	ft_printf("|||||                 Lem_in                  |||||\n");
	ft_printf("|*************************************************|\n");
	ft_printf("|                    [USAGE]                      |\n");
	ft_printf("|                                                 |\n");
	ft_printf("| ./lem_in < [hive_file]                          |\n");
	ft_printf("| OR                                              |\n");
	ft_printf("| ./lem_in                                        |\n");
	ft_printf("|     //stdin                                     |\n");
	ft_printf("|                                                 |\n");
	ft_printf("|*************************************************|\n");
	ft_printf("|  AVAILABLE FLAGS:                               |\n");
	ft_printf("|  ,___________________________________________   |\n");
	ft_printf("|  | -i                                        |  |\n");
	ft_printf("|  | To display graph general info             |  |\n");
	ft_printf("|  | (Adjacency list, rooms, links, paths)     |  |\n");
	ft_printf("|  | -sp                                       |  |\n");
	ft_printf("|  | To set ants only on shortest path         |  |\n");
	ft_printf("|  | -lines                                    |  |\n");
	ft_printf("|  | To display amount of links on stdout      |  |\n");
	ft_printf("|  |___________________________________________|  |\n");
	ft_printf("|                                                 |\n");
	ft_printf("|*************************************************|\n");
	ft_printf("|___________________[nsniezhk]____________________|\n");
}

int				try_execute(void)
{
	ft_printf("Empty line in stdin!\n");
	ft_printf("\x1b[36m""[WARNING] ""\x1b[93m");
	ft_printf("Trying to execute with provided data!\n");
	return (2);
}

void			reverse_path(t_node **n)
{
	t_node	*prev;
	t_node	*cur;
	t_node	*next;

	prev = NULL;
	cur = *n;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*n = prev;
}

int				lem_atoi(char *string)
{
	unsigned int		number;
	int					sign;

	number = 0;
	sign = 1;
	while (*string == ' ' || *string == '\t'
			|| *string == '\v' || *string == '\f'
			|| *string == '\r' || *string == '\n')
		string++;
	if (*string == '-' || *string == '+')
		return (ant_error(-3));
	while (*string >= '0' && *string <= '9')
	{
		number = number * 10 + *string - '0';
		string++;
		if (number > MAX_INT)
			return (ant_error(-5));
	}
	return ((int)number);
}

int				get_flags(t_lem **l, int argc, char **argv)
{
	int	c;

	c = 0;
	while (++c < argc)
	{
		if (ft_strcmp(argv[c], "-i") == 0)
			(*l)->info += 1;
		else if (ft_strcmp(argv[c], "-sp") == 0)
			(*l)->one_way += 1;
		else if (ft_strcmp(argv[c], "-lines") == 0)
			(*l)->lines += 1;
		else if (ft_strcmp(argv[c], "-muse") == 0)
			(*l)->muse += 1;
		else
			return (0);
	}
	if ((*l)->info > 1 || (*l)->one_way > 1 || (*l)->muse > 1)
	{
		ft_printf("Dubble argument!\n");
		exit(0);
	}
	return (1);
}
