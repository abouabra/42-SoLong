/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:58:49 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:15:15 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_phase_1(char *map_name)
{
	char	*extention;

	extention = ft_strchr(map_name, '.');
	if (!extention)
		return (0);
	if (ft_strncmp(extention, ".ber", -1))
	{
		ft_dprintf(1, "Error\nMap does not have .ber extention\n");
		return (0);
	}
	return (1);
}

int	map_phase_2(t_args *vars, int *exit_count, int *coin_count,
		int *player_count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (!ft_strchr("01CEP", vars->map[i][j]))
			{
				ft_dprintf(1, "Error\nMap Contains Other Characters\n");
				return (0);
			}
			if (vars->map[i][j] == 'E')
				(*exit_count)++;
			if (vars->map[i][j] == 'C')
				(*coin_count)++;
			if (vars->map[i][j] == 'P')
				(*player_count)++;
		}
	}
	return (1);
}

int	map_phase_3(t_args *vars, int exit_count, int coin_count, int player_count)
{
	if (!exit_count || !coin_count || !player_count || exit_count > 1
		|| player_count > 1)
	{
		ft_dprintf(1, "Error\nDouble or Missing characters\n");
		return (0);
	}
	vars->coin_counter = coin_count;
	return (1);
}

int	map_phase_4(t_args *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (((i == 0 || i == vars->number_of_lines - 1)
					&& is_not_charset(vars->map[i], '1'))
				|| ((j == 0 || j == ft_strlen(vars->map[i]) - 1)
					&& ft_strncmp(&vars->map[i][j], "1", 1)))
			{
				ft_dprintf(1, "Error\nMap is not surrounded by walls");
				return (0);
			}
		}
	}
	return (1);
}

int	map_operation(t_args *vars, char *map_name)
{
	int	exit_count;
	int	coin_count;
	int	player_count;

	exit_count = 0;
	coin_count = 0;
	player_count = 0;
	if (!map_phase_1(map_name)
		|| !map_phase_2(vars, &exit_count, &coin_count, &player_count)
		|| !map_phase_3(vars, exit_count, coin_count, player_count)
		|| !map_phase_4(vars) || !map_phase_5(vars) || !map_phase_6(vars))
		return (0);
	return (1);
}
