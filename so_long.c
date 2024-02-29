/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/02/29 13:41:33 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int width;
	int height;	
}  t_data;
// read map
char	*read_map(int fd)
{
	char	*s;
	char	*buffer;
	char	*tmp;

	s = "   ";
	buffer = NULL;
	while (s)
	{
		s = get_next_line(fd);
		tmp = buffer;
		buffer = ft_strjoin(buffer, s);
		free(tmp);
		free(s);
		if (s && s[0] != '1')
			return (free(buffer), ft_print_error("border"), NULL);
	}
	return (buffer);
}
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

void	ft_print_error(char *str)
{
	if (ft_strncmp(str, "content", ft_strlen(str)) == 0)
		write(1, "eroor\ncontent", 13);
	if (ft_strncmp(str, "border", ft_strlen(str)) == 0)
		write(1, "eroor\nborder", 12);
	if (ft_strncmp(str, "arg", ft_strlen(str)) == 0)
		write(1, "eroor\nnumber of arguments invalid", 33);
}

// void	put_image(char **temp, void *mlx_ptr, void *mlx_win, t_piece *p)
// {
// 	int		j;
// 	int		i;
	
// 	i = 0;
// 	while(temp[i])
// 	{
// 		j = 0;
// 		while(temp[i][j] != '\0')
// 		{
// 			puts("here");
// 			if(temp[i][j] == '1')
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, p->wall, j * 50, i * 50);
// 			if(temp[i][j] == '0')
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, p->route, j * 50, i * 50);
// 			if(temp[i][j] == 'P')
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, p->avatar, j * 50, i * 50);
// 			if(temp[i][j] == 'E')
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, p->road, j * 50, i * 50);
// 			if(temp[i][j] == 'C')
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, p->coin, j * 50, i * 50);
// 			j++;
// 		}
// 		i++;
// 	}
// }
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
		path_img = "road.xpm";
	else if(c == 'C')
		path_img = "coin.xpm";
	return (path_img);	
}
int main(int arg_c, char **arg_v)
{
	
	int		fd;
	char	*bufer;
	char 	**split;
	int		t;
	// t_piece p;

	if (arg_c != 2)
		return (ft_print_error("arg"), 1); 
	fd = open(arg_v[1], O_RDONLY);
	if(fd < 0)
		return (close(fd), 1);
	bufer =	read_map(fd);
	if (!bufer)
		return(free(bufer), 1);
	//ayman
	int i = 0;
	t_data data;
	while (bufer[i] != '\0')
	{
		if ((bufer[i] != '1' && bufer[i] != '0' && bufer[i] != 'P' && bufer[i] != 'E' && bufer[i] != 'C' && bufer[i] != '\n'))
			{
				return (free(bufer), ft_print_error("content"),1);
			}
		i++;
	}
	//ayamn final
	split = ft_split(bufer, '\n');
	char **temp  = split;
	if (!split)
		return (1);
	//whidth of first line
	data.mlx_ptr = mlx_init();
	data.width = ft_strlen(split[0]);
	data.height = count_word(bufer, '\n');
	//************************************
	t = handel_border(split, data.width, data.height);
	if (t == 1)
		return (ft_print_error("border"), 1);
	//************************************
	// p.route = mlx_xpm_file_to_image(mlx_ptr ,"textures/route.xpm", &w, &h);
	// p.wall = mlx_xpm_file_to_image(mlx_ptr ,"textures/wall_sijn1pxm.xpm", &w, &h);
	// p.coin = mlx_xpm_file_to_image(mlx_ptr ,"coin.xpm", &w, &h);
	// p.road = mlx_xpm_file_to_image(mlx_ptr ,"road.xpm", &w, &h);
	data.win_ptr =mlx_new_window(data.mlx_ptr, data.width * 50, data.height * 50, "./so-long");
	int w = 50;
	int h = 50;
	 i = 0;
	int j;
	while(i < data.height)
	{
		j = 0;
		while(j < data.width)
		{
			data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr , get_image_path(split[i][j]), &w, &h);
			mlx_put_image_to_window(data.mlx_ptr,data.win_ptr, data.img_ptr, j * 50, i * 50);
			j++;
		}
		i++;
	}
	mlx_loop(data.mlx_ptr);
	// free(bufer);
	// put_image(temp, mlx_ptr, mlx_win, &p);
	return (0);
}


