/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_level_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:08:09 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 11:11:40 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	select_level_mouse_click_5(int button, int x, int y, t_args *vars)
{
	if (button == 1 && x > 147 && x < 1353 && y > 848 && y < 926)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		run_game_type_page(vars);
	}
	if (button == 1 && x > 147 && x < 447 && y > 73 && y < 151)
	{
		vars->map = vars->map_cluster[Level_1];
		vars->map_index = Level_1;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
}
