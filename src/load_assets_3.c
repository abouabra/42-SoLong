/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:59:10 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 13:13:06 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_assets(t_args *vars)
{
	load_game_assets(vars);
	get_coin_assets(vars);
	get_all_player_assets(vars);
	set_player_assets(vars);
	get_zombie_assets(vars);
	get_exit_assets(vars);
	vars->prespective = RIGHT;
	vars->default_player_img = vars->player_imgs[RIGHT];
	vars->default_coin_img = vars->coin_imgs[Collectibale_0];
	vars->default_exit_img = vars->exit_imgs[Exit_0];
}
