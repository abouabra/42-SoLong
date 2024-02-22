/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_music.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:18:07 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/03 17:48:00 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	play_backgroud_music(void)
{
	int	id;

	id = fork();
	if (id == -1)
		return ;
	if (id == 0)
	{
		system("afplay textures/mp3/Background_music.mp3");
		exit(0);
	}
}

void	run_door_audio(void)
{
	int	id;

	id = fork();
	if (id == -1)
		return ;
	if (id == 0)
	{
		system("afplay textures/mp3/Door_0.mp3");
		exit(0);
	}
}

void	run_kill_enemy_audio(void)
{
	int	id;

	id = fork();
	if (id == -1)
		return ;
	if (id == 0)
	{
		system("afplay textures/mp3/enemy_death_sound.mp3");
		exit(0);
	}
}

void	run_shoot_bullet_audio(void)
{
	int	id;

	id = fork();
	if (id == -1)
		return ;
	if (id == 0)
	{
		system("afplay textures/mp3/Bullet_0.mp3");
		exit(0);
	}
}

void	run_exploation_audio(void)
{
	int	id;

	id = fork();
	if (id == -1)
		return ;
	if (id == 0)
	{
		system("afplay textures/mp3/Explosion_0.mp3");
		exit(0);
	}
}
