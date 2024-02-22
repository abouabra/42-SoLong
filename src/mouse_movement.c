/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:35:23 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:05:06 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_mouse_data(int x, int y, t_args *vars)
{
	vars->mouse_x = x;
	vars->mouse_y = y;
	return (0);
}

int	mouse_click(int button, int x, int y, t_args *vars)
{
	t_bullet	*bullet;

	if (button == 1 && x > 0 && y > 0 && vars->bullet_counter > 0)
	{
		vars->shoot = 1;
		bullet = ft_new_bullet(vars);
		if (!bullet)
			return (0);
		add_bullet_in_front(&vars->bullet_head, bullet);
		run_shoot_bullet_audio();
		shoot(vars->clock_timer, vars);
		vars->bullet_counter--;
	}
	return (0);
}
