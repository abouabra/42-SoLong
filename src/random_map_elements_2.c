/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_map_elements_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:14:14 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:03:07 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_exit(t_args *vars, char **map)
{
	int			row;
	int			col;

	row = rand() % (vars->number_of_lines - 2) + 1;
	col = rand() % (vars->line_len - 2) + 1;
	while (map[row][col] != '0')
	{
		row = rand() % (vars->number_of_lines - 2) + 1;
		col = rand() % (vars->line_len - 2) + 1;
	}
	map[row][col] = 'E';
}

void	place_player(t_args *vars, char **map)
{
	int			row;
	int			col;

	row = rand() % (vars->number_of_lines - 2) + 1;
	col = rand() % (vars->line_len - 2) + 1;
	while (map[row][col] != '0')
	{
		row = rand() % (vars->number_of_lines - 2) + 1;
		col = rand() % (vars->line_len - 2) + 1;
	}
	map[row][col] = 'P';
	vars->player_pos[X] = col;
	vars->player_pos[Y] = row;
}

void	place_extra_items_2(t_args *vars, char **map)
{
	int	row;
	int	col;
	int	num_items;

	num_items = vars->number_of_lines / 2;
	while (num_items > 0)
	{
		row = rand() % (vars->number_of_lines - 2) + 1;
		col = rand() % (vars->line_len - 2) + 1;
		if (map[row][col] == '0')
		{
			map[row][col] = 'Y';
			num_items--;
		}
	}
	place_extra_items_3(vars, map);
}

void	place_extra_items_3(t_args *vars, char **map)
{
	int	row;
	int	col;
	int	num_items;

	num_items = vars->number_of_lines / 4;
	while (num_items > 0)
	{
		row = rand() % (vars->number_of_lines - 2) + 1;
		col = rand() % (vars->line_len - 2) + 1;
		if (map[row][col] == '0')
		{
			map[row][col] = 'Z';
			num_items--;
		}
	}
}

void	place_walls_2(t_args *vars, char **map)
{
	int	row;
	int	col;
	int	num_walls;

	num_walls = ((vars->number_of_lines - 2) * (vars->line_len - 2)) / 4;
	while (num_walls > 0)
	{
		row = rand() % (vars->number_of_lines - 2) + 1;
		col = rand() % (vars->line_len - 2) + 1;
		if (map[row][col] == '0')
		{
			map[row][col] = '1';
			num_walls--;
		}
	}
}
