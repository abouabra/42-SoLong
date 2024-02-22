/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet_linked_list_stuff.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:59:56 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 13:00:03 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_node(t_bullet **head, int id)
{
	t_bullet	*current;
	t_bullet	*prev;

	current = *head;
	prev = *head;
	if (current != NULL && current->id == id)
	{
		*head = current->next;
		free(current);
		current = NULL;
		return ;
	}
	while (current != NULL && current->id != id)
	{
		prev = current;
		current = current->next;
	}
	prev->next = current->next;
	free(current);
	current = NULL;
}

void	add_bullet_in_front(t_bullet **head, t_bullet *bullet)
{
	if (*head && bullet)
		bullet->next = *head;
	if (bullet)
		*head = bullet;
}

t_bullet	*ft_new_bullet(t_args *vars)
{
	t_bullet	*bullet;
	int			x;
	int			y;

	x = 0;
	y = 0;
	bullet = ft_calloc(1, sizeof(t_bullet));
	if (!bullet)
		return (0);
	bullet->id = vars->bullet_id;
	vars->bullet_id++;
	bullet->x = vars->player_pos[X] * SPRITE_X;
	bullet->y = vars->player_pos[Y] * SPRITE_Y;
	bullet->img = vars->bullet_img;
	bullet->prespective = vars->prespective;
	bullet->next = NULL;
	return (bullet);
}
