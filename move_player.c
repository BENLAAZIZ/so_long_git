/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:08:18 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/12 17:20:06 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_action(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->p.rout, data->x_p * 50, data->y_p * 50);
	data->x_p = x;
	data->y_p = y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->p.player, data->x_p * 50, data->y_p * 50);
}

void	move_p_up(t_data *data)
{
	int	x;
	int	y;

	x = data->x_p;
	y = data->y_p;
	if (data->split[data->y_p - 1][data->x_p] != '1')
	{
		if (data->split[data->y_p - 1][data->x_p] == 'E' && data->p.coi <= 0)
		{
			move_action(data, x, --y);
			exit(1);
		}
		else if (data->split[data->y_p - 1][data->x_p] == 'C')
		{
			move_action(data, x, --y);
			data->split[data->y_p][data->x_p] = '0';
			--data->p.coi;
		}
		else if (data->split[data->y_p - 1][data->x_p] != 'E')
			move_action(data, x, --y);
	}
}

void	move_p_down(t_data *data)
{
	int	x;
	int	y;

	x = data->x_p;
	y = data->y_p;
	if (data->split[data->y_p + 1][data->x_p] != '1')
	{
		if (data->split[data->y_p + 1][data->x_p] == 'E' && data->p.coi <= 0)
		{
			move_action(data, x, ++y);
			exit(1);
		}
		else if (data->split[data->y_p + 1][data->x_p] == 'C')
		{
			move_action(data, x, ++y);
			data->split[data->y_p][data->x_p] = '0';
			--data->p.coi;
		}
		else if (data->split[data->y_p + 1][data->x_p] != 'E')
			move_action(data, x, ++y);
	}
}

void	move_p_right(t_data *data)
{
	int	x;
	int	y;

	x = data->x_p;
	y = data->y_p;
	if (data->split[data->y_p][data->x_p + 1] != '1')
	{
		if (data->split[data->y_p][data->x_p + 1] == 'E' && data->p.coi <= 0)
		{
			move_action(data, ++x, y);
			exit(1);
		}
		else if (data->split[data->y_p][data->x_p + 1] == 'C')
		{
			move_action(data, ++x, y);
			data->split[data->y_p][data->x_p] = '0';
			--data->p.coi;
		}
		else if (data->split[data->y_p][data->x_p + 1] != 'E')
			move_action(data, ++x, y);
	}
}

void	move_p_left(t_data *data)
{
	int	x;
	int	y;

	x = data->x_p;
	y = data->y_p;
	if (data->split[data->y_p][data->x_p - 1] != '1')
	{
		if (data->split[data->y_p][data->x_p - 1] == 'E' && data->p.coi <= 0)
		{
			move_action(data, --x, y);
			exit(1);
		}
		else if (data->split[data->y_p][data->x_p - 1] == 'C')
		{
			move_action(data, --x, y);
			data->split[data->y_p][data->x_p] = '0';
			--data->p.coi;
		}
		else if (data->split[data->y_p][data->x_p - 1] != 'E' )
			move_action(data, --x, y);
	}
}
