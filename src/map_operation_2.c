/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operation_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:26:05 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:15:39 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_phase_5(t_args *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		if (ft_strlen(vars->map[i]) != ft_strlen(vars->map[i + 1])
			&& vars->map[i + 1])
		{
			ft_dprintf(1, "Error\nMap is not Rectangular\n");
			return (0);
		}
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'P')
			{
				vars->player_pos[X] = j;
				vars->player_pos[Y] = i;
			}
		}
	}
	return (1);
}

void	valid_path(t_args *vars, char **map, int i, int j)
{
	if (vars->map[i][j] == 'C' || vars->map[i][j] == 'E')
		vars->vaid_path_counter++;
	if (map[i - 1][j] != '1')
	{
		map[i - 1][j] = '1';
		valid_path(vars, map, i - 1, j);
	}
	if (map[i][j - 1] != '1')
	{
		map[i][j - 1] = '1';
		valid_path(vars, map, i, j - 1);
	}
	if (map[i + 1][j] != '1')
	{
		map[i + 1][j] = '1';
		valid_path(vars, map, i + 1, j);
	}
	if (map[i][j + 1] != '1')
	{
		map[i][j + 1] = '1';
		valid_path(vars, map, i, j + 1);
	}
}

int	map_phase_6(t_args *vars)
{
	char	**cloned_map;

	cloned_map = clone_map(vars);
	vars->line_len = ft_strlen(vars->map[0]);
	valid_path(vars, cloned_map, vars->player_pos[Y], vars->player_pos[X]);
	if (vars->coin_counter + 1 != vars->vaid_path_counter)
	{
		ft_dprintf(1, "Error\nINVALID PATH\n");
		return (0);
	}
	free_map(vars, cloned_map);
	return (1);
}
