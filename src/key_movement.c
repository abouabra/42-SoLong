/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:31:17 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:18:09 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enable_cheats(t_args *vars)
{
	vars->coin_counter = 0;
	vars->exit_status = 1;
}

void	key_movement_2(int keycode, t_args *vars)
{
	if (keycode == 0)
	{
		vars->default_player_img = vars->player_imgs[LEFT];
		vars->prespective = LEFT;
		move_player_left(vars);
	}
	if (keycode == 2)
	{
		vars->default_player_img = vars->player_imgs[RIGHT];
		vars->prespective = RIGHT;
		move_player_right(vars);
	}
	if (keycode == 53)
		close_win(vars);
}

int	key_movement(int keycode, t_args *vars)
{
	if (keycode == 13)
	{
		vars->default_player_img = vars->player_imgs[UP];
		vars->prespective = UP;
		move_player_up(vars);
	}
	if (keycode == 1)
	{
		vars->default_player_img = vars->player_imgs[DOWN];
		vars->prespective = DOWN;
		move_player_down(vars);
	}
	key_movement_2(keycode, vars);
	return (0);
}
