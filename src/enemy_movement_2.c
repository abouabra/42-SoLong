/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:25:11 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:49:29 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_enemy_hp(t_args *vars)
{
	t_enemy	*enemy;

	enemy = vars->enemy_head[vars->map_index];
	while (enemy)
	{
		if (enemy->health == 3)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->health_bar_imgs[heath_100], enemy->x * SPRITE_X,
				enemy->y * SPRITE_Y);
		if (enemy->health == 2)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->health_bar_imgs[heath_66], enemy->x * SPRITE_X,
				enemy->y * SPRITE_Y);
		if (enemy->health == 1)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->health_bar_imgs[heath_33], enemy->x * SPRITE_X,
				enemy->y * SPRITE_Y);
		enemy = enemy->next;
	}
}
