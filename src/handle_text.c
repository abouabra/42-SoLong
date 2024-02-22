/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:49:42 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:25:10 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_game_menu_2(t_args *vars, char *level_counter)
{
	char	*bullet_final;
	char	*bullet_counter;
	char	*level_final;
	char	*score_final;
	char	*score_counter;

	level_final = ft_strjoin("LEVEL: ", level_counter);
	bullet_counter = ft_itoa(vars->bullet_counter);
	bullet_final = ft_strjoin("BULLETS: ", bullet_counter);
	free(bullet_counter);
	score_counter = ft_itoa(vars->score_counter);
	score_final = ft_strjoin("SCORE: ", score_counter);
	free(score_counter);
	mlx_string_put(vars->mlx, vars->win, 64, vars->screen_y + 20, 0xffffff,
		level_final);
	mlx_string_put(vars->mlx, vars->win, 750, vars->screen_y + 20, 0xffffff,
		bullet_final);
	mlx_string_put(vars->mlx, vars->win, 594, vars->screen_y + 20, 0xffffff,
		score_final);
	free(bullet_final);
	free(level_final);
	free(score_final);
}

void	handle_game_menu(t_args *vars)
{
	char	*coin_final;
	char	*coin_counter;
	char	*movement_final;
	char	*movement_counter;
	char	*level_counter;

	level_counter = ft_itoa(vars->map_index + 1);
	coin_counter = ft_itoa(vars->coin_counter);
	coin_final = ft_strjoin("MAGAZINES LEFT: ", coin_counter);
	free(coin_counter);
	movement_counter = ft_itoa(vars->movement_counter);
	movement_final = ft_strjoin("MOVEMENTS: ", movement_counter);
	free(movement_counter);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->padding_menu_img, 0,
		vars->screen_y);
	mlx_string_put(vars->mlx, vars->win, 194, vars->screen_y + 20, 0xffffff,
		coin_final);
	mlx_string_put(vars->mlx, vars->win, 412, vars->screen_y + 20, 0xffffff,
		movement_final);
	free(coin_final);
	free(movement_final);
	handle_game_menu_2(vars, level_counter);
	free(level_counter);
}
