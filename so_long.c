/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/20 22:05:16 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->width = (int)ft_strlen(data->split[0]);
	data->height = 0;
	while (data->split[data->height])
		data->height++;
	printf("h %d ; w %d", data->height, data->width);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->width * 50, data->height * 50, "./so-long");
	data->p.player = ft_mlx_xpm_file_to_image(data, "textures/man.xpm");
	data->p.rout = ft_mlx_xpm_file_to_image(data, "textures/space.xpm");
	data->p.wall = ft_mlx_xpm_file_to_image(data, "textures/wall.xpm");
	data->p.door = ft_mlx_xpm_file_to_image(data, "textures/exit.xpm");
	data->p.coin = ft_mlx_xpm_file_to_image(data, "textures/zlij.xpm");
	if (!data->p.player || !data->p.rout || !data->p.wall
		|| !data->p.door || !data->p.coin)
		destroy_all(data);
}

static void	print_image(t_data *data)
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

static void	cord_player(t_data *data)
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

static void	so_long(t_data *data)
{
	data->p.move = 0;
	print_image(data);
	mlx_hook(data->win_ptr, 2, 0, handel_key, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_loop(data->mlx_ptr);
}

void v()
{
	system("leaks so_long");
}
int	main(int arg_c, char **arg_v)
{
	t_data	data;

	atexit(v);
	if (arg_c != 2)
		return (ft_print_error("arg"), 1);
	if (handel_content(get_buffer(arg_v, &data), &data) == 1)
		return (ft_print_error("map"), 1);
	puts("ssssss");
	data.split = ft_split(get_buffer(arg_v, &data), '\n');
	if (!data.split)
		return (free(data.buffer), 1);
	ft_init(&data);
	if ((handel_border(data.split, data.width, data.height)) == 1)
		return (free_split_buffer(&data), destroy_all(&data), 1);
	cord_player(&data);
	data.p.coi_copy = data.p.coi;
	data.p.b = fload_fill(&data, data.y_p, data.x_p, &data.p.a);
	if (data.p.b == 1)
		return (free_split_buffer(&data), destroy_all(&data), ft_print_error("map"), 0);
	free_split_buffer(&data);
	data.split2 = ft_split(get_buffer(arg_v, &data), '\n');
	if (!data.split2)
		return (free(data.buffer), 1);
	so_long(&data);
	return (0);
}
