/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_linked_list_stuff_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:25:11 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:59:01 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_enemy_node(t_args *vars, t_enemy **head, int id)
{
	t_enemy	*current;
	t_enemy	*prev;

	current = *head;
	prev = *head;
	if (current != NULL && current->id == id)
	{
		*head = current->next;
		vars->map[current->y][current->x] = '0';
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
	vars->map[current->y][current->x] = '0';
	free(current);
	current = NULL;
}
