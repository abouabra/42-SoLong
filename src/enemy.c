/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:25:11 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:29:11 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_enemy_pos(t_args *vars)
{
	int		i;
	int		j;
	t_enemy	*enemy;
	int		map_index;

	map_index = vars->map_index - 1;
	if (map_index >= 0)
		ft_enemy_clear(&vars->enemy_head[map_index]);
	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
		{
			if (vars->map[i][j] == 'O')
			{
				enemy = ft_new_enemy(vars, i, j);
				add_enemy_in_back(&vars->enemy_head[vars->map_index], enemy);
			}
		}
	}
}

void	move_enemy(t_args *vars)
{
	int		choice;
	t_enemy	*enemy;

	enemy = vars->enemy_head[vars->map_index];
	while (enemy)
	{
		choice = rand() % 4;
		if (choice == 0)
			move_enemy_up(vars, enemy);
		if (choice == 1)
			move_enemy_down(vars, enemy);
		if (choice == 2)
			move_enemy_left(vars, enemy);
		if (choice == 3)
			move_enemy_right(vars, enemy);
		enemy = enemy->next;
	}
}

void	hurt_enemy(t_args *vars, char c, int i, int j)
{
	t_enemy	*enemy;

	enemy = vars->enemy_head[vars->map_index];
	while (enemy != NULL)
	{
		if ((j - 1 == enemy->x || j + 1 == enemy->x || j == enemy->x)
			&& (i == enemy->y || i - 1 == enemy->y || i + 1 == enemy->y))
		{
			if (c == 'X')
				enemy->health--;
			if (c == 'Y')
				enemy->health = 0;
		}
		enemy = enemy->next;
	}
}
