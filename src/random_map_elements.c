/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_map_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:14:14 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:11:46 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_map(t_args *vars, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
			map[i][j] = '0';
	}
}

void	place_walls(t_args *vars, char **map)
{
	int	num_walls;
	int	i;
	int	j;

	num_walls = ((vars->number_of_lines - 2) * (vars->line_len - 2)) / 4;
	i = -1;
	while (++i < vars->number_of_lines)
	{
		map[i][0] = '1';
		map[i][vars->line_len - 1] = '1';
	}
	j = -1;
	while (++j < vars->line_len)
	{
		map[0][j] = '1';
		map[vars->number_of_lines - 1][j] = '1';
	}
	place_walls_2(vars, map);
}

void	place_collectibles(t_args *vars, char **map)
{
	int	num_collectibles;
	int	row;
	int	col;

	num_collectibles = rand() % 8 + 3;
	while (num_collectibles > 0)
	{
		row = rand() % (vars->number_of_lines - 2) + 1;
		col = rand() % (vars->line_len - 2) + 1;
		if (map[row][col] == '0')
		{
			map[row][col] = 'C';
			num_collectibles--;
		}
	}
}

void	place_enemy(t_args *vars, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
		{
			if (map[i][j] == 'C')
			{
				if (map[i - 1][j] == '0')
					map[i - 1][j] = 'O';
				else if (map[i + 1][j] == '0')
					map[i + 1][j] = 'O';
				else if (map[i][j - 1] == '0')
					map[i][j - 1] = 'O';
				else if (map[i][j + 1] == '0')
					map[i][j + 1] = 'O';
			}
		}
	}
}

void	place_extra_items(t_args *vars, char **map)
{
	int	num_items;
	int	row;
	int	col;

	num_items = vars->number_of_lines / 1;
	while (num_items > 0)
	{
		row = rand() % (vars->number_of_lines - 2) + 1;
		col = rand() % (vars->line_len - 2) + 1;
		if (map[row][col] == '0')
		{
			map[row][col] = 'X';
			num_items--;
		}
	}
	place_extra_items_2(vars, map);
}
