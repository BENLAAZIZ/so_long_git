/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/08 22:19:18 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[i] != '\0' || ss2[i] != '\0') && (n > i))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	if (n == i)
		return (0);
	return (ss1[i] - ss2[i]);
}

void	ft_int(t_data *data)
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
	while (data->split[++(data->p.i)] != NULL)
	{
		data->p.j = -1;
		while (data->split[data->p.i][++data->p.j] != '\0')
		{
			if (data->split[data->p.i][data->p.j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.rout, data->p.j * 50, data->p.i * 50);
			if (data->split[data->p.i][data->p.j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.wall, data->p.j * 50, data->p.i * 50);
			if (data->split[data->p.i][data->p.j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.player, data->p.j * 50, data->p.i * 50);
			if (data->split[data->p.i][data->p.j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.coin, data->p.j * 50, data->p.i * 50);
			if (data->split[data->p.i][data->p.j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->p.door, data->p.j * 50, data->p.i * 50);
		}
	}
}

int	handel_hey(int key, t_data *data)
{
	if (key == 53)
		exit(1);
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

int	main(int arg_c, char **arg_v)
{
	int		fd;
	char	*buffer;
	t_data	*data = (t_data *)malloc(sizeof(t_data));

	if (arg_c != 2)
		return (ft_print_error("arg"), 1);
	fd = open(arg_v[1], O_RDONLY);
	if (fd < 0)
		return (1);
	buffer = read_map(fd);
	if (!buffer)
		return (free(buffer), 1);
	if (handel_content(buffer, data) == 1)
		return (free(buffer), ft_print_error("content"), 1);
	data->split = ft_split(buffer, '\n');
	if (!data->split)
		return (free(buffer), 1);
	ft_int(data);
	if ((handel_border(data->split, data->width, data->height)) == 1)
		return (free(buffer), 1);
	print_image(data);
	cord_player(data);
	// mlx_key_hook(data->win_ptr, handel_hey, data);
	mlx_hook(data->win_ptr, 2, 0, handel_hey, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
