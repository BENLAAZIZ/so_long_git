/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/15 15:22:44 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data)
{
	int	w;
	int	h;

	data->mlx_ptr = mlx_init();
	data->p.player = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/player.xpm", &h, &w);
	data->p.rout = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/route.xpm", &h, &w);
	data->p.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall_sijn1pxm.xpm", &h, &w);
	data->p.door = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/door.xpm", &h, &w);
	data->p.coin = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/tassarott.xpm", &h, &w);
	data->width = (int)ft_strlen(data->split[0]);
	data->height = 0;
	while (data->split)
	{
		if (!data->split[data->height])
			break ;
		data->height++;
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->width * 50, data->height * 50, "./so-long");
}

void	print_image(t_data *data)
{
	data->p.i = -1;
	while (data->split2[++(data->p.i)] != NULL)
	{
		data->p.j = -1;
		while (data->split2[data->p.i][++data->p.j] != '\0')
		{
			if (data->split2[data->p.i][data->p.j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.rout, data->p.j * 50, data->p.i * 50);
			if (data->split2[data->p.i][data->p.j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.wall, data->p.j * 50, data->p.i * 50);
			if (data->split2[data->p.i][data->p.j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.player, data->p.j * 50, data->p.i * 50);
			if (data->split2[data->p.i][data->p.j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.coin, data->p.j * 50, data->p.i * 50);
			if (data->split2[data->p.i][data->p.j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.door, data->p.j * 50, data->p.i * 50);
		}
	}
}

int	handel_key(int key, t_data *data)
{
	if (key == 53)
	{
		free_t_data(data->split2);
		exit(1);
	}
	if (key == 13)
	{
		move_p_up(data);
	}
	if (key == 1)
	{
		move_p_down(data);
	}
	if (key == 2)
	{
		move_p_right(data);
	}
	if (key == 0)
	{
		move_p_left(data);
	}
	return (1);
}

void	cord_player(t_data *data)
{
	char	**tmp;

	data->y_p = 0;
	tmp = data->split;
	if (!tmp)
		return ;
	while (data->y_p < data->height)
	{
		data->x_p = 0;
		while (data->x_p < data->width)
		{
			if (tmp[data->y_p][data->x_p] == 'P')
				break ;
			++(data->x_p);
		}
		if (tmp[data->y_p][data->x_p] == 'P')
			break ;
		++(data->y_p);
	}
}

void v(void)
{
	system("leaks so_long");
}
int ft_exit(t_data *data)
{
	free_t_data(data->split2);
	exit(1);
}
int	main(int arg_c, char **arg_v)
{
	int		fd;
	t_data	data;
	int		a;
	int		b;

	atexit(v);
	if (arg_c != 2)
		return (ft_print_error("arg"), 1);
	if (handel_content(get_buffer(arg_v, &data), &data) == 1)
		return (free(data.buffer), 1);
	data.split = ft_split(get_buffer(arg_v, &data), '\n');
	if (!data.split)
		return (free(data.buffer), 1);
	ft_init(&data);
	if ((handel_border(data.split, data.width, data.height)) == 1)
		return (free_t_data(data.split), free(data.buffer), 1);
	cord_player(&data);
	data.p.coi_copy = data.p.coi;
	a = 1;
	b = fload_fill(&data, data.y_p, data.x_p, &a);
	if(b == 0)
		return (free_t_data(data.split), free(data.buffer), ft_print_error("map"), 0);
	free_t_data(data.split);
	free(data.buffer);	
	data.split2 = ft_split(get_buffer(arg_v, &data), '\n');
	if (!data.split2)
		return (free(data.buffer), 1);
	print_image(&data);
	mlx_hook(data.win_ptr, 2, 0, handel_key, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_exit, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
