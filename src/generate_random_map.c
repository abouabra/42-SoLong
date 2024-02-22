/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_random_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:28:09 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:28:25 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	coin_counter(t_args *vars, char **map)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
			if (map[i][j] == 'C')
				counter++;
	}
	return (counter);
}

void	generated_map_valid_path(t_args *vars, char **map, int i, int j)
{
	if (map[i][j] == 'C' || map[i][j] == 'E')
		vars->vaid_path_counter++;
	if (vars->map_clone[i - 1][j] != '1')
	{
		vars->map_clone[i - 1][j] = '1';
		generated_map_valid_path(vars, map, i - 1, j);
	}
	if (vars->map_clone[i][j - 1] != '1')
	{
		vars->map_clone[i][j - 1] = '1';
		generated_map_valid_path(vars, map, i, j - 1);
	}
	if (vars->map_clone[i + 1][j] != '1')
	{
		vars->map_clone[i + 1][j] = '1';
		generated_map_valid_path(vars, map, i + 1, j);
	}
	if (vars->map_clone[i][j + 1] != '1')
	{
		vars->map_clone[i][j + 1] = '1';
		generated_map_valid_path(vars, map, i, j + 1);
	}
}

char	**generate_random_map(t_args *vars)
{
	int		i;
	char	**map;

	i = -1;
	map = ft_calloc(1, (vars->number_of_lines + 1) * sizeof(char *));
	while (++i < vars->number_of_lines)
		map[i] = ft_calloc(1, (vars->line_len + 1) * sizeof(char));
	initialize_map(vars, map);
	place_walls(vars, map);
	place_collectibles(vars, map);
	place_enemy(vars, map);
	place_extra_items(vars, map);
	place_exit(vars, map);
	place_player(vars, map);
	return (map);
}

char	**clone_generated_map(t_args *vars, char **map)
{
	char	**clone;
	int		i;

	i = -1;
	clone = ft_calloc(1, (vars->number_of_lines + 1) * sizeof(char *));
	if (!clone)
		return (0);
	while (++i < vars->number_of_lines)
		clone[i] = ft_strdup(map[i]);
	clone[i] = 0;
	return (clone);
}

char	**get_valid_map(t_args *vars)
{
	char	**map;

	while (1)
	{
		map = generate_random_map(vars);
		vars->map_clone = clone_generated_map(vars, map);
		vars->vaid_path_counter = 0;
		generated_map_valid_path(vars, map, vars->player_pos[Y],
			vars->player_pos[X]);
		free_map(vars, vars->map_clone);
		if (coin_counter(vars, map) + 1 == vars->vaid_path_counter)
			break ;
		free_map(vars, map);
	}
	return (map);
}
