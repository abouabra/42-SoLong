/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:34:23 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 14:33:58 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_in_range_4(t_args *vars, int i, int j)
{
	if (vars->x_calc + SPRITE_X > 0 && vars->x_calc < 64 && vars->y_calc
		+ SPRITE_Y > 0 && vars->y_calc < 64)
	{
		if (vars->map[i][j] == 'X')
		{
			vars->map[i][j] = '0';
			run_exploation_audio();
			hurt_enemy(vars, 'X', i, j);
		}
		if (vars->map[i][j] == 'Y')
		{
			vars->map[i][j] = '0';
			run_exploation_audio();
			hurt_enemy(vars, 'Y', i, j);
		}
		if (vars->map[i][j] == 'Z')
		{
			ft_dprintf(1, "YOU DIED TO NUCLEAR BOMB\n");
			vars->map[i][j] = '0';
			run_exploation_audio();
			close_win(vars);
		}
		return (1);
	}
	return (0);
}

int	is_in_range(t_args *vars, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
		{
			if (vars->map[i][j] == 'X' || vars->map[i][j] == 'Y'
				|| vars->map[i][j] == 'Z')
			{
				vars->x_calc = x - j * SPRITE_X;
				vars->y_calc = y - i * SPRITE_Y;
				is_in_range_4(vars, i, j);
			}
		}
	}
	if (is_in_range_2(vars, x, y))
		return (1);
	return (0);
}

int	detect_coalition(t_args *vars, t_bullet *bullet)
{
	if (bullet->x < 0 || bullet->y < 0 || bullet->x > vars->screen_x
		|| bullet->y > vars->screen_y)
		return (1);
	if (is_in_range(vars, bullet->x, bullet->y))
		return (1);
	return (0);
}

void	clear_bullets(t_args *vars)
{
	t_bullet	*bullet;

	bullet = vars->bullet_head;
	while (bullet)
	{
		if (detect_coalition(vars, bullet))
			delete_node(&vars->bullet_head, bullet->id);
		bullet = bullet->next;
	}
}

void	shoot(int clock_timer, t_args *vars)
{
	t_bullet	*bullet;

	bullet = vars->bullet_head;
	while (bullet)
	{
		if (clock_timer % 1 == 0)
		{
			if (bullet->prespective == UP)
				bullet->y -= BULLET_MOVEMENT_TIMER;
			if (bullet->prespective == DOWN)
				bullet->y += BULLET_MOVEMENT_TIMER;
			if (bullet->prespective == LEFT)
				bullet->x -= BULLET_MOVEMENT_TIMER;
			if (bullet->prespective == RIGHT)
				bullet->x += BULLET_MOVEMENT_TIMER;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bullet_img,
				bullet->x, bullet->y);
		}
		bullet = bullet->next;
	}
}
