/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:37:57 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:06:43 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(t_args *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	system("killall afplay &> /dev/null");
	end_phase(vars);
	exit(0);
}

void	end_phase(t_args *vars)
{
	int	i;

	i = -1;
	while (++i < 12)
		free_map(vars, vars->map_cluster[i]);
	ft_enemy_clear(&vars->enemy_head[vars->map_index]);
	free(vars);
}
