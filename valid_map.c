/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:19:00 by hben-laz          #+#    #+#             */
/*   Updated: 2024/02/28 21:48:04 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handel_border( char **split,int whidth, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
		//first line and last line
	while (x < whidth)
	{
		if (split[0][x] != '1' || split[height - 1][x] != '1')
			return (1);
		x++;
	}
	//first column and last column
	y = 0;
	while (y < height && split[y] != NULL)
	{
		if (split[y][0] != '1' || split[y][whidth - 1] != '1')
			return (1);
		if (ft_strlen(split[y]) != (size_t)whidth)
            return 1;
		y++;
	}
	return (0);
	
}
