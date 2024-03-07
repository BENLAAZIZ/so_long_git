/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:08:18 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/07 19:38:07 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_p_up(t_data *data)
{
	int		x;
	int		y;
	char	**split_tmp;

	x = data->x_p;
	y = data->y_p;
	split_tmp = data->split;
	split_tmp[data->x_p - 1][data->y_p] = 'P';
	split_tmp[x][y] = '0';
}