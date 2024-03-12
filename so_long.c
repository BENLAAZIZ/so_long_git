/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/12 14:47:56 by hben-laz         ###   ########.fr       */
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

int	handel_key(int key, t_data *data)
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

// int	fload_fill(t_data *data, int x, int y,int *exit)
// {
// 	if (data->split2[x][y] == '1')
// 			return 0;
// 	if (data->split2[x][y] == 'E' && data->p.coi_copy > 0)
// 			return 0;
// 	if (data->split2[x][y] == 'C')
// 			--data->p.coi_copy;
// 	if (data->split2[x][y] == 'E' && *exit == 1)
// 		--(*exit);
// 	data->split2[x][y] = '1';
// 	fload_fill(data, (x - 1), y, exit);
// 	fload_fill(data, (x + 1), y, exit);
// 	fload_fill(data, x, (y - 1), exit);
// 	fload_fill(data, x, (y + 1), exit);
// 	if (data->p.coi_copy <= 0 && *exit <= 0)
// 		return 1;
// 	return (0);
// }

int	fload_fill(t_data *data, int x, int y,int *exit)
{
	if (data->split2[x][y] == '1')
			return 0;
	if (data->split2[x][y] == 'E' && data->p.coi_copy == 0)
	{
		data->split2[x][y] = '1';
		--(*exit);
	}
	// if (data->split2[x][y] == 'E' && data->p.coi_copy > 0)
	// 		return 0;
	if (data->split2[x][y] == 'C')
			--data->p.coi_copy;
	data->split2[x][y] = '1';
	fload_fill(data, (x - 1), y, exit);
	fload_fill(data, (x + 1), y, exit);
	fload_fill(data, x, (y - 1), exit);
	fload_fill(data, x, (y + 1), exit);
	if (data->p.coi_copy <= 0 && *exit <= 0)
		return 1;
	return (0);
}
char	*get_buffer(char	**arg_v)
{
	int fd;
	char *buffer;
	if (arg_v[1] != NULL)
	{
		fd = open(arg_v[1], O_RDONLY);
		if (fd < 0)
			return (NULL);
		buffer = read_map(fd);
		if (!buffer)
			return (free(buffer), NULL);
		return (buffer);
	}
		else
		return (NULL);
	}
int	f_fload(t_data *data)
{
	int i;
	int j;
	
	j = 0;
	while (data->split2[j] != NULL)
	{
		i = 0;
		while (data->split2[j][i] != '\0')
		{
			if (data->split2[j][i] == '0')
				return (0);
			i++;
		}
		printf("\n%s", data->split2[j]);
		j++;
	}
	return (1);
}

int	main(int arg_c, char **arg_v)
{
	int		fd;
	char	*buffer;
	t_data	data;
	int a;
	int b;
	
	if (arg_c != 2)
		return (ft_print_error("arg"), 1);
	if (handel_content(get_buffer(arg_v), &data) == 1)
		return (ft_print_error("map"), 1);
	data.split = ft_split(get_buffer(arg_v), '\n');
	if (!data.split)
		return (1);
	ft_int(&data);
	if ((handel_border(data.split, data.width, data.height)) == 1)
		return (1);
	cord_player(&data);	
	data.split2 = ft_split(get_buffer(arg_v), '\n');
		data.p.coi_copy = data.p.coi;
		a = 1;
		b = fload_fill(&data, data.y_p, data.x_p, &a);
		if(b == 0)
			return (ft_print_error("map"), 0);
		puts("dcdddddd");
		if (f_fload(&data) == 0)
			return (ft_print_error("map"), 0);
	
	printf("\nb %d	", b);
	print_image(&data);
	// mlx_key_hook(data->win_ptr, handel_hey, data);
	mlx_hook(data.win_ptr, 2, 0, handel_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
