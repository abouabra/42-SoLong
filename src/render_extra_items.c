/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_extra_items.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:00:40 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 11:13:34 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_extra_items(t_args *vars, int i, int j, char c)
{
	if (c == 'X')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Background], j
			* SPRITE_X, i * SPRITE_Y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Extra_bg_2], j
			* SPRITE_X, i * SPRITE_Y);
	}
	if (c == 'Y')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Background], j
			* SPRITE_X, i * SPRITE_Y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Extra_bg_1], j
			* SPRITE_X, i * SPRITE_Y);
	}
	if (c == 'Z')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Background], j
			* SPRITE_X, i * SPRITE_Y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Extra_bg_0], j
			* SPRITE_X, i * SPRITE_Y);
	}
}
