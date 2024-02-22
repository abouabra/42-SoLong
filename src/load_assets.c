/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:59:10 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 13:13:18 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_coin_assets(t_args *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	vars->coin_imgs[Collectibale_0] = mlx_xpm_file_to_image(
			vars->mlx, "textures/coins/coins_0.xpm", &x, &y);
	vars->coin_imgs[Collectibale_1] = mlx_xpm_file_to_image(
			vars->mlx, "textures/coins/coins_1.xpm", &x, &y);
	vars->coin_imgs[Collectibale_2] = mlx_xpm_file_to_image(
			vars->mlx, "textures/coins/coins_2.xpm", &x, &y);
	vars->coin_imgs[Collectibale_3] = mlx_xpm_file_to_image(
			vars->mlx, "textures/coins/coins_3.xpm", &x, &y);
	vars->coin_imgs[Collectibale_4] = mlx_xpm_file_to_image(
			vars->mlx, "textures/coins/coins_4.xpm", &x, &y);
	vars->coin_imgs[Collectibale_5] = mlx_xpm_file_to_image(
			vars->mlx, "textures/coins/coins_5.xpm", &x, &y);
	vars->coin_imgs[Collectibale_6] = mlx_xpm_file_to_image(
			vars->mlx, "textures/coins/coins_6.xpm", &x, &y);
	vars->coin_imgs[Collectibale_7] = mlx_xpm_file_to_image(
			vars->mlx, "textures/coins/coins_7.xpm", &x, &y);
}

void	get_exit_assets(t_args *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	vars->exit_imgs[Exit_0] = mlx_xpm_file_to_image(
			vars->mlx, "textures/exit/Door_0.xpm", &x, &y);
	vars->exit_imgs[Exit_1] = mlx_xpm_file_to_image(
			vars->mlx, "textures/exit/Door_1.xpm", &x, &y);
	vars->exit_imgs[Exit_2] = mlx_xpm_file_to_image(
			vars->mlx, "textures/exit/Door_2.xpm", &x, &y);
	vars->exit_imgs[Exit_3] = mlx_xpm_file_to_image(
			vars->mlx, "textures/exit/Door_3.xpm", &x, &y);
	vars->exit_imgs[Exit_4] = mlx_xpm_file_to_image(
			vars->mlx, "textures/exit/Door_4.xpm", &x, &y);
}

void	set_player_assets(t_args *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	vars->player_imgs[UP] = vars->all_player_imgs[vars->skin_chooser][UP];
	vars->player_imgs[DOWN] = vars->all_player_imgs[vars->skin_chooser][DOWN];
	vars->player_imgs[LEFT] = vars->all_player_imgs[vars->skin_chooser][LEFT];
	vars->player_imgs[RIGHT] = vars->all_player_imgs[vars->skin_chooser][RIGHT];
}

void	get_zombie_assets(t_args *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	vars->zombie_imgs[UP] = mlx_xpm_file_to_image(
			vars->mlx, "textures/zombie/Zombie_up.xpm", &x, &y);
	vars->zombie_imgs[DOWN] = mlx_xpm_file_to_image(
			vars->mlx, "textures/zombie/Zombie_down.xpm", &x, &y);
	vars->zombie_imgs[LEFT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/zombie/Zombie_left.xpm", &x, &y);
	vars->zombie_imgs[RIGHT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/zombie/Zombie_right.xpm", &x, &y);
	vars->health_bar_imgs[heath_33] = mlx_xpm_file_to_image(
			vars->mlx, "textures/health/health_33.xpm", &x, &y);
	vars->health_bar_imgs[heath_66] = mlx_xpm_file_to_image(
			vars->mlx, "textures/health/health_66.xpm", &x, &y);
	vars->health_bar_imgs[heath_100] = mlx_xpm_file_to_image(
			vars->mlx, "textures/health/health_100.xpm", &x, &y);
}

void	load_game_assets(t_args *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->imgs[Background] = mlx_xpm_file_to_image(
			vars->mlx, "textures/Extra/Background.xpm", &j, &i);
	vars->imgs[Wall] = mlx_xpm_file_to_image(
			vars->mlx, "textures/Extra/Wall.xpm", &j, &i);
	vars->imgs[Extra_bg_0] = mlx_xpm_file_to_image(
			vars->mlx, "textures/Extra/Extra_bg_0.xpm", &j, &i);
	vars->imgs[Extra_bg_1] = mlx_xpm_file_to_image(
			vars->mlx, "textures/Extra/Extra_bg_1.xpm", &j, &i);
	vars->imgs[Extra_bg_2] = mlx_xpm_file_to_image(
			vars->mlx, "textures/Extra/Extra_bg_2.xpm", &j, &i);
	vars->bullet_img = mlx_xpm_file_to_image(
			vars->mlx, "textures/Extra/Bullet.xpm", &j, &i);
	vars->padding_menu_img = mlx_xpm_file_to_image(
			vars->mlx, "textures/Extra/padding_menu.xpm", &j, &i);
}
