/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:08:18 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/07 23:23:06 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_p_up(t_data *data)
{
	int		x;
	int		y;
	x = data->x_p;
	y = data->y_p;
	printf("x = %d , y = %d \n", x,y);
	if (data->split[data->x_p - 1][data->y_p] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, y * 50, x * 50);
		mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, y * 50, --x * 50);
	}
	data->x_p = x;
	data->y_p = y;
	printf("x = %d , y = %d \n", x,y);
}

void	move_p_down(t_data *data)
{
	int		x;
	int		y;
	x = data->x_p;
	y = data->y_p;
	printf("x = %d , y = %d \n", x,y);
	if (data->split[data->x_p + 1][data->y_p] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, y * 50, x * 50);
		mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, y * 50, ++x * 50);
	}
	data->x_p = x;
	data->y_p = y;
	printf("x = %d , y = %d \n", x,y);
}
void	move_p_left(t_data *data)
{
	int		x;
	int		y;
	x = data->x_p;
	y = data->y_p;
	printf("x = %d , y = %d \n", x,y);
	if (data->split[data->x_p][data->y_p - 1] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, y * 50, x * 50);
		mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, --y * 50, x * 50);
	}
	data->x_p = x;
	data->y_p = y;
	printf("x = %d , y = %d \n", x,y);
}
void	move_p_right(t_data *data)
{
	int		x;
	int		y;
	x = data->x_p;
	y = data->y_p;
	printf("x = %d , y = %d \n", x,y);
	if (data->split[data->x_p][data->y_p + 1] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, y * 50, x * 50);
		mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, ++y * 50, x * 50);
	}
	data->x_p = x;
	data->y_p = y;
	printf("x = %d , y = %d \n", x,y);
}


