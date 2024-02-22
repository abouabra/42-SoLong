/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:48:06 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 13:00:44 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/so_long.h"

void	update_exit(t_args *vars)
{
	int	i;

	i = -1;
	if (vars->exit_status == 1 && vars->exit_tracker <= 4)
	{
		if (vars->exit_tracker == 0
			&& vars->clock_timer % EXIT_ANIMATION_TIMER == 0)
			run_door_audio();
		if (vars->clock_timer % EXIT_ANIMATION_TIMER == 0)
		{
			vars->default_exit_img = vars->exit_imgs[vars->exit_tracker];
			vars->exit_tracker++;
		}
	}
}

void	update_coins(t_args *vars)
{
	if (vars->clock_timer % COIN_ANIMATION_TIMER == 0)
	{
		if (vars->coin_imgs_counter > 7)
			vars->coin_imgs_counter = 0;
		vars->default_coin_img = vars->coin_imgs[vars->coin_imgs_counter];
		vars->coin_imgs_counter++;
	}
}

void	bonus_animation(t_args *vars)
{
	if (vars->shoot == 1)
	{
		shoot(vars->clock_timer, vars);
		clear_bullets(vars);
	}
	if (vars->clock_timer % ENEMY_MOVEMENT_TIMER == 0)
		move_enemy(vars);
	print_enemy_sprites(vars);
	print_enemy_hp(vars);
	handle_game_menu(vars);
	update_coins(vars);
	update_exit(vars);
}
