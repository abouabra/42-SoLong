/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:23:21 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:04:43 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player_up(t_args *vars)
{
	if (vars->map[vars->player_pos[Y] - 1][vars->player_pos[X]] != '1')
	{
		vars->movement_counter++;
		vars->player_pos[Y]--;
	}
}

void	move_player_down(t_args *vars)
{
	if (vars->map[vars->player_pos[Y] + 1][vars->player_pos[X]] != '1')
	{
		vars->movement_counter++;
		vars->player_pos[Y]++;
	}
}

void	move_player_left(t_args *vars)
{
	if (vars->map[vars->player_pos[Y]][vars->player_pos[X] - 1] != '1')
	{
		vars->movement_counter++;
		vars->player_pos[X]--;
	}
}

void	move_player_right(t_args *vars)
{
	if (vars->map[vars->player_pos[Y]][vars->player_pos[X] + 1] != '1')
	{
		vars->movement_counter++;
		vars->player_pos[X]++;
	}
}
