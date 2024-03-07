/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/07 22:45:41 by hben-laz         ###   ########.fr       */
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
// char *get_image_path(int c)
// {
// 	char *path_img;
// 	path_img = NULL;
// 	if(c == 'P')
// 		path_img = "textures/player.xpm";
// 	else if(c == '0')
// 		path_img = "textures/route.xpm";
// 	else if(c == '1')
// 		path_img = "textures/wall_sijn1pxm.xpm";
// 	else if(c == 'E')
// 		path_img = "textures/door.xpm";
// 	else if(c == 'C')
// 		path_img = "textures/tassarott.xpm";
// 	return (path_img);	
// }

void ft_int(t_data *data)
{
	int w;
	int h;
	data->mlx_ptr = mlx_init();
	printf(" add:%p\n", data->mlx_ptr);
	puts("hhhhh");
	data->p.player = mlx_xpm_file_to_image(data->mlx_ptr , "textures/player.xpm" , &h, &w);
	data->p.rout = mlx_xpm_file_to_image(data->mlx_ptr , "textures/route.xpm" , &h, &w);
	data->p.wall = mlx_xpm_file_to_image(data->mlx_ptr , "textures/wall_sijn1pxm.xpm" , &h, &w);
	data->p.door = mlx_xpm_file_to_image(data->mlx_ptr , "textures/door.xpm" , &h, &w);
	data->p.coin = mlx_xpm_file_to_image(data->mlx_ptr , "textures/tassarott.xpm" , &h, &w);
	data->width = (int)ft_strlen(data->split[0]);
	data->height = 0;
	while (data->split)
	{
		if (!data->split[data->height])
			break;
		data->height++;
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * 50, data->height * 50, "./so-long");
}

void print_image(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	printf("%s", data->split[0]);
	while(data->split[i] != NULL)
	{
		j = 0;
		while(data->split[i][j] != '\0')
		{
			if (data->split[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p.rout, j * 50, i * 50);
			if (data->split[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p.wall, j * 50, i * 50);
			if (data->split[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p.player, j * 50, i * 50);
			if (data->split[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p.coin, j * 50, i * 50);
			if (data->split[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p.door, j * 50, i * 50);
			j++;
			
		}
		i++;
	}
}
int	handel_hey(int key, t_data *data)
{
	// printf("%d\n", data->x_p);
	// printf("%d\n", data->y_p);
	printf("%d\n", key);
	
	if (key == 53)
		exit(1);
	if (key == 13)
	{
		move_p_up(data);
	}
	return (1);
}

void cord_player(t_data *data)
{
	char	**tmp;

	(data->x_p) = 0;
	tmp = data->split;
	if (!tmp)
		return ;	
	while (data->x_p < data->width)
	{
		data->y_p = 0;
		while ( data->y_p < data->height)
		{
			if (tmp[data->x_p][data->y_p] == 'P')
				break ;
			++(data->y_p);
		}
		if (tmp[data->x_p][data->y_p] == 'P')
				break ;
		++(data->x_p);
	}
	
}
int main(int arg_c, char **arg_v)
{
	int		fd;
	char	*buffer;
	t_data	*data = (t_data *)malloc(sizeof(t_data));
	t_piece p;
	
	if (arg_c != 2)
		return (ft_print_error("arg"), 1); 
	fd = open(arg_v[1], O_RDONLY);
	if(fd < 0)
		return (1);
	buffer = read_map(fd);
	if (!buffer)
		return(free(buffer), 1);
	if (handel_content(buffer) == 1)
		return (free(buffer), ft_print_error("content"),1);
	char **temp =NULL;
	data->split = ft_split(buffer, '\n');
	temp = data->split;
	printf("%s", data->split[0]);
	if (!data->split)
		return (free(buffer), 1);
	// data->width = (int)ft_strlen(data->split[0]);
	// data->height = count_word(buffer, '\n');
	ft_int(data);
	if ((handel_border(data->split, data->width, data->height)) == 1)
		return (free(buffer), 1);
	data->split = temp;
	print_image(data);
	cord_player(data);
	mlx_key_hook(data->win_ptr, handel_hey, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
