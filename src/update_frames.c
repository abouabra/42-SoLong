/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:36:25 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/03 19:43:32 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_before_print_3(t_args *vars)
{
	if (vars->map[vars->player_pos[Y]][vars->player_pos[X]] == 'E' &&
				vars->exit_status)
	{
		if (vars->map_index < Level_12)
		{
			vars->map = vars->map_cluster[vars->map_index + 1];
			vars->map_index = vars->map_index + 1;
			vars->exit_tracker = 0;
			vars->exit_status = 0;
			vars->default_exit_img = vars->exit_imgs[Exit_0];
			mlx_destroy_window(vars->mlx, vars->win);
			run_game_page(vars);
		}
		else
		{
			ft_dprintf(1, "YOU FINISHED THE GAME\n");
			close_win(vars);
		}
	}
}

void	check_before_print_2(t_args *vars)
{
	int		i;
	int		j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
		{
			if (vars->map[vars->player_pos[Y]][vars->player_pos[X]] == 'C')
			{
				vars->map[vars->player_pos[Y]][vars->player_pos[X]] = '0';
				vars->coin_counter--;
				vars->bullet_counter += BULLET_MAGAZINE_SIZE;
			}
			if (vars->map[vars->player_pos[Y]][vars->player_pos[X]] == 'O')
			{
				ft_dprintf(1, "YOU HAVE BEEN KILLED BY AN ENEMY\n");
				close_win(vars);
			}
			if (!vars->coin_counter)
				vars->exit_status = 1;
			check_before_print_3(vars);
		}
	}
}

void	check_before_print(t_args *vars)
{
	t_enemy	*enemy;

	check_before_print_2(vars);
	enemy = vars->enemy_head[vars->map_index];
	while (enemy)
	{
		if (enemy->health == 0)
		{
			run_kill_enemy_audio();
			vars->score_counter += 100;
			delete_enemy_node(vars, &vars->enemy_head[vars->map_index],
				enemy->id);
		}
		enemy = enemy->next;
	}
}

int	update_frames(t_args *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	check_before_print(vars);
	set_player_assets(vars);
	print_map(vars);
	if (BONUS == 1)
		bonus_animation(vars);
	vars->clock_timer++;
	return (0);
}
