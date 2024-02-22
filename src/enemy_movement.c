/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:25:11 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:49:15 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemy_up(t_args *vars, t_enemy *enemy)
{
	if (!ft_strchr("1XYZCOE", vars->map[enemy->y - 1][enemy->x]))
	{
		vars->map[enemy->y][enemy->x] = '0';
		enemy->y -= 1;
		vars->map[enemy->y][enemy->x] = 'O';
		enemy->prespective = UP;
	}
}

void	move_enemy_down(t_args *vars, t_enemy *enemy)
{
	if (!ft_strchr("1XYZCOE", vars->map[enemy->y + 1][enemy->x]))
	{
		vars->map[enemy->y][enemy->x] = '0';
		enemy->y += 1;
		vars->map[enemy->y][enemy->x] = 'O';
		enemy->prespective = DOWN;
	}
}

void	move_enemy_left(t_args *vars, t_enemy *enemy)
{
	if (!ft_strchr("1XYZCOE", vars->map[enemy->y][enemy->x - 1]))
	{
		vars->map[enemy->y][enemy->x] = '0';
		enemy->x -= 1;
		vars->map[enemy->y][enemy->x] = 'O';
		enemy->prespective = LEFT;
	}
}

void	move_enemy_right(t_args *vars, t_enemy *enemy)
{
	if (!ft_strchr("1XYZCOE", vars->map[enemy->y][enemy->x + 1]))
	{
		vars->map[enemy->y][enemy->x] = '0';
		enemy->x += 1;
		vars->map[enemy->y][enemy->x] = 'O';
		enemy->prespective = RIGHT;
	}
}

void	print_enemy_sprites(t_args *vars)
{
	t_enemy	*enemy;
	void	*default_zombie_img;

	enemy = vars->enemy_head[vars->map_index];
	while (enemy)
	{
		if (enemy->prespective == UP)
			default_zombie_img = vars->zombie_imgs[UP];
		if (enemy->prespective == DOWN)
			default_zombie_img = vars->zombie_imgs[DOWN];
		if (enemy->prespective == LEFT)
			default_zombie_img = vars->zombie_imgs[LEFT];
		if (enemy->prespective == RIGHT)
			default_zombie_img = vars->zombie_imgs[RIGHT];
		mlx_put_image_to_window(vars->mlx, vars->win, default_zombie_img,
			enemy->x * SPRITE_X, enemy->y * SPRITE_Y);
		enemy = enemy->next;
	}
}
