/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:28:41 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:15:48 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map(t_args *vars, char *map_name)
{
	int		fd;
	char	*tmp;
	char	*str;
	char	**final;

	str = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		(vars->number_of_lines)++;
		str = ft_strjoin_gnl(str, tmp);
		free(tmp);
	}
	final = ft_split(str, '\n');
	free(str);
	return (final);
}

int	map_check(t_args *vars, char *map_name)
{
	vars->map = get_map(vars, map_name);
	if (!vars->map)
		return (0);
	if (!map_operation(vars, map_name))
		return (0);
	place_enemy(vars, vars->map);
	place_extra_items(vars, vars->map);
	return (1);
}
