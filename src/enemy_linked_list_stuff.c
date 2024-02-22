/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_linked_list_stuff.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:25:11 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:59:21 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemy	*ft_new_enemy(t_args *vars, int i, int j)
{
	t_enemy	*enemy;
	int		x;
	int		y;

	x = 0;
	y = 0;
	enemy = ft_calloc(1, sizeof(t_enemy));
	if (!enemy)
		return (0);
	enemy->id = vars->enemy_id;
	vars->enemy_id++;
	enemy->y = i;
	enemy->x = j;
	enemy->prespective = UP;
	enemy->health = ENEMY_HEALTH;
	enemy->next = NULL;
	return (enemy);
}

t_enemy	*ft_last_enemy(t_enemy *enemy)
{
	if (enemy)
	{
		while (enemy->next != NULL)
			enemy = enemy->next;
	}
	return (enemy);
}

void	add_enemy_in_back(t_enemy **head, t_enemy *enemy)
{
	t_enemy	*tmp;

	if (*head)
	{
		tmp = ft_last_enemy(*head);
		tmp->next = enemy;
	}
	else
		*head = enemy;
}

void	ft_enemy_clear(t_enemy **head)
{
	t_enemy	*tmp;

	if (head != NULL)
	{
		while (*head != NULL)
		{
			tmp = (*head)->next;
			free(*head);
			*head = tmp;
		}
		*head = NULL;
	}
}

t_enemy	*get_enemy_node(t_args *vars, int x, int y)
{
	t_enemy	*enemy;
	int		x_calc;
	int		y_calc;

	enemy = vars->enemy_head[vars->map_index];
	while (enemy)
	{
		x_calc = x - enemy->x * SPRITE_X;
		y_calc = y - enemy->y * SPRITE_Y;
		if (x_calc + SPRITE_X > 0 && x_calc < 64 && y_calc + SPRITE_Y > 0
			&& y_calc < 64)
		{
			return (enemy);
		}
		enemy = enemy->next;
	}
	return (NULL);
}
