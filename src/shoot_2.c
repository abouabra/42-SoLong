/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:34:23 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 14:34:45 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_in_range_3_follow_up(t_args *vars, int x, int y)
{
	t_enemy	*enemy;

	if (vars->x_calc + SPRITE_X > 0 && vars->x_calc < 64 && vars->y_calc
		+ SPRITE_Y > 0 && vars->y_calc < 64)
	{
		enemy = get_enemy_node(vars, x, y);
		enemy->health--;
		if (enemy->health == 0)
		{
			run_kill_enemy_audio();
			vars->score_counter += 100;
			delete_enemy_node(vars,
				&vars->enemy_head[vars->map_index], enemy->id);
		}
		return (1);
	}
	return (0);
}

int	is_in_range_3(t_args *vars, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
		{
			if (vars->map[i][j] == 'O')
			{
				vars->x_calc = x - j * SPRITE_X;
				vars->y_calc = y - i * SPRITE_Y;
				if (is_in_range_3_follow_up(vars, x, y))
					return (1);
			}
		}
	}
	return (0);
}

int	is_in_range_2(t_args *vars, int x, int y)
{
	int		x_calc;
	int		y_calc;
	int		i;
	int		j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
		{
			if (vars->map[i][j] == '1' || vars->map[i][j] == 'E')
			{
				x_calc = x - j * SPRITE_X;
				y_calc = y - i * SPRITE_Y;
				if (x_calc + SPRITE_X > 0 && x_calc < 64 && y_calc
					+ SPRITE_Y > 0 && y_calc < 64)
					return (1);
			}
		}
	}
	if (is_in_range_3(vars, x, y))
		return (1);
	return (0);
}
