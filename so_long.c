/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/07 19:29:40 by hben-laz         ###   ########.fr       */
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
char *get_image_path(int c)
{
	char *path_img;
	path_img = NULL;
	if(c == 'P')
		path_img = "textures/player.xpm";
	else if(c == '0')
		path_img = "textures/route.xpm";
	else if(c == '1')
		path_img = "textures/wall_sijn1pxm.xpm";
	else if(c == 'E')
		path_img = "textures/door.xpm";
	else if(c == 'C')
		path_img = "textures/tassarott.xpm";
	return (path_img);	
}
void print_image(char **split, t_data *data)
{
	int	i;
	int	j;
	int	w;
	int	h;

	w = 50;
	h = 50;
	i = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * 50, data->height * 50, "./so-long");
	while(i < data->height)
	{
		j = 0;
		while(j < data->width)
		{
			data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr , get_image_path(split[i][j]), &w, &h);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, j * 50, i * 50);
			j++;
		}
		i++;
	}
}
int	handel_hey(int key, t_data *data)
{
	cord_player(data);
	printf("%d\n", data->x_p);
	printf("%d\n", data->y_p);
	
	if (key == 53)
		exit(1);
	if (key == 13)
	{
		move_p_up(data);
	}
	// if (key == 's')
	// {
	// 	move_p_down();
	// }	
	// if (key == 'a')
	// {
	// 	move_p_left();
	// }
	// if (key == 'd')
	// {
	// 	move_p_right();
	// }
	return (1);
}

void cord_player(t_data *data)
{
	char	**split_tmp;

	(data->x_p) = 0;
	split_tmp = data->split;
	if (!split_tmp)
		return ;	
	while (data->x_p < data->width)
	{
		data->y_p = 0;
		while ( data->y_p < data->height)
		{
			if (split_tmp[data->x_p][data->y_p] == 'P')
				break ;
			++(data->y_p);
		}
		if (split_tmp[data->x_p][data->y_p] == 'P')
				break ;
		++(data->x_p);
	}
}
int main(int arg_c, char **arg_v)
{
	int		fd;
	char	*buffer;
	char 	**split_tmp;
	t_data	*data = (t_data *)malloc(sizeof(t_data));
	
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
	data->split = ft_split(buffer, '\n');
	if (!data->split)
		return (free(buffer), 1);
	split_tmp = data->split;
	//  int i = 0;
	//  while (split_tmp[i])
	//  {
	//  	printf("%s\n", data->split[i]);
	//  	i++;
	//  }
	data->width = (int)ft_strlen(split_tmp[0]);
	data->height = count_word(buffer, '\n');
	if ((handel_border(split_tmp, (data->width), (data->height))) == 1)
		return (free(buffer), 1);
	print_image(split_tmp, data);
	mlx_key_hook(data->win_ptr, handel_hey, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
