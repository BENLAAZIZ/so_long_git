/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:08:18 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/08 18:59:00 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//  static int	check_nbr_coin(t_data *data)
// {
// 	int i;
// 	int j;
// 	int	c;

// 	i = 0;
// 	c = 0;
// 	while (data->split[i] != NULL)
// 	{
// 		j = 0;
// 		while (data->split[i][j])
// 		{
// 			if (data->split[i][j] == 'C')
// 				c++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (c);
// }

void	move_p_up(t_data *data)
{
	printf("%d\n", data->p.coi);
	if (data->split[data->y_p - 1][data->x_p] != '1')
	{
		if (data->split[data->y_p - 1][data->x_p] == 'E' && data->p.coi <= 0)
		{
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, data->x_p * 50, --data->y_p * 50);
			exit(1);
		}
		else if (data->split[data->y_p - 1][data->x_p] == 'C')
		{
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, data->x_p * 50, --data->y_p * 50);
			data->split[data->y_p][data->x_p] = '0';
			--data->p.coi;
		}
		else if (data->split[data->y_p - 1][data->x_p] != 'E')
		{
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, data->x_p * 50, --data->y_p * 50);
		}
	}
}

void	move_p_down(t_data *data)
{
	printf("%d\n", data->p.coi);
	if (data->split[data->y_p + 1][data->x_p] != '1')
	{
		if (data->split[data->y_p + 1][data->x_p] == 'E' && data->p.coi <= 0)
		{
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, data->x_p * 50, ++data->y_p * 50);
			exit(1);
		}
		else if (data->split[data->y_p + 1][data->x_p ] == 'C')
		{
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, data->x_p * 50, ++data->y_p * 50);
			data->split[data->y_p][data->x_p] = '0';
			--data->p.coi;
		}
		else if (data->split[data->y_p + 1][data->x_p] != 'E')
		{
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, data->x_p * 50, ++data->y_p * 50);
		}
	}
}

void	move_p_right(t_data *data)
{
	printf("%d\n", data->p.coi);
	if (data->split[data->y_p][data->x_p + 1] != '1')
	{
		if (data->split[data->y_p][data->x_p + 1] == 'E' && data->p.coi <= 0)
		{
			puts("here1");
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, ++data->x_p * 50, data->y_p * 50);
			exit(1);
		}
		else if (data->split[data->y_p][data->x_p + 1] == 'C')
		{
			puts("here1");
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, ++data->x_p * 50, data->y_p * 50);
			data->split[data->y_p][data->x_p] = '0';
			--data->p.coi;
		}
		else if (data->split[data->y_p][data->x_p + 1] != 'E')
		{
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, ++data->x_p * 50, data->y_p * 50);
		}
	}
}

void	move_p_left(t_data *data)
{
	printf("%d\n", data->p.coi);
	if (data->split[data->y_p][data->x_p - 1] != '1')
	{
		if (data->split[data->y_p][data->x_p - 1] == 'E' && data->p.coi <= 0)
		{
			puts("here1");
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, --data->x_p * 50, data->y_p * 50);
			exit(1);
		}
		else if (data->split[data->y_p][data->x_p - 1] == 'C')
		{
			puts("here2");
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, --data->x_p * 50, data->y_p * 50);
			data->split[data->y_p][data->x_p] = '0';
			--data->p.coi;
		}
		else if (data->split[data->y_p][data->x_p - 1] != 'E' )
		{
			puts("here3");
			mlx_put_image_to_window(data->mlx_ptr , data->win_ptr, data->p.rout, data->x_p * 50, data->y_p * 50);
			mlx_put_image_to_window(data->mlx_ptr ,data->win_ptr, data->p.player, --data->x_p * 50, data->y_p * 50);
		}
	}
}





