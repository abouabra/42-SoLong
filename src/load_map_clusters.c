/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_clusters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:03:32 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:16:23 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_map_clusers(t_args *vars)
{
	int	i;

	vars->map_cluster[0] = vars->map;
	i = 0;
	while (++i < 12)
		vars->map_cluster[i] = get_valid_map(vars);
}
