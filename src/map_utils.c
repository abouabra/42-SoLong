/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:53:45 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:11:03 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_not_charset(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == c)
		i++;
	if (str[i] != c && str[i])
		return (1);
	return (0);
}

char	**clone_map(t_args *vars)
{
	char	**clone;
	int		i;

	i = -1;
	clone = ft_calloc(1, (vars->number_of_lines + 1) * sizeof(char *));
	if (!clone)
		return (0);
	while (++i < vars->number_of_lines)
		clone[i] = ft_strdup(vars->map[i]);
	clone[i] = 0;
	return (clone);
}

void	free_map(t_args *vars, char **map)
{
	int	i;

	i = -1;
	while (++i < vars->number_of_lines)
		free(map[i]);
	free(map);
}
